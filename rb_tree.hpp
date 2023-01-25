#pragma once

#include <iostream>
#include <memory>
#include <functional>
#include "Utils.hpp"
#include "Pair.hpp"
#include "Iterator.hpp"


namespace ft {

    enum Color {red, black};

    template<class Key, class T>
    class Node {
      public:
        ft::pair<const Key, T>       *value;
        Color                        color;
        Node                         *left, *right, *parent;

        Node(): value(NULL), color(red), left(NULL), right(NULL), parent(NULL){};

        Node(T val) {
            std::allocator<ft::pair<const Key, T> > alloc;

            this->value = alloc.allocate(1);
            alloc.construct(this->value, val);
            this->left = this->right = this->parent = NULL;
            this->color = red;
        }

        Node(const Node& copy): value(copy.value), color(copy.color), left(copy.left), right(copy.right), parent(copy.parent) {};

        ~Node() {
            std::allocator<ft::pair<const Key, T> > alloc;

            if (this->value) {
                alloc.destroy(this->value);
                alloc.deallocate(this->value, 1);
                this->value = NULL;
            }
        }
    };

    template<class Key, class T, class Compare = std::less<Key> >
    class RBTree {
        public:

            typedef typename ft::pair<const Key, T>                                        value_type;
            typedef typename ft::Node<const Key, T>*                                       nodePtr;
            typedef Compare																   key_compare;
            typedef std::allocator<Node<const Key, T> >                                    Alloc;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>               iterator;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, const T>         const_iterator;
            typedef typename ft::reverse_iterator<iterator>                                reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator>                          const_reverse_iterator;

        private:
            nodePtr     root;
            Alloc       alloc;
            Compare     comp;

        public:

            RBTree(const key_compare& comp = key_compare(), const Alloc& alloc = Alloc()): root(NULL), alloc(alloc), comp(comp) {};

            ~RBTree() {};

            nodePtr NewNode(value_type& val) {
                nodePtr node;
                Alloc   alloc;

                node = alloc.allocate(1);
                alloc.construct(node, val);
                return node;
            }

            void    deallocateNode(nodePtr del) {
                alloc.destroy(del);
                alloc.deallocate(del, 1);
                del = NULL;
            }

            nodePtr    insert(value_type& val) {
                if (!this->root) {
                    this->root = this->NewNode(val);
                    this->root->color = black;
                    return (root);
                }
                if (val > this->root->value) {
                    this->root->right = this->NewNode(val);
                    this->root->right = insert(this->root->right);
                    this->root->right->parent = root;
                }
                else if (val < this->root->value) {
                    this->root->left = this->NewNode(val);
                    this->root->left = insert(this->root->left);
                    this->root->left->parent = root;
                }
                this->insert_balance(val);
                return this->root;
            }

            void    insert_balance(nodePtr& val) {
                nodePtr uncle;
                while (val->parent->color == red) {
                    if (val->parent == val->parent->parent->right) {
                        uncle = val->parent->parent->left;
                        if (uncle->color == red) {
                            uncle->color = black;
                            val->parent->color = black;
                            val->parent->parent->color = red;
                            val = val->parent->parent;
                        }
                        else {
                            if (val == val->parent->left) {
                                val = val->parent;
                                this->right_rotation(val);
                            }
                            val->parent->color = black;
                            val->parent->parent->color = red;
                            this->left_rotation(val->parent->parent);
                        }
                    }
                    else {
                        uncle = val->parent->parent->right;
                        if (uncle->color == red){
                            uncle->color = black;
                            val->parent->color = black;
                            val->parent->parent->color = red;
                            val = val->parent->parent;
                        }
                        else {
                            if (val == val->parent->right) {
                                val = val->parent;
                                this->left_rotation(val);
                            }
                            val->parent->color = black;
                            val->parent->parent->color = red;
                            this->right_rotation(val->parent->parent);
                        }
                    }
                    this->root->color = black;
                }
            }

            void    left_rotation(nodePtr& val) {
                nodePtr tmp = val->parent;
                val->parent = val;
                val->left = tmp;
                val = NULL;
            }

            void    right_rotation(nodePtr& val) {
                nodePtr tmp = val->parent;
                val->parent = val;
                val->right = tmp;
                val = NULL;
            }

            void    deleteNode(const Key &key) {
                nodePtr val = this->search(key);

                if (!this->root || !val)
                    return ;
                if (val == root) {
                    if (this->root->left == NULL && this->root->right == NULL){
                        this->deallocateNode(this->root);
                        return ;
                    }
                    else if (this->root->left == NULL || this->root->right == NULL) {
                        nodePtr oldroot = this->root;
                        this->root = (root->left == NULL) ? root->right : root->left;
                        deallocateNode(oldroot);
                    }
                    else {
                       nodePtr successor = this->getSuccessor(this->root);
                        this->root->value->first = successor->value->first;
                        deleteNode(this->root->value->first);
                    }
                }
                else if (val->color == red) {
                    if (val->right == NULL && val->left == NULL)
                        this->deallocate(val);
                    else if (val->right == NULL) {
                        nodePtr tmp = val->left;
                        this->deallocateNode(val->left);
                        val = tmp;
                    }
                    else if (val->left == NULL) {
                        nodePtr tmp2 = val->right;
                        this->deallocateNode(val->right);
                        val = tmp2;
                    }
                }
                else
                    this->balance_deleteNode(val);
            }

