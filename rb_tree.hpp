#pragma once

#include <iostream>
#include <memory>
#include <functional>
#include <stdexcept>
#include "Utils.hpp"
#include "Pair.hpp"
#include "node.hpp"
#include "rbt_iterator.hpp"

namespace ft {

    template<class Key, class T, class Compare = std::less<Key> >
    class RBTree {
        public:

            typedef typename ft::pair<const Key, T>                                        value_type;
            typedef Key                                                                    key_type;
            typedef typename ft::Node<const Key, T>*                                       nodePtr;
            typedef Compare																   key_compare;
            typedef std::allocator<ft::pair<const Key, T> >                                Alloc;
            typedef std::allocator<ft::Node<Key, T> >                                      node_alloc;
            typedef typename ft::RbtIterator<ft::pair<const Key, T>, ft::Node<const Key, T>	>          iterator;
            typedef typename ft::RbtIterator<const ft::pair<const Key, T>, ft::Node<const Key, T> >     const_iterator;

    private:
            nodePtr     root;
            Alloc       alloc;
            node_alloc p_alloc;
            key_compare comp;
            size_t      size;
            nodePtr    _end;
    public:

            RBTree(const key_compare& comp = key_compare(), const Alloc& alloc = Alloc(), const node_alloc& n_alloc = node_alloc()): root(NULL), alloc(alloc), p_alloc(n_alloc), comp(comp), size(0), _end(NULL) {
                _end = this->NewNode(ft::make_pair(size, T()), NULL);
                _end->color = black;
                root = _end;
            }

            ~RBTree() {
                clear(root);
                deallocateNode(_end);
            }

            nodePtr NewNode(const value_type &val, nodePtr parent) {
                nodePtr node;

                node = p_alloc.allocate(1);
                alloc.construct(&node->value, val);
                node->parent = parent;
                node->color = red;
                node->right = node->left = _end;
                return node;
            }

            void update_end(void) {
                alloc.destroy(&_end->value);
                alloc.construct(&_end->value, ft::make_pair(size, T()));
                if (root != _end)
                    _end->parent = root;
            }

            void    deallocateNode(nodePtr del) {
                if (del == root)
                    root = _end;
                else {
                    if (del->parent != _end && del == del->parent->left)
                        del->parent->left = _end;
                    else if (del->parent != _end && del == del->parent->right)
                        del->parent->right = _end;
                }
                alloc.destroy(&del->value);
                p_alloc.deallocate(del, 1);
            }

        nodePtr search_(const Key &val) const {
            nodePtr tmp = this->root;

            while (tmp != _end) {
                if (this->comp(tmp->value.first, val) && tmp->right) { // val bigger
                    tmp = tmp->right;
                } else if (this->comp(val, tmp->value.first) && tmp->left) { // val smaller
                    tmp = tmp->left;
                }
                else if (this->comp(val, tmp->value.first) == false && this->comp(tmp->value.first, val) == false) //equal
                    break;
                else
                    tmp = _end;
            }
            return tmp;
        }

            nodePtr    insert(const value_type& val) {
                nodePtr node = root;
                nodePtr parent = NULL;

                while (node != _end) {
                    parent = node;
                    if (this->comp(val.first, node->value.first))
                        node = node->left;
                    else if (this->comp(node->value.first, val.first))
                        node = node->right;
                    else
                        return _end;
                }
                nodePtr to_insert = NewNode(val, NULL);
                if (parent == NULL) // root father -> NULL
                    root = to_insert;
                else if (this->comp(val.first, parent->value.first))
                    parent->left = to_insert;
                else
                    parent->right = to_insert;
                to_insert->parent = parent;
                this->size++;
                update_end();
                insert_balance(to_insert);
                return to_insert;
            }

            void insert_balance(nodePtr val) {
                nodePtr parent = val->parent;

                if (parent == NULL) // root father -> NULL
                    return ;
                if (parent->color == black)
                    return ;
                nodePtr grandparent = parent->parent;
                if (grandparent == NULL) {
                    parent->color = black;
                    return;
                }
                nodePtr uncle = getUncle(parent);
                if (uncle != _end && uncle->color) {
                    parent->color = black;
                    grandparent->color = red;
                    uncle->color = black;
                    insert_balance(grandparent);
                }
                else if (parent == grandparent->left) {
                    if (val == parent->right) {
                        left_rotation(parent);
                        parent = val;
                    }
                    right_rotation(grandparent);
                    parent->color = black;
                    grandparent->color = red;
                }
                else {
                    if (val == parent->left) {
                        right_rotation(parent);
                        parent = val;
                    }
                    left_rotation(grandparent);
                    parent->color = black;
                    grandparent->color = red;
                }
            }

