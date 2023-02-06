#pragma once

#include <iostream>
#include <memory>
#include <functional>
#include "Utils.hpp"
#include "Pair.hpp"
#include "rbt_iterator.hpp"
#include "node.hpp"

namespace ft {

    template<class Key, class T, class Compare = std::less<Key> >
    class RBTree {
        public:

            typedef typename ft::pair<const Key, T>                                        value_type;
            typedef Key                                                                    key_type;
            typedef typename ft::Node<const Key, T>*                                       nodePtr;
            typedef Compare																   key_compare;
            typedef std::allocator<Node<const Key, T> >                                    Alloc;
            typedef ft::RbtIterator<ft::pair<const Key, T>	>	                           iterator;
//            typedef ft::RbtIterator<const ft::pair<const Key, T> >                         const_iterator;

    private:
            nodePtr     root;
            Alloc       alloc;
            key_compare comp;
            size_t      size;
            iterator     _end;

    public:

            RBTree(const key_compare& comp = key_compare(), const Alloc& alloc = Alloc()): root(NULL), alloc(alloc), comp(comp), size(0), _end(root) {};

            ~RBTree() {
                if (this->root) {
                    alloc.destroy(this->root);
                    alloc.deallocate(this->root, 1);
                    this->root = NULL;
                }
            }

            nodePtr NewNode(const value_type& val, nodePtr parent) {
                nodePtr node;
                std::allocator<ft::pair<const Key, T> > p_alloc;


                node = alloc.allocate(1);
                node->value = p_alloc.allocate(1);
                p_alloc.construct(node->value, val);
                node->parent = parent;
                node->color = red;
                node->right = node->left = NULL;
                return node;
            }

            void    deallocateNode(nodePtr &del) {
                std::allocator<ft::pair<const Key, T> > p_alloc;

                std::cout << "value to del : " << del->value->first << std::endl; 
                p_alloc.destroy(del->value);
                p_alloc.deallocate(del->value, 1);
                this->alloc.deallocate(del, 1);
                del = NULL;
            }

            nodePtr    insert(const value_type& val) {
                nodePtr to_find = search_(val.first);

//                std::cout << to_find->value->first << std::endl;
                if (to_find != this->end() && to_find->value->first == val.first)
                        return to_find;
                this->size++;
                if (!this->root) {
                    this->root = this->NewNode(val, NULL);
                    this->root->color = black;
                    return (root);
                }
                if (this->comp(this->root->value->first, val.first)) {
                    this->root->right = this->NewNode(val, this->root);
                     this->root->right->parent = root;
                    this->insert_balance(this->root->right);
                }
                else if (this->comp(val.first, this->root->value->first)) {
                    this->root->left = this->NewNode(val, this->root);
                     this->root->left->parent = root;
                    this->insert_balance(this->root->left);
                }
                return this->root;
            }

            void    insert_balance(nodePtr val) {
                if (val == this->root || val->parent->color == black)
					return ;
                nodePtr uncle = getUncle(val);
                if (uncle != this->end() && uncle->color == red) {
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
                            right_rotation(val);
                        else
                            left_rotation(val);
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
            }

            bool    deleteNode(const Key &key) {
                nodePtr val = this->search_(key);

                if (!this->root || !val)
                    return false;
                this->size--;
                if (val == root) {
                    if (this->root->left == NULL && this->root->right == NULL){
                        this->deallocateNode(this->root);
                        return true;
                    }
                    else if (this->root->left == NULL || this->root->right == NULL) {
                        nodePtr oldRoot = this->root;
                        this->root = (root->left == NULL) ? root->right : root->left;
                        deallocateNode(oldRoot);                    }
                    else {
                        nodePtr successor = this->getSuccessor(this->root);
                        this->root->value = successor->value;
                        deleteNode(this->root->value->first);

                    }
                }
                else if (val->color == red) {
                    if (val->right == NULL && val->left == NULL)
                    {
                        this->deallocateNode(val); // segfault here
                    }
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
                    balance_deleteNode(val);
                return true;
            }

            void    balance_deleteNode(nodePtr &val) {
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

            nodePtr getUncle(nodePtr node) {
                if (node == this->root || node->parent == this->root || node == this->end())
                        return this->end();
                if (node->parent == node->parent->parent->left)
                    return node->parent->parent->right;
                else
                    return node->parent->parent->left;
            }

            size_t getSize() const {
                return size;
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

            void    left_rotation(nodePtr val) {
                nodePtr tmp = val;
				nodePtr tmp2 = val->right->left;

				val = val->right;
				val->left = tmp;
				tmp->right = tmp2;
				val->parent = tmp->parent;
				if (tmp2)
					tmp2->parent = tmp;
				if (val->parent)
				{
					if (tmp == tmp->parent->right)
						val->parent->right = val;
					else
						val->parent->left = val;
				}
				else
					this->root = val;
				tmp->parent = val;
            }

            void    right_rotation(nodePtr val) {
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
                }
                else
                    this->root = val;
                tmp->parent = val;
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

            nodePtr search_(const Key& val) const {
                nodePtr tmp = this->root;

                while (tmp && tmp != this->end()) {
                    if (this->comp(val, tmp->value->first)) { // val smaller
//                        std::cout << "smaller" << std::endl;
                        tmp = tmp->left;
                    } else if (this->comp(tmp->value->first, val)) { // val bigger
//                        std::cout << "bigger" << std::endl;
                        tmp = tmp->right;
                    }
                    else
                        return tmp;
                }
                return tmp;
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

            nodePtr findMin(nodePtr cur) {
                while (cur->left)
                    cur = cur->left;
                return cur;
            }

            nodePtr findMax(nodePtr cur) {
                if (!cur)
                    return cur;
                while (cur->right)
                    cur = cur->right;
                return cur;
            }

            // iterator

            nodePtr begin() {
                nodePtr tmp = this->root;
				
				if (!tmp)
					return (NULL);
				while (tmp->left)
				{
					tmp = tmp->left;
				}
				return (tmp);
            }

            nodePtr begin() const {
                nodePtr tmp = this->root;
				
				if (!tmp)
					return (NULL);
				while (tmp->left)
				{
					tmp = tmp->left;
				}
				return (tmp);
            }

            nodePtr end() {
                return (this->_end.getEnd());
            }

            nodePtr end() const {
                return (this->_end.getEnd());
            }
    };
}