            void    balance_deleteNode(nodePtr& val) {
                nodePtr sibling;
                while (val != this->root && val->color == black) {
                    if (val == val->parent->left) {
                        sibling = val->parent->right;
                        if (sibling->color == red) {
                            sibling->color = black;
                            val->parent->color = red;
                            this->left_rotation(val->parent);
                            sibling = val->parent->right;
                        }
                        if (sibling->left->color == black && sibling->right->color == black) {
                            sibling->color = red;
                            val = val->parent;
                        }
                        else {
                            if (sibling->right->color == black) {
                                sibling->left->color = black;
                                sibling->color = red;
                                this->right_rotation(sibling);
                                sibling = val->parent->right;
                            }
                            sibling->color = val->parent->color;
                            val->parent->color = black;
                            sibling->right->color = black;
                            left_rotation(val->parent);
                            val = root;
                        }
                    }
                    else {
                        sibling = val->parent->left;
                        if (sibling->color == red) {
                            sibling->color = black;
                            val->parent->color = red;
                            this->right_rotation(val->parent);
                            sibling = val->parent->left;
                        }
                        if (sibling->left->color == black && sibling->right->color == black) {
                            sibling->color = red;
                            val = val->parent;
                        }
                        else {
                            if (sibling->left->color == black) {
                                sibling->right->color = black;
                                sibling->color = red;
                                this->left_rotation(sibling);
                                sibling = val->parent->left;
                            }
                            sibling->color = val->parent->color;
                            val->parent->color = black;
                            sibling->left->color = black;
                            this->right_rotation(val->parent);
                            val = root;    
                        }
                    }
                }
                val->color = black;
            }

            void clear() {
                nodePtr max = findMax(this->root);

                while (max != this->root) {
                    deleteNode(max->value->first);
                    max--;
                }
                if (max == this->root && this->root) {
                    deleteNode(this->root->value->first);
                    this->root = NULL;
                    deleteNode(max->value->first);
                }
            }

            nodePtr findMin(nodePtr cur) {
                while (cur->left)
                    cur = cur->left;
                return cur;
            }

            nodePtr findMax(nodePtr cur) {
                while (cur->right)
                    cur = cur->right;
                return cur;
            }

            nodePtr search(const Key& val) {
                nodePtr tmp = this->root;
                if (!tmp)
                    return NULL;
                while (tmp) {
                    if (!this->comp(tmp->value->first, val) && tmp->left) // val is smaller
                        tmp = tmp->left;
                    else if (this->comp(tmp->value->first, val) && tmp->right) // val bigger
                        tmp = tmp->right;
                    else if (!this->comp(tmp->value->first, val) && !this->comp(val, tmp->value->first)) // equal
                        break ;
                    else // nil node
                        tmp = NULL;
                }
                return tmp;
            }

            iterator search_it(const Key& val) {
                nodePtr tmp = this->root;
                if (!tmp)
                    return NULL;
                while (tmp) {
                    if (!this->comp(tmp->data->first, val) && tmp->left) // val is smaller
                        tmp = tmp->left;
                    else if (this->comp(tmp->data->first, val) && tmp->right) // val bigger
                        tmp = tmp->right;
                    else if (!this->comp(tmp->data->first, val) && !this->comp(val, tmp->data->first)) // equal
                        break ;
                    else // nil node
                        tmp = NULL;
                }
                return tmp;
            }

            value_type& search(iterator position) {
                iterator it = this->begin();
                nodePtr tmp = this->root;

                while (it != this->end()) {
                    if (it == position)
                        return *tmp->value;
                    it++;
                    tmp++;
                }
                return *tmp->value;
            }

            nodePtr getSuccessor(nodePtr root) { // get the inorder successor
                nodePtr curr = root->right;
                while (curr->left)
                    curr = curr->left;
                return curr;
            }

            nodePtr getRoot(void) {
                return this->root;
            }

            // iterator

            iterator begin() {
                return findMin(this->root);
            }

            iterator end() {
                nodePtr last = findMax(this->root);
                return last->right;
            }

            const_iterator begin() const {
                return findMin(this->root);
            }

            const_iterator end() const {
                nodePtr last = findMax(this->root);
                return last->right;
            }

            reverse_iterator rbegin() {
                return reverse_iterator(this->end());
            }

            const_reverse_iterator rbegin() const {
                return reverse_iterator(this->end());
            }

            reverse_iterator rend() {
                return reverse_iterator(this->begin());
            }
            
            const_reverse_iterator rend() const {
                return reverse_iterator(this->begin());
            }

    };

}