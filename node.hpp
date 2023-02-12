#pragma once

#include "Pair.hpp"
#include <memory>
#include <iostream>

namespace ft {
    enum Color {red, black};

    template<class Key, class T>
    class Node {
    public:
        ft::pair<const Key, T>       value;
        Color                        color;
        Node                         *left, *right, *parent;
        bool                         d_black;

        Node(): value(NULL), color(red), left(NULL), right(NULL), parent(NULL), d_black(false) {};

        ~Node() {};
    };
}