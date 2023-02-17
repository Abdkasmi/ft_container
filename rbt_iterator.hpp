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

            nodePtr *base() const {
                return _node;
            }

            RbtIterator &operator++() { // ++it
				_node = increment(_node);
                return *this;
            }

            RbtIterator operator++(int) { // it++
                nodePtr* tmp = _node;
                _node = increment(_node);
                return (RbtIterator(tmp, _end));
            }

            RbtIterator &operator--() { // --it
                _node = decrement(_node);
                return *this;
            }

            RbtIterator operator--(int) { // it--
                nodePtr* tmp = _node;
                _node = decrement(_node);
                return (RbtIterator(tmp, _end));
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
                nodePtr	*tmp = node;
                while (tmp->parent)
                    tmp = tmp->parent;
                if (node == _end)
                    return (greatest(tmp)); // might just return _end
                if (node->right == _end)
                {
                    tmp = node;
                    while (tmp->parent && tmp == tmp->parent->right)
                        tmp = tmp->parent;
                    tmp = tmp->parent;
                    if (!tmp)
                        return _end;
                    return tmp;
                }
                tmp = node->right;
                while (tmp->left != _end)
                    tmp = tmp->left;
                if (!tmp)
                    return _end;
                return tmp;
            }

            nodePtr* greatest(nodePtr* cur) {
                while (cur->right != _end)
                    cur = cur->right;
                return cur;
            }

            nodePtr *decrement(nodePtr* node) {
                nodePtr	*tmp = node;

                while (tmp->parent)
                    tmp = tmp->parent;
                if (node == _end) {
                    return (greatest(tmp));
                }
                if (node->left == _end)
                {
                    tmp = node;
                    while (tmp->parent && tmp == tmp->parent->left)
                        tmp = tmp->parent;
                    tmp = tmp->parent;
                    if (!tmp) {
                        return _end;
                    }
                    return tmp;
                }
                tmp = node->left;
                while (tmp->right != _end)
                    tmp = tmp->right;
                if (!tmp)
                    return _end;
                return tmp;
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
}