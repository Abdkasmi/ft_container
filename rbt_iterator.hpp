#pragma once

#include <iostream> 
#include "rb_tree.hpp"
#include "Iterator.hpp"
#include <stdexcept>
#include <functional>

namespace ft {

    template<class Key, class T, class Compare = std::less<Key> >
    class RbtIterator {//: ft::iterator<ft::bidirectional_iterator_tag, Compare>

        public :

            typedef Key                                                             key_type;
			typedef typename ft::bidirectional_iterator_tag	                        iterator_category;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>        iterator;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, const T>  const_iterator;
			typedef typename Iterator_traits<T>::value_type			                value_type;
			typedef typename Iterator_traits<T>::difference_type		            difference_type;
			typedef	typename Iterator_traits<T>::pointer				            pointer;
			typedef typename Iterator_traits<T>::reference			                reference;

            typedef typename ft::Node<const Key, T>*                                nodePtr;
            
            RbtIterator(): _node(NULL), _end(NULL) {};

            RbtIterator(nodePtr node): _node(node), _end(NULL) {};

            RbtIterator(nodePtr node, nodePtr end): _node(node), _end(end) {};

            RbtIterator&    operator=(const RbtIterator& x) {
                this->_node = x.node;
                this->end = x.end;
                return *this;
            }

            ~RbtIterator() {};

            RbtIterator &operator++() { // ++it
                nodePtr p;
                if (this->_node == NULL) { // if !node => trying ++ from end(), we go to the root
                    this->_end = this->_node;
                    this->_node = ft::RBTree<const Key, T>::getRoot();
                    if (this->_node == NULL) // tree is empty
                        throw std::underflow_error("Underflow error !");
                    while (this->_node->left) // go to the smallest value in the tree (first inorder node)
                        this->_node = this->_node->left;
                }
                else {
                    if (this->_node->right) { // looking for the next successor => one right then farthest ppossible on the left
                        this->_node = this->_node->right;
                        while (this->_node->left)
                            this->_node = this->_node->left;
                    }
                    else { // we went already through the left-subtree and there is no right-subtree => we move up looking for a P for wich _node is a left child
                           // A non NULL P is the successor, if P is NULL the successor is the end
                        p = this->_node->parent;
                        while (p && this->_node == p->right) {
                            this->_node = p;
                            p = p->parent;
                        }
                        this->_node = p;
                    }
                }
                return *this;
            }

            RbtIterator operator++(int) { // it++
                RbtIterator this_tmp = *this;

                ++(*this);
                return this_tmp;
            }

            RbtIterator &operator--() { // --it
                nodePtr p;
                if (this->_node == NULL) { // if _node == NULL trying to -- from root, we go to root
                    this->_end = this->_node;
                    this->_node = ft::RBTree<const Key, T>::getRoot();
                    if (this->_node == NULL) // tree is empty
                        throw std::underflow_error("Underflow caught");
                    this->_node = ft::RBTree<const Key, T>::findMax(this->_node); // get biggest value
                }
                else {
                    if (this->_node->left) {
                        this->_node = this->_node->left; // looking for next successor
                        while (this->_node->right)
                            this->_node = this->_node->left;
                    }
                    else {
                        p = this->_node->parent;
                        while (p && this->_node == p->left) {
                            this->_node = p;
                            p = p->parent;
                        }
                        this->_node = p;
                    }
                }
                return *this;
            }

            RbtIterator operator--(int) { // it--
                RbtIterator this_tmp = *this;

                --(*this);
                return this_tmp;
            }
        
        private :

            nodePtr _node;
            nodePtr _end;

    };

}