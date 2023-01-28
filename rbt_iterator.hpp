#pragma once

#include <iostream> 
#include "rb_tree.hpp"
#include "Iterator.hpp"
#include <stdexcept>
#include <functional>

namespace ft {

    template< class T2 > struct remove_const                { typedef T2 type; };
	template< class T2 > struct remove_const<const T2>       { typedef T2 type; };

    template<class T>
    class RbtIterator {

        public :

            typedef	typename T::first_type				                        key_type;
			typedef	typename T::second_type			                        	mapped_type;
			typedef typename ft::iterator<RbtIterator, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<RbtIterator, T>::value_type			value_type;
			typedef typename ft::iterator<RbtIterator, T>::difference_type		difference_type;
			typedef typename ft::iterator<RbtIterator, T>::pointer				pointer;
			typedef typename ft::iterator<RbtIterator, T>::reference			reference;

            typedef typename ft::Node<const key_type, mapped_type>*             nodePtr;
            
            RbtIterator(): _node(NULL), _end(NULL) {}

            RbtIterator(nodePtr node): _node(node), _end(NULL) {}

            RbtIterator(nodePtr node, nodePtr end): _node(node), _end(end) {}

            RbtIterator(const RbtIterator<typename remove_const<T>::type> & ref) : _node(ref._node), _end(ref._end) {}
            
            RbtIterator&    operator=(const RbtIterator& x) {
                this->_node = x._node;
                this->_end = x._end;
                return *this;
            }

            ~RbtIterator() {};

            RbtIterator &operator++() { // ++it
                nodePtr p;
                if (this->_node == NULL) { // if !node => trying ++ from end(), we go to the root
                    this->_end = this->_node;
                    this->_node = ft::RBTree<const key_type, T>::getRoot();
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
                    this->_node = ft::RBTree<const key_type, T>::getRoot();
                    if (this->_node == NULL) // tree is empty
                        throw std::underflow_error("Underflow caught");
                    this->_node = ft::RBTree<const key_type, T>::findMax(this->_node); // get biggest value
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

            void    setBase(nodePtr tmp) {
                this->_node = tmp;
            }

            nodePtr base(void) const {
                return this->_node;
            }

        private :

            nodePtr _node;
            nodePtr _end;

    };

    template < typename IteratorL, typename IteratorR >
		bool operator==(RbtIterator<IteratorL> const &lhs, RbtIterator<IteratorR> const &rhs)
		{
			return (lhs.base() == rhs.base());
		}

	template < typename IteratorL, typename IteratorR >
		bool operator!=(RbtIterator<IteratorL> const &lhs, RbtIterator<IteratorR> const &rhs)
		{
			return (!(lhs.base() == rhs.base()));
		}

	template < typename IteratorL, typename IteratorR >
		bool operator<(RbtIterator<IteratorL> const &lhs, RbtIterator<IteratorR> const &rhs)
		{
			return (lhs.base() < rhs.base());
		}

	template < typename IteratorL, typename IteratorR >
		bool operator>(RbtIterator<IteratorL> const &lhs, RbtIterator<IteratorR> const &rhs)
		{
			return (rhs.base() < lhs.base());
		}

	template < typename IteratorL, typename IteratorR >
		bool operator<=(RbtIterator<IteratorL> const &lhs, RbtIterator<IteratorR> const &rhs)
		{
			return (!(rhs.base() < lhs.base()));
		}

	template < typename IteratorL, typename IteratorR >
		bool operator>=(RbtIterator<IteratorL> const &lhs, RbtIterator<IteratorR> const &rhs)
		{
			return (!(lhs.base() < rhs.base()));
		}

	// arithmetic operators

	template < typename Iterator >
		RbtIterator<Iterator> operator+(typename RbtIterator<Iterator>::difference_type n, RbtIterator<Iterator> const &rhs)
		{
			return (rhs.base() + n);
		}

	template < typename IteratorL, typename IteratorR >
		typename RbtIterator<IteratorL>::difference_type operator-(RbtIterator<IteratorL> const &lhs, RbtIterator<IteratorR> const &rhs)
		{
			return (lhs.base() - rhs.base());
		}

}