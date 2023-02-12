#pragma once

#include <iostream>
#include <memory>
#include <functional>
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
//            typedef typename ft::RbtIterator<ft::pair<const Key, T>, ft::Node<const Key, T>	>          iterator;
//            typedef typename ft::RbtIterator<const ft::pair<const Key, T> >                         const_iterator;

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
                std::cout << "hello" <<std::endl;
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
                node->d_black = false;
                return node;
            }

            void update_end(void) {
                alloc.destroy(&_end->value);
                alloc.construct(&_end->value, ft::make_pair(size, T()));
            }

        void _inorder(nodePtr p_root)
        {
            if (!p_root)
                return;
            _inorder(p_root->left);
            std::cout << "inorder == " << p_root->value.first << " " << p_root->value.second << std::endl;
            _inorder(p_root->right);
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
                if (this->comp(tmp->value.first, val)) { // val bigger
                    if (tmp->right == _end)
                        return tmp;
                    tmp = tmp->right;
                } else if (this->comp(val, tmp->value.first)) { // val smaller
                    if (tmp->left == _end)
                        return tmp;
                    tmp = tmp->left;
                }
                else
                    return tmp;
            }
            return tmp;
        }

            nodePtr    insert(const value_type& val) {
                nodePtr to_find = this->search_(val.first);

                if (to_find != _end && to_find->value.first == val.first) {
                    to_find->d_black = true;
                    return to_find;
                }
                this->size++;
//                update_end();
                if (this->root == _end) {
                    this->root = this->NewNode(val, NULL);
                    this->root->color = black;
                    return (root);
                }
                if (this->comp(to_find->value.first, val.first)) {
                    to_find->right = this->NewNode(val, to_find);
                    to_find = this->insert_balance(to_find->right);
                }
                else if (this->comp(val.first, to_find->value.first)) {
                    to_find->left = this->NewNode(val, to_find);
                    to_find = this->insert_balance(to_find->left);
                }
                return to_find;
            }

            nodePtr  insert_balance(nodePtr val) {
                if (val == this->root || val->parent->color == black) {
                    return val;
                }
                nodePtr uncle = getUncle(val);
                if (uncle != _end && uncle->color == red) {
                    switch_color(uncle);
                    switch_color(val->parent);
                    if (val->parent->parent != this->root)
                        switch_color(val->parent->parent);
                    insert_balance(val->parent->parent);
                }
                else {
                    nodePtr parent = val->parent;
                    nodePtr grandparent = parent->parent;
                    if (!rotate_check(val, parent, grandparent)) {
                        if (parent->left == val)
                            right_rotation(val->parent);
                        else
                            left_rotation(val->parent);
                    }
                    if (grandparent->left == parent || grandparent->left == val) {
                        switch_color(grandparent);
                        switch_color(grandparent->left);
                        right_rotation(grandparent);
                    } else {
                        switch_color(grandparent);
                        switch_color(grandparent->right);
                        left_rotation(grandparent);
                    }
                }
                return val;
            }

            bool    deleteNode(Key key) {
                nodePtr del = this->search_(key);

                if (del->value.first != key)
                    return false;
                this->size--;
                update_end();
                if (del->left == _end && del->right == _end) {
                    if (del->color == red && this->root == del) {
                        this->deallocateNode(del);
                    } else {
                        nodePtr db = this->NewNode(value_type(), del->parent);
                        db->color = black;
                        db->d_black = true;
                        bool	l_or_r = del == del->parent->left;
                        this->deallocateNode(del);
                        l_or_r ? db->parent->left = db : db->parent->right = db;
                        balance_deleteNode(db);
                    }
                }
                else {
                    nodePtr tmp = del->left != _end ? findMax(del->left) : findMin(del->right);
                    if (tmp->left != _end || tmp->right != _end) {
                        if (tmp->left != _end) {
                            switch_color(tmp->left);
                            tmp->left->parent = tmp->parent;
                            tmp == tmp->parent->left ? tmp->parent->left = tmp->left : tmp->parent->right = tmp->left;
                        }
                        else {
                            switch_color(tmp->right);
                            tmp->right->parent = tmp->parent;
                            tmp == tmp->parent->left ? tmp->parent->left = tmp->right : tmp->parent->right = tmp->right;
                        }
                        copy_node(del, tmp);
                    }
                    else {
                        if (tmp->color == red) {
                            tmp == tmp->parent->left ? tmp->parent->left = _end : tmp->parent->right = _end;
                            copy_node(del, tmp);
                        }
                        else {
                            nodePtr db = this->NewNode(value_type(), tmp->parent);
                            db->color = black;
                            db->d_black = true;
                            tmp == tmp->parent->left ? tmp->parent->left = db : tmp->parent->right = db;
                            copy_node(del, tmp);
                            balance_deleteNode(db);
                        }
                    }
                }
                return true;
            }

        void	copy_node(nodePtr a, nodePtr b)
        {
            if (a != root)
                a == a->parent->left ? a->parent->left = b : a->parent->right = b;
            else
                root = b;
            b->parent = a->parent;
            b->left = a->left;
            b->right = a->right;
            if (b->left != _end)
                b->left->parent = b;
            if (b->right != _end)
                b->right->parent = b;
            b->color = a->color;
            alloc.destroy(&a->value);
            p_alloc.deallocate(a, 1);
            a = _end;
        }

            void    balance_deleteNode(nodePtr val) {
                if (val == root) {
                    val->color = black;
                    return ;
                }
                nodePtr sibling = get_sibling(val);
                if (sibling->color == red) {
                    sibling->color = val->parent->color;
                    val->parent->color = red;
                    val == val->parent->left ? left_rotation(val->parent) : right_rotation(val->parent);
                    balance_deleteNode(val);
                }
                else {
                    nodePtr far_child = get_far_child(val);
                    if (far_child != _end && far_child->color == red) {
                        sibling->color = val->parent->color;
                        val->parent->color = black;
                        val == val->parent->left ? left_rotation(val->parent) : right_rotation(val->parent);
                        if (val->d_black)
                            this->deallocateNode(val);
                        far_child->color = black;
                    }
                    else {
                        nodePtr near_child = get_near_child(val);
                        if (near_child == _end && near_child->color == red) {
                            near_child->color = sibling->color;
                            sibling->color = red;
                            val == val->parent->left ? right_rotation(sibling) : left_rotation(sibling);
                            balance_deleteNode(val);
                        }
                        else {
                            if (val->d_black)
                                deallocateNode(val);
                            sibling->color = red;
                            if (val->parent->color == black)
                                balance_deleteNode(val->parent);
                            else
                                val->parent->color = black;
                        }
                    }
                }
            }

            nodePtr getUncle(nodePtr node) const {
                if (node == this->root || node->parent == this->root || node == _end)
                        return _end;
                if (node->parent == node->parent->parent->left)
                    return node->parent->parent->right;
                else
                    return node->parent->parent->left;
            }

            nodePtr get_far_child(nodePtr node) const
            {
                if (node == node->parent->right)
                    return (node->parent->left->left);
                return (node->parent->right->right);
            }

            nodePtr	get_near_child(nodePtr node) const
            {
                if (node == node->parent->right)
                    return (node->parent->left->right);
                return (node->parent->right->left);
            }

            size_t getSize() const {
                return size;
            }

            nodePtr getEnd() const
            {
                return _end;
            }
            void	switch_color(nodePtr node)
            {
                if (!node || node == this->end())
                    return ;
                if (node->color == black)
                    node->color = red;
                else
                    node->color = black;
            }

            bool    rotate_check(nodePtr node, nodePtr parent, nodePtr grandpa) const  {
                if ((grandpa->left == parent && parent->left == node) || (grandpa->right == parent && parent->right == node))
                    return (true);
                return (false);
            }

            void left_rotation(nodePtr& p_val) {
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

            void right_rotation(nodePtr& val) {
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
//                std::cout << node->value.first << " with address : " << &node << std::endl;
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
                if (node == node->parent->right)
                    return (node->parent->left);
                return (node->parent->right);
            }

            nodePtr getSuccessor(nodePtr node) { // get the inorder successor
                nodePtr curr = node->right;
                while (curr->left)
                    curr = curr->left;
                return curr;
            }

            nodePtr getRoot() const {
                return this->root;
            }

            void setRoot(nodePtr tmp) {
                this->root = tmp;
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
    };
}