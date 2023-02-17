#pragma once

#include <iostream>
#include "Iterator.hpp"
#include "Utils.hpp"
#include "Pair.hpp"
#include "rb_tree.hpp"
#include "rbt_iterator.hpp"
#include <memory>
#include <functional>

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
	class map {
		

		public:

		/*
		##     ## ######## ##     ## ########  ######## ########     ######## ##    ## ########  ########
		###   ### ##       ###   ### ##     ## ##       ##     ##       ##     ##  ##  ##     ## ##
		#### #### ##       #### #### ##     ## ##       ##     ##       ##      ####   ##     ## ##
		## ### ## ######   ## ### ## ########  ######   ########        ##       ##    ########  ######
		##     ## ##       ##     ## ##     ## ##       ##   ##         ##       ##    ##        ##
		##     ## ##       ##     ## ##     ## ##       ##    ##        ##       ##    ##        ##
		##     ## ######## ##     ## ########  ######## ##     ##       ##       ##    ##        ########
		*/

		typedef Key																					key_type;
		typedef T																					mapped_type;
		typedef ft::pair<const key_type,mapped_type>												value_type;
		typedef Compare																				key_compare;
		typedef Alloc																				allocator_type;
		typedef typename allocator_type::reference													reference;
		typedef typename allocator_type::const_reference											const_reference;
		typedef typename allocator_type::pointer													pointer;
		typedef typename allocator_type::const_pointer												const_pointer;
		typedef typename ft::RbtIterator<value_type, ft::Node<const Key, T> >								iterator;
		typedef typename ft::RbtIterator<const value_type, ft::Node<const Key, T> >						const_iterator;
		typedef typename ft::reverse_iterator<iterator>												reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>										const_reverse_iterator;
		typedef ptrdiff_t																			difference_type;
		typedef size_t																				size_type;
        typedef typename ft::RBTree<const key_type, mapped_type, key_compare>                       tree_type;

		typedef typename ft::Node<const Key, T>* 													nodePtr;

		private:

			allocator_type											_alloc;
			key_compare												_comp;
			tree_type                                           	_tree;
		
		/*
		##     ## ######## ##     ## ########  ######## ########     ######## ##     ## ##    ##  ######  ######## ####  #######  ##    ##  ######
		###   ### ##       ###   ### ##     ## ##       ##     ##    ##       ##     ## ###   ## ##    ##    ##     ##  ##     ## ###   ## ##    ##
		#### #### ##       #### #### ##     ## ##       ##     ##    ##       ##     ## ####  ## ##          ##     ##  ##     ## ####  ## ##
		## ### ## ######   ## ### ## ########  ######   ########     ######   ##     ## ## ## ## ##          ##     ##  ##     ## ## ## ##  ######
		##     ## ##       ##     ## ##     ## ##       ##   ##      ##       ##     ## ##  #### ##          ##     ##  ##     ## ##  ####       ##
		##     ## ##       ##     ## ##     ## ##       ##    ##     ##       ##     ## ##   ### ##    ##    ##     ##  ##     ## ##   ### ##    ##
		##     ## ######## ##     ## ########  ######## ##     ##    ##        #######  ##    ##  ######     ##    ####  #######  ##    ##  ######
		*/

		// Constructors

		public:
		
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _comp(comp), _tree(_comp, _alloc) {};

		template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = NULL): _alloc(alloc), _comp(comp), _tree(_comp, _alloc) {
				this->insert(first, last);
			}
		
		map (const map & x): _alloc(x._alloc), _comp(x._comp), _tree(x._comp, x._alloc) {
			this->insert(x.begin(), x.end());
		}

		// Destructor

		~map() {}

		// Copy operator

		map& operator=(const map& x) {
			this->_comp = x.key_comp();
			this->_alloc = x.get_allocator();
			this->clear();
			this->insert(x.begin(), x.end());
			return *this;
		}

        void _inorder()
        {
            this->_tree._inorder(_tree.getRoot());
        }

		/*
		#### ######## ######## ########     ###    ########  #######  ########   ######
		 ##     ##    ##       ##     ##   ## ##      ##    ##     ## ##     ## ##    ##
		 ##     ##    ##       ##     ##  ##   ##     ##    ##     ## ##     ## ##
		 ##     ##    ######   ########  ##     ##    ##    ##     ## ########   ######
		 ##     ##    ##       ##   ##   #########    ##    ##     ## ##   ##         ##
		 ##     ##    ##       ##    ##  ##     ##    ##    ##     ## ##    ##  ##    ##
		####    ##    ######## ##     ## ##     ##    ##     #######  ##     ##  ######
		*/

		iterator begin() {
			iterator it(_tree.findMin(_tree.getRoot()), _tree.getEnd());

			return it;
		}

		const_iterator begin() const {
			const_iterator it(_tree.findMin(_tree.getRoot()), _tree.getEnd());

			return it;
			}

		iterator end() {
			iterator it(_tree.getEnd(), _tree.getEnd());

			return it;
		}

		const_iterator end() const {
			const_iterator it(_tree.getEnd(), _tree.getEnd());

			return it;
		}

		reverse_iterator rbegin() {
            return (end());
		}
		
		const_reverse_iterator rbegin() const {
            return (end());
		}

		reverse_iterator rend() {
            return (begin());
		}

		const_reverse_iterator rend() const {
            return (begin());
		}

		/*
		 ######     ###    ########     ###     ######  #### ######## ##    ##
		##    ##   ## ##   ##     ##   ## ##   ##    ##  ##     ##     ##  ##
		##        ##   ##  ##     ##  ##   ##  ##        ##     ##      ####
		##       ##     ## ########  ##     ## ##        ##     ##       ##
		##       ######### ##        ######### ##        ##     ##       ##
		##    ## ##     ## ##        ##     ## ##    ##  ##     ##       ##
		 ######  ##     ## ##        ##     ##  ######  ####    ##       ##
		*/

		bool empty() const {
			if (this->_tree.getSize() == 0)
				return true;
			return false;
		}
		
		size_type size() const {
			return this->_tree.getSize();
		}

		size_type max_size() const {
			return this->_alloc.max_size();
		}

		/*
		######## ##       ######## ##     ## ######## ##    ## ########       ###     ######   ######  ########  ######   ######
		##       ##       ##       ###   ### ##       ###   ##    ##         ## ##   ##    ## ##    ## ##       ##    ## ##    ##
		##       ##       ##       #### #### ##       ####  ##    ##        ##   ##  ##       ##       ##       ##       ##
		######   ##       ######   ## ### ## ######   ## ## ##    ##       ##     ## ##       ##       ######    ######   ######
		##       ##       ##       ##     ## ##       ##  ####    ##       ######### ##       ##       ##             ##       ##
		##       ##       ##       ##     ## ##       ##   ###    ##       ##     ## ##    ## ##    ## ##       ##    ## ##    ##
		######## ######## ######## ##     ## ######## ##    ##    ##       ##     ##  ######   ######  ########  ######   ######
		*/

		mapped_type&	operator[](const key_type& k) {
            pair<iterator, bool> tmp = this->insert(ft::make_pair(k,mapped_type()));
            iterator it = tmp.first;
            return (it->second);
		}

		/*
		##     ##  #######  ########  #### ######## #### ######## ########   ######
		###   ### ##     ## ##     ##  ##  ##        ##  ##       ##     ## ##    ##
		#### #### ##     ## ##     ##  ##  ##        ##  ##       ##     ## ##
		## ### ## ##     ## ##     ##  ##  ######    ##  ######   ########   ######
		##     ## ##     ## ##     ##  ##  ##        ##  ##       ##   ##         ##
		##     ## ##     ## ##     ##  ##  ##        ##  ##       ##    ##  ##    ##
		##     ##  #######  ########  #### ##       #### ######## ##     ##  ######
		*/

		pair<iterator, bool> insert(const value_type& val) {
            iterator	it(this->find(val.first));

            if (it == end())
            {
                _tree.insert(val);
                iterator ret(this->find(val.first));
                return (ft::make_pair(ret, true));
            }
            return (ft::make_pair(it, false));
		}

		iterator insert(iterator position, const value_type& val) {
			static_cast<void>(position);
            ft::pair<iterator, bool>	p = insert(val);
            if (p.second == false)
                return (p.first);
            return (p.first);
		}

		template<class InputIterator>
			void	insert(InputIterator first, InputIterator last) {
				while (first != last) {
					insert(*first);
					first++;
				}
			}

		void	erase(iterator position) {
            erase(position->first);
		}

		size_type erase(const key_type& k) {
            size_t s = _tree.getSize();
            _tree.deleteNode(k);
			if (this->_tree.getSize() != s)
                return 1;
			return 0;
		}

		void	erase(iterator first, iterator last) {
            iterator tmp = first;
            size_type i = 0;
            while (tmp != last) {
                ++tmp;
                ++i;
            }
            while (i > 0) {
                tmp = last;
                size_type j = -1;
                while (++j < i){
                    --tmp;
                }
                erase(tmp);
                --i;
            }
		}

		void	swap(map& x){
			_tree.swap(x._tree);
		}

		void	clear() {
			this->_tree.clear(_tree.getRoot());
		}

		/*
		 #######  ########   ######  ######## ########  ##     ## ######## ########   ######
		##     ## ##     ## ##    ## ##       ##     ## ##     ## ##       ##     ## ##    ##
		##     ## ##     ## ##       ##       ##     ## ##     ## ##       ##     ## ##
		##     ## ########   ######  ######   ########  ##     ## ######   ########   ######
		##     ## ##     ##       ## ##       ##   ##    ##   ##  ##       ##   ##         ##
		##     ## ##     ## ##    ## ##       ##    ##    ## ##   ##       ##    ##  ##    ##
		 #######  ########   ######  ######## ##     ##    ###    ######## ##     ##  ######
		*/

		key_compare key_comp() const {
			return this->_comp;
		}


	private : 
				class value_compare: public std::binary_function<value_type, value_type, bool> {
					friend class map;
					
					protected:
					
						Compare comp;
						value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
					
					public:
					
						typedef bool result_type;
						typedef value_type first_argument_type;
						typedef value_type second_argument_type;
						bool operator() (const value_type& x, const value_type& y) const {
							return comp(x.first, y.first);
						}
				};

	public :

		value_compare value_comp() const {
			return value_compare(this->_comp);
		}

		/*
		 #######  ########  ######## ########     ###    ######## ####  #######  ##    ##  ######
		##     ## ##     ## ##       ##     ##   ## ##      ##     ##  ##     ## ###   ## ##    ##
		##     ## ##     ## ##       ##     ##  ##   ##     ##     ##  ##     ## ####  ## ##
		##     ## ########  ######   ########  ##     ##    ##     ##  ##     ## ## ## ##  ######
		##     ## ##        ##       ##   ##   #########    ##     ##  ##     ## ##  ####       ##
		##     ## ##        ##       ##    ##  ##     ##    ##     ##  ##     ## ##   ### ##    ##
		 #######  ##        ######## ##     ## ##     ##    ##    ####  #######  ##    ##  ######
		*/

		iterator find(const key_type& k) {
            iterator it = this->begin();

            while (it != this->end() && it->first != k)
                it++;
            return it;
		}

		const_iterator find(const key_type& k) const {
            const_iterator it = this->begin();

            while (it != this->end() && it->first != k)
                it++;
            return it;
		}

		size_type count(const key_type& k) const {
			nodePtr toFind = this->_tree.search_(k);

            if (toFind->value.first == k) {
                return 1;
            }
			return 0;
		}

		iterator lower_bound(const key_type& k) {
			iterator it = find(k);

            if (it != end())
                return it;
            if (_comp(k, _tree.findMin(_tree.getRoot())->value.first))
                return iterator(_tree.findMin(_tree.getRoot()), _tree.getEnd());
            if (_comp(_tree.findMax(_tree.getRoot())->value.first, k))
                return end();
			return this->end();
		}

		const_iterator lower_bound(const key_type& k) const {
			const_iterator it = find(k);

            if (it != end())
                return it;
            if (_comp(k, _tree.findMin(_tree.getRoot())->value.first))
                return iterator(_tree.findMin(_tree.getRoot()), _tree.getEnd());
            if (_comp(_tree.findMax(_tree.getRoot())->value.first, k))
                return end();
            return this->end();
		}

		iterator upper_bound(const key_type& k) {
			iterator it = find(k);

            if (it != end())
                return ++it;
            if (_comp(k, _tree.findMin(_tree.getRoot())->value.first))
                return iterator(_tree.findMin(_tree.getRoot()), _tree.getEnd());
            if (_comp(_tree.findMax(_tree.getRoot())->value.first, k))
                return end();
            return this->end();
		}

		const_iterator upper_bound(const key_type& k) const {
			const_iterator it = find(k);

            if (it != end())
                return ++it;
            if (_comp(k, _tree.findMin(_tree.getRoot())->value.first))
                return iterator(_tree.findMin(_tree.getRoot()), _tree.getEnd());
            if (_comp(_tree.findMax(_tree.getRoot())->value.first, k))
                return end();
            return this->end();
		}

		pair<iterator, iterator> equal_range(const key_type& k) {
			return pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k));
		}

		pair<const_iterator, const_iterator> equal_range(const key_type& k) const {
			return pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k));
		}

		/*
		   ###    ##       ##        #######   ######     ###    ########  #######  ########
		  ## ##   ##       ##       ##     ## ##    ##   ## ##      ##    ##     ## ##     ##
		 ##   ##  ##       ##       ##     ## ##        ##   ##     ##    ##     ## ##     ##
		##     ## ##       ##       ##     ## ##       ##     ##    ##    ##     ## ########
		######### ##       ##       ##     ## ##       #########    ##    ##     ## ##   ##
		##     ## ##       ##       ##     ## ##    ## ##     ##    ##    ##     ## ##    ##
		##     ## ######## ########  #######   ######  ##     ##    ##     #######  ##     ##
		*/

		allocator_type get_allocator() const {
			return this->_alloc;
		}
	};

	// overload operators

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename map<Key, T>::const_iterator	lhs_b(lhs.begin());
		typename map<Key, T>::const_iterator	rhs_b(rhs.begin());
		typename map<Key, T>::const_iterator	ite(lhs.end());

		while (lhs_b != ite)
		{
			if (lhs_b->first != rhs_b->first)
				return (false);
			lhs_b++;
			rhs_b++;
		}
		return (true);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{ return (!(lhs == rhs)); }

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{ return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template <class Key, class T, class Compare, class Alloc>
	bool	operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{ return (!(rhs < lhs)); }

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{ return (rhs < lhs); }

	template <class Key, class T, class Compare, class Alloc>
	bool	operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{ return (!(lhs < rhs)); }
}

