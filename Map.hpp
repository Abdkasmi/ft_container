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

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> >>
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

		typedef Key												key_type;
		typedef T												mapped_type;
		typedef ft::pair<const key_type,mapped_type>			value_type;
		typedef Compare											key_compare;
		typedef Alloc											allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename ft::iterator::value_type				iterator;
		typedef typename ft::const_iterator::value_type			const_iterator;
		typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef ptrdiff_t										difference_type;
		typedef size_t											size_type;

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

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _comp(comp), _alloc(alloc), _tree() {};

		template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _comp(comp), _alloc(alloc), _tree() {
				while (first != last) {
					this->insert(*first);
					first++;
				}
			}
		
		map (const map & x): _tree(), _alloc(x.alloc), _comp(x.comp) {
			this->insert(x.begin(), x.end());
		}

		// Destructor

		~map() {
			this->clear();
		}

		// Copy operator

		map& operator=(const map& x) {
			this->clear();
			this->insert(x.begin(), x.end());
			return *this;
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
			return this->_tree.begin();
		}

		const_iterator begin() const {
			return this->_tree.begin()
		}

		iterator end() {
			return this->_tree.end();
		}

		const_iterator end() const {
			return this->_tree.end();
		}

		reverse_iterator rbegin() {
			return this->_tree.rbegin();
		}
		
		const_reverse_iterator rbegin() const {
			return this->_tree.rbegin();
		}

		reverse_iterator rend() {
			return this->_tree.rend();
		}

		const_reverse_iterator rend() const {
			return this->_tree.rend();
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
			if (this->_tree.getRoot())
				return true;
			return false;
		}
		
		size_type size() const {
			size_type lenght = 0;
			iterator it = this->_tree.begin();

			while (it != this->_tree.end()) {
				lenght++;
				it++;
			}
			return lenght;
		}

		size_type max_size() const {
			return this->_alloc.max_size();
		}

		/*
		######## ##       ######## ##     ## ######## ##    ## ########       ###     ######   ######  ########  ######   ######
		##       ##       ##       ###j   ### ##       ###   ##    ##         ## ##   ##    ## ##    ## ##       ##    ## ##    ##
		##       ##       ##       #### #### ##       ####  ##    ##        ##   ##  ##       ##       ##       ##       ##
		######   ##       ######   ## ### ## ######   ## ## ##    ##       ##     ## ##       ##       ######    ######   ######
		##       ##       ##       ##     ## ##       ##  ####    ##       ######### ##       ##       ##             ##       ##
		##       ##       ##       ##     ## ##       ##   ###    ##       ##     ## ##    ## ##    ## ##       ##    ## ##    ##
		######## ######## ######## ##     ## ######## ##    ##    ##       ##     ##  ######   ######  ########  ######   ######
		*/

		mapped_type&	operator[](const key_type& k) {
			value_type val = this->insert(ft::make_pair(k, mapped_type()));
			return val.first->second;
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
			iterator it == this->_tree.search(val.first);

			if (it == this->end()) {
				this->_tree.insert(val);
				iterator ret = this->_tree.search(val.first);
				return (pair<iterator, bool>(ret, true));
			}
			return pair<iterator, bool>(it, false);
		}

		iterator insert(iterator position, const value_type& val) {
			(void)position;
			ft::pair<iterator, bool> it = this->insert(val);

			return it.first;
		}

		template<class InputIterator>
			void	insert(InputIterator first, InputIterato last) {
				while (first != last) {
					this->insert(*first);
					first++;
				}
			}

		void	erase(iterator position) {
			value_type to_find = this->_tree.search(position);
			this->_tree.deleteNode(to_find.first);
		}

		size_type erase(const key_type& k) {
			if (this->_tree.deleteNode(k.first))
				return 1;
			return 0;
		}

		void	erase(iterator first, iterator last) {
			value_type k;
			while (first != last) {
				k = this->_tree.search(first);
				this->_tree.deleteNode(k.first);
				first++;
			}
		}

		void	swap(map& x){
			map tmp = this;

			this->_alloc = x._alloc;
			this->_comp = x._comp;
			this->_tree = x._tree;

			x._alloc = tmp._alloc;
			x._comp = tmp._comp;
			x._tree = tmp._tree;
		}

		void	clear() {
			this->_tree.clear();
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
		
		}

		const_iterator find(const key_type& k) const {

		}

		private:

			allocator_type							_alloc;
			key_compare								_comp;
			ft::RBTree<const key_type, mapped_type>	_tree;
	};
}

