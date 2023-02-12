#pragma once

#include <iostream>
#include "node.hpp"
#include "Iterator.hpp"
#include <stdexcept>
#include <functional>

class Node;
namespace ft {

    template<class T, class Node>
    class RbtIterator {

        public :

            typedef	T				                                    value_type;
			typedef Node                                                nodePtr;
			typedef value_type*                                         pointer;
			typedef value_type&                                         reference;
			typedef std::ptrdiff_t                                      difference_type;
            typedef ft::bidirectional_iterator_tag                      iterator_category;

            RbtIterator(): _node(NULL), _end(NULL) {};

            RbtIterator(nodePtr* node, nodePtr* end): _node(node), _end(end) {};

            RbtIterator(const RbtIterator<value_type, nodePtr> & ref) : _node(ref._node), _end(ref._end) {};

            RbtIterator&    operator=(const RbtIterator& x) {
                this->_node = x.getNode();
                this->_end = x.getEnd();
                return *this;
            }

            ~RbtIterator() {};

            operator RbtIterator<const value_type, nodePtr>(void) const {
                return RbtIterator<const value_type, nodePtr>(_node, _end);
            }

            RbtIterator &operator++() { // ++it
				_node = increment(_node);
                return *this;
            }

            RbtIterator operator++(int) { // it++
                nodePtr* this_tmp = _node;
                _node = increment(_node);
                return (RbtIterator(this_tmp, _end));
            }

            RbtIterator &operator--() { // --it
                _node = decrement(_node);
                return *this;
            }

            RbtIterator operator--(int) { // it--
                nodePtr* this_tmp = _node;
                _node = decrement(_node);
                return (RbtIterator(this_tmp, _end));
            }

            nodePtr* getNode() const {
                return this->_node;
            }

            nodePtr* getEnd() const {
                return this->_end;
            }

            value_type	&operator*() const {
                return (this->_node->value);
            }

			value_type	*operator->() const {
                return (&this->_node->value);
            }

            nodePtr* increment(nodePtr* node) {
                nodePtr* node_ = node;
                if (node_->right != _end) {
                    node_ = node_->right;
                    while (node_->left != _end) {
                        node_ = node_->left;
                    }
                } else {
                    nodePtr *parent = node_->parent;
                    while (parent != _end && node_ == parent->right) {
                        node_ = parent;
                        parent = node_->parent;
                        std::cout << &parent->right << " end : " << &_end << std::endl;
                        if (parent == _end) {
                            break;
                        }
                    }
                    if (parent != _end)
                        node_ = parent;
                    else
                        node_ = _end;  // set the iterator to the end
                }
                return node_;
            }

            nodePtr *decrement(nodePtr* node) {
                nodePtr *node_ = node;
                if (node_ == _end)
                    return _end;
                if (node_->left != _end) {
                    node_ = node_->left;
                    while (node_->right != _end)
                        node_ = node_->right;
                }
                else {
                    nodePtr *parent = node_->parent;
                    while (parent != _end && node_ == parent->left) {
                        node_ = parent;
                        parent = node_->parent;
                    }
                    if (parent != _end)
                        node_ = parent;
                    else
                        node_ = _end;  // set the iterator to the beginning
                }
                return node_;
                }

        public :

            nodePtr* _node;
            nodePtr* _end;
    };

    template < typename ItL_T,typename ItR_T, typename ItL_N, typename ItR_N >
		bool operator==(RbtIterator<ItL_T, ItL_N> const &lhs, RbtIterator<ItR_T, ItR_N> const &rhs)
		{
			return (lhs.getNode() == rhs.getNode());
		}

	template < typename ItL_T,typename ItR_T, typename ItL_N, typename ItR_N >
		bool operator!=(RbtIterator<ItL_T, ItL_N>const &lhs, RbtIterator<ItR_T, ItR_N> const &rhs)
		{
			return (!(lhs.getNode() == rhs.getNode()));
		}
//
//	template < typename IteratorL, typename IteratorR >
//		bool operator<(RbtIterator<IteratorL> const &lhs, RbtIterator<IteratorR> const &rhs)
//		{
//			return (lhs.base() < rhs.base());
//		}
//
//	template < typename IteratorL, typename IteratorR >
//		bool operator>(RbtIterator<IteratorL> const &lhs, RbtIterator<IteratorR> const &rhs)
//		{
//			return (rhs.base() < lhs.base());
//		}
//
//	template < typename IteratorL, typename IteratorR >
//		bool operator<=(RbtIterator<IteratorL> const &lhs, RbtIterator<IteratorR> const &rhs)
//		{
//			return (!(rhs.base() < lhs.base()));
//		}
//
//	template < typename IteratorL, typename IteratorR >
//		bool operator>=(RbtIterator<IteratorL> const &lhs, RbtIterator<IteratorR> const &rhs)
//		{
//			return (!(lhs.base() < rhs.base()));
//		}
//
//	 arithmetic operators
//
//	template < typename Iterator >
//		RbtIterator<Iterator> operator+(typename RbtIterator<Iterator>::difference_type n, RbtIterator<Iterator> const &rhs)
//		{
//			return (rhs.base() + n);
//		}
//
//	template < typename IteratorL, typename IteratorR >
//		typename RbtIterator<IteratorL>::difference_type operator-(RbtIterator<IteratorL> const &lhs, RbtIterator<IteratorR> const &rhs)
//		{
//			return (lhs.base() - rhs.base());
//		}

}