#pragma once

#include "Pair.hpp"
#include <memory>
#include <iostream>

namespace ft {
    enum Color {red, black};

    template<class Key, class T>
    class Node {
    public:
        ft::pair<const Key, T>       *value;
        Color                        color;
        Node                         *left, *right, *parent;

        Node(): value(NULL), color(red), left(NULL), right(NULL), parent(NULL){};

        // Node(const ft::pair<const Key, T>& val) {
        //     std::allocator<ft::pair<const Key, T> > alloc;

        //     this->value = alloc.allocate(1);
        //     alloc.construct(this->value, val);
        //     this->left = this->right = this->parent = NULL;
        //     this->color = red;
        // }

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
}