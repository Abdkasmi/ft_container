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

        Node(const Node& copy): value(copy.value), color(copy.color), left(copy.left), right(copy.right), parent(copy.parent )

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

            typedef ft::pair<const Key, T> value_type;

            typedef Node<const Key, T>* nodePtr;
            typedef std::allocator<Node<const Key, T> > Alloc;

            nodePtr     root;
            nodeAlloc   alloc;

            RBTree(): root(NULL), alloc(NULL) {};

            ~RBTree() {};

            nodePtr NewNode(value_type& val) {
                nodePtr node;
                Alloc   alloc;

                node = alloc.allocate(1);
                alloc.construct(node, val);
                return node;
            }

            void    insert(value_type& val) {
                if (!this->root)
                    this->root = NewNode(val);
                else {
                    
                }
            }

    };

}