            void deleteNode(const key_type k) {
                nodePtr node = search_(k);
                if (node == _end)
                    return ;
                nodePtr moveUp;
                Color delNodeColor;
                if (node->left == _end || node->right == _end) {
                    delNodeColor = node->color;
                    moveUp = delZeroOne(node);
                }
                else {
                    nodePtr inorderSuccessor = findMin(node->right);
                    alloc.destroy(&node->value);
                    alloc.construct(&node->value, inorderSuccessor->value);
                    delNodeColor = inorderSuccessor->color;
                    moveUp = delZeroOne(inorderSuccessor);
                }
                if (delNodeColor == black) {
                    fixRedBlackDelete(moveUp);
                    if (moveUp != _end && moveUp->nil) {
                        replaceParentChild(moveUp->parent, moveUp, _end);
                    }
                }
                size--;
                update_end();
            }

            nodePtr delZeroOne(nodePtr node) {
                nodePtr tmp;
                if (node->left != _end) { // Node has ONLY a left child --> replace by its left child
                    tmp = node->left;
                    replaceParentChild(node->parent, node, node->left);
                    return tmp;
                }
                else if (node->right != _end) {   // Node has ONLY a right child --> replace by its right child
                    tmp = node->right;
                    replaceParentChild(node->parent, node, node->right);
                    return tmp;
                }
                // Node has no children -->
                // * node is red --> just remove it
                // * node is black --> replace it by a temporary NIL node (needed to fix the R-B rules)
                else {
                    nodePtr new_child;
                    if (node->color == black) {
                        new_child = this->NewNode(value_type(), node->parent);
                        new_child->color = black;
                        new_child->nil = true;
                    }
                    else
                        new_child = _end;
                    replaceParentChild(node->parent, node, new_child);
                    return new_child;
                }
            }

            void replaceParentChild(nodePtr parent, nodePtr oldChild, nodePtr newChild) {
                if (parent == NULL) {
                    root = newChild;
                } else if (parent->left == oldChild) {
                    parent->left = newChild;
                    if (oldChild != _end)
                        deallocateNode(oldChild);
                } else if (parent->right == oldChild) {
                    parent->right = newChild;
                    if (oldChild != _end)
                        deallocateNode(oldChild);
                } else {
                    throw std::length_error("Node is not a child of its parent");
                }
                if (newChild != _end) {
                    newChild->parent = parent;
                }
            }

            void fixRedBlackDelete(nodePtr node) {
                // Case 1: Examined node is root, end of recursion
                if (node == root) {
                    return ;
                }
                nodePtr sibling = get_sibling(node);
                // Case 2: Red sibling
                if (sibling->color == red) {
                    handleRedSibling(node, sibling);
                    sibling = get_sibling(node); // Get new sibling for fall-through to cases 3-6
                }
                if (sibling->right == NULL && sibling->left == NULL)
                    return ;
                // Cases 3+4: Black sibling with two black children
                if (sibling->right && sibling->left && isBlack(sibling->left) && isBlack(sibling->right)) {
                    sibling->color = red;
                    // Case 3: Black sibling with two black children + red parent
                    if (node->parent->color == red) {
                        node->parent->color = black;
                    }
                        // Case 4: Black sibling with two black children + black parent
                    else {
                        fixRedBlackDelete(node->parent);
                    }
                }
                    // Case 5+6: Black sibling with at least one red child
                else {
                    handleBlackSiblingWithAtLeastOneRedChild(node, sibling);
                }
            }

            void handleRedSibling(nodePtr node, nodePtr sibling) {
                // Recolor...
                sibling->color = black;
                node->parent->color = red;

                // ... and rotate
                if (node == node->parent->left) {
                    left_rotation(node->parent);
                } else {
                    right_rotation(node->parent);
                }
            }

            bool isBlack(nodePtr node) {
                return node == _end || node->color == black;
            }

            void handleBlackSiblingWithAtLeastOneRedChild(nodePtr node, nodePtr sibling) {
                bool nodeIsLeftChild = node == node->parent->left;

                // Case 5: Black sibling with at least one red child + "outer nephew" is black
                // --> Recolor sibling and its child, and rotate around sibling
                if (nodeIsLeftChild && isBlack(sibling->right)) {
                    sibling->left->color = black;
                    sibling->color = red;
                    right_rotation(sibling);
                    sibling = node->parent->right;
                } else if (!nodeIsLeftChild && isBlack(sibling->left)) {
                    sibling->right->color = black;
                    sibling->color = red;
                    left_rotation(sibling);
                    sibling = node->parent->left;
                }

                // Fall-through to case 6...

                // Case 6: Black sibling with at least one red child + "outer nephew" is red
                // --> Recolor sibling + parent + sibling's child, and rotate around parent
                sibling->color = node->parent->color;
                node->parent->color = black;
                if (nodeIsLeftChild) {
                    sibling->right->color = black;
                    left_rotation(node->parent);
                } else {
                    sibling->left->color = black;
                    right_rotation(node->parent);
                }
            }

            nodePtr getUncle(nodePtr node) const {
                nodePtr grandparent = node->parent;
                if (grandparent->left == node)
                    return grandparent->right;
                else if (grandparent->right == node)
                    return grandparent->left;
                else
                    return _end;
            }

            size_t getSize() const {
                return size;
            }

            nodePtr getEnd() const
            {
                return _end;
            }

            void left_rotation(nodePtr p_val) {
                nodePtr tmp = p_val;
                nodePtr tmp2 = tmp->right->left;

                p_val = tmp->right;
                p_val->left = tmp;
                tmp->right = tmp2;
                p_val->parent = tmp->parent;
                if (tmp2) {
                    tmp2->parent = tmp;
                }
                if (p_val->parent) {
                    if (tmp == tmp->parent->right) {
                        p_val->parent->right = p_val;
                    } else {
                        p_val->parent->left = p_val;
                    }
                } else {
                    this->root = p_val;
                }
                tmp->parent = p_val;
            }

            void right_rotation(nodePtr val) {
                nodePtr tmp = val;
                nodePtr tmp2 = val->left->right;
                val = val->left;
                val->right = tmp;
                tmp->left = tmp2;
                val->parent = tmp->parent;
                if (tmp2)
                    tmp2->parent = tmp;
                if (val->parent) {
                    if (tmp == tmp->parent->right)
                        val->parent->right = val;
                    else
                        val->parent->left = val;
                } else
                    this->root = val;
                tmp->parent = val;
            }

            void clear(nodePtr node) {
                if (node != _end) {
                    clear(node->left);
                    clear(node->right);
                    alloc.destroy(&node->value);
                    p_alloc.deallocate(node, 1);
                    if (node == root)
                        root = _end;
                    node = _end;
                }
                this->size = 0;
                update_end();
            }

            nodePtr 	get_sibling(nodePtr node) const
            {
                nodePtr parent = node->parent;
                if (node == parent->left) {
                    return parent->right;
                } else if (node == parent->right) {
                    return parent->left;
                } else {
                    throw std::overflow_error("Parent is not a child of its grandparent");
                }
            }

            nodePtr getRoot() const {
                return this->root;
            }

            nodePtr findMin(nodePtr cur) const{
                while (cur != _end && cur->left != _end)
                    cur = cur->left;
                return cur;
            }

            nodePtr findMax(nodePtr cur) const {
                while (cur != _end && cur->right != _end)
                    cur = cur->right;
                return cur;
            }

            nodePtr end() {
                return (this->_end);
            }

            nodePtr end() const {
                return (this->_end);
            }

            void swap(RBTree &x) {
                nodePtr root_ = x.root;
                nodePtr end = x._end;
                size_t s = x.size;

                x.root = root;
                x._end = _end;
                x.size = size;

                root = root_;
                _end = end;
                size = s;
            }

            void _inorder(nodePtr p_root)
            {
                if (p_root == _end)
                    return;
                _inorder(p_root->left);
                std::cout << "inorder == " << p_root->value.first << " " << p_root->value.second << std::endl;
                _inorder(p_root->right);
            }
    };
}