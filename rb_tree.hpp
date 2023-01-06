#pragma once

#include <iostream>
#include <memory>

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

        Node(const Node& copy): value(copy.value), color(copy.color), left(copy.left), right(copy.right), parent(copy.parent)

        ~Node() {
            std::allocator<ft::pair<const Key, T> > alloc;

            if (this->value) {
                alloc.destroy(this->value);
                alloc.dealocate(this->value, 1);
                this->value = NULL;
            }
        }
    };

    template<class Key, class T>
    class RBTree {
        public:

            typedef typename ft::pair<const Key, T> value_type;

            typedef typename Node<const Key, T>* nodePtr;
            typedef std::allocator<Node<const Key, T> > Alloc;

        private:
            nodePtr     root;
            Alloc       alloc;

            RBTree(): root(NULL), alloc(NULL) {};

            ~RBTree() {};

            nodePtr NewNode(value_type& val) {
                nodePtr node;
                Alloc   alloc;

                node = alloc.allocate(1);
                alloc.construct(node, val);
                return node;
            }

            void    deleteNode(nodePtr del) {
                alloc.destroy(del);
                alloc.deallocate(del, 1);
            }

            nodePtr     searchTree(const Key key) {

            }

            nodePtr    insert(value_type& val) {
                if (!this->root) {
                    this->root = NewNode(val);
                    this->root->color = black;
                    return (root);
                }
                if (val > this->root->value)
                    this->root->right = insert(this->root->right);
                else if (val < this->root->value)
                    this->root->left = insert(this->root->left);
                balance(val);
                return this->root;
            }

            void    balance(nodePtr& val) {
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
                                right_rotation(val);
                            }
                            val->parent->color = black;
                            val->parent->parent->color = red;
                            left_rotation(val->parent->parent);
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
                                left_rotation(val);
                            }
                            val->parent->color = black;
                            val->parent->parent->color = red;
                            right_rotation(val->parent->parent);
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

            void    balance_deleteNode(nodePtr& val) {
                nodePtr sibling;
                while (val != this->root && val->color == black) {
                    if (val == val->parent->left) {
                        sibling = val->parent->right;
                        if (sibling->color = red) {
                            sibling->color = black;
                            val->parent->color = red;
                            left_rotation(val->parent);
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
                                right_rotation(sibling);
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
                            right_rotation(val->parent);
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
                                left_rotation(sibling);
                                sibling = val->parent->left;
                            }
                            sibling->color = val->parent->color;
                            val->parent->color = black;
                            sibling->left->color = black;
                            right_rotation(val->parent);
                            val = root;    
                        }
                    }
                }
                val->color = black;
            }
    };

}