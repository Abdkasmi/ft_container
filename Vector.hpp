#pragma once

#include <iostream>
#include <memory>
#include "Utils.hpp"
#include "Iterator.hpp"

namespace ft {

		template <class T, class Alloc = std::allocator<T> >
		class vector{

			public :
			/*
			##     ## ######## ##     ## ########  ######## ########     ######## ##    ## ########  ########
			###   ### ##       ###   ### ##     ## ##       ##     ##       ##     ##  ##  ##     ## ##
			#### #### ##       #### #### ##     ## ##       ##     ##       ##      ####   ##     ## ##
			## ### ## ######   ## ### ## ########  ######   ########        ##       ##    ########  ######
			##     ## ##       ##     ## ##     ## ##       ##   ##         ##       ##    ##        ##
			##     ## ##       ##     ## ##     ## ##       ##    ##        ##       ##    ##        ##
			##     ## ######## ##     ## ########  ######## ##     ##       ##       ##    ##        ########
			*/
				
				typedef T																value_type;
				typedef Alloc															allocator_type;
				typedef typename allocator_type::reference								reference;
				typedef typename allocator_type::const_reference						const_reference;
				typedef typename allocator_type::pointer 								pointer;
				typedef typename allocator_type::const_pointer 							const_pointer;
				typedef typename ft::random_access_iterator<T>							iterator;
				typedef typename ft::random_access_iterator<const T>					const_iterator;
				typedef typename ft::reverse_iterator<iterator>							reverse_iterator;
				typedef typename ft::reverse_iterator<const_iterator>					const_reverse_iterator;
				typedef std::ptrdiff_t													difference_type;
				typedef std::size_t														size_type;
						
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

			explicit vector(const allocator_type& alloc = allocator_type()): _allocator(alloc),_begin(NULL), _size(0), _lenght(0) {};
			
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _allocator(alloc), _size(n), _lenght(n * 2) {
				this->_begin = this->_allocator.allocate(this->_lenght, 0);
				for (size_type i = 0; i < n; i++)
					this->_allocator.construct(this->_begin + i, val);
			}

			template <class InputIterator>
				vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _allocator(alloc) {
					size_t i = 0;
					while (first != last) {
						first++;
						i++;
					}
					this->_size = i;
					this->_lenght = i * 2;
					this->_begin = this->_allocator.allocate(this->_lenght, 0);
					for (size_type i = 0; i < this->_size; i++) {
						this->_allocator.construct(this->_begin + i, (*first)++);
					}
				}
			
			vector(const vector& x): _allocator(x._allocator), _size(x._size), _lenght(x._lenght) {
				this->_begin = this->_allocator.allocate(this->_lenght, 0);
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(this->_begin + i, *(x._begin + i));
			}

			// Destrcuctor

			~vector() {
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.destroy(this->_begin + i);
				this->_allocator.deallocate(this->_begin, this->_lenght);
			}

			// Overload operator=

			vector& operator= (const vector& x) {
				if (this != &x)
					this->assign(x.begin(), x.end());
				return *this;
			}

			// Iterators

			iterator begin() {
				return this->_begin;
			}

			iterator end() {
				return this->_begin + this->_size;
			}

			const_iterator begin() const {
				return this->_begin;
			}

			const_iterator end() const {
				return this->_begin + this->_size;
			}

			reverse_iterator rbegin() {
				return (reverse_iterator(this->_begin + this->_size));
			}

			reverse_iterator rend() {
				return (reverse_iterator(this->_begin));
			}

			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(this->_begin + this->_size));
			}

			const_reverse_iterator rend() const {
				return (reverse_iterator(this->_begin));
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

			size_type size() const {
				return this->_size;
			}

			size_type max_size() const {
				return this->_allocator.max_size();
			}

			void resize(size_type n, value_type val = value_type()) {
				if (n < this->_size) {
					for (size_type i = this->_size; i > n; i--)
						this->_allocator.destroy(this->_begin + i);
				}
				else if (n > this->_size) {
					if (n + this->_size <= this->_lenght) {
						for (size_type i = this->_size; i < this->_size + n; i++) {
							this->_allocator.construct(this->_begin + i, val);
						}
					}
					else if (n + this->_size > this->_lenght) {
						this->_lenght = n + this->_size * 2;
						pointer	tmp2;
						tmp2 = this->_allocator.allocate(this->_lenght, 0);
						for (size_type i = 0; i < this->_size; i++) {
							this->_allocator.construct(tmp2 + i, this->_begin + i);
						}
						for (size_type i = this->_size; i < this->_size + n; i++) {
							this->_allocator.construct(tmp2 + i, val);
						}
						this->_begin = tmp2;
						this->_size += n;
					}
				}
				this->_size = n;
			}

			size_type capacity() const {
				return this->_lenght;
			}

			bool empty() {
				return !this->_size;
			}

			void reserve(size_type n) {
				if (n > max_size())
					throw std::length_error("vector::reserve");
				if (n > this->_lenght) {
					pointer tmp = this->_allocator.allocate(n, 0);
					for (size_type i = 0; i < n; i++)
						this->_allocator.construct(tmp + i, this->_begin + i);
					for (size_type i = 0; i < this->_size; i++)
						this->_allocator.destroy(this->_begin + i);
					this->_allocator.deallocate(this->_begin, this->_lenght);
					this->_begin = tmp;
					this->_lenght = n;
				}
				else
					return ;
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

			reference operator[](size_type n) {
				return *(this->_begin + n);
			}

			const_reference operator[](size_type n) const {
				return *(this->_begin + n);
			}

			reference at(size_type n) {
				if (n > this->_size)
					throw std::out_of_range("vector::at");
				return *this->begin + n;
			}

			const_reference at(size_type n) const {
				return *this->_begin + n;
			}

			reference front() {
				return *this->_begin;
			}

			const_reference front() const {
				return *this->_begin;
			}

			reference back() {
				return *this->_begin + (this->_size - 1);
			}

			const_reference back() const {
				return *this->_begin + (this->_size - 1);
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

			template <class InputIterator>
				void assign(InputIterator first, InputIterator last) {
					for (size_type i = 0; i < this->_size; i++)
						this->_allocator.destroy(this->_begin + i);
					this->_allocator.deallocate(this->_begin, this->_lenght);
					this->_size = last - first;
					this->_lenght = this->_size * 2;
					this->_begin = this->_allocator.allocate(this->_lenght, 0);
					for (size_type i = 0; i < this->_size; i++)
						this->_allocator.construct(this->_begin + i, *first++);
				}

			void assign(size_type n, const value_type & val) {
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.destroy(this->_begin + i);
				this->_allocator.dealocate(this->_begin, this->_lenght);
				this->_size = n;
				this->_lenght = n * 2;
				this->_begin = this->_allocator.allocate(this->_lenght, 0);
				for (size_type i = 0; i < n; i++)
					this->_allocator.constrcut(this->_begin + i, val[i]);
			}

			void push_back(const value_type & val) {
				if (this->_size + 1 <= this->_lenght){
					this->_allocator.construct(this->_begin + this->_size, val);
					this->_size++;
				}
				else
					this->resize(this->_size + 1, val);
			}

			void	pop_back(){
				if (this->_size > 0) {	
					this->_allocator.destroy(this->_begin + (this->_size - 1));
					this->_size--;
				}
			}

			iterator insert (iterator position, const value_type& val) {
				size_type i = 0;
				pointer tmp = this->_allocator.allocate((this->_size + 1) * 2);
				iterator it = this->_begin;
				while (it != position) {
					*it++;
					i++;
				}
				for (size_type j = 0; j < this->_size + 1; j++) {
					if (i == j)
						this->_allocator.construct(tmp + j, val);
					else
						this->_allocator.construct(tmp + j, *(this->_begin + j));
				}
				for (size_type j = 0; j < this->_size; j++)
					this->_allocator.destroy(this->_begin + j);
				this->_allocator.deallocate(this->_begin);
				this->_begin = tmp;
				this->_size++;
				this->_lenght = this->_size * 2;
				return (it);
			}

			void insert(iterator position, size_type n, const value_type& val) {
				size_type i = 0, k = 0;
				pointer tmp = this->_allocator.allocate((this->_size + n) * 2);
				iterator it = this->_begin;
				while (it != position) {
					*it++;
					i++;
				}
				for (size_type j = 0; j < this->_size + n; j++) {
					if (j == i) {
						while (k < n) {
							this->_allocator.construct(tmp + j, val[k]);
							k++;
						}
						j += k;
					}
					else
						this->_allocator.construct(tmp + j, *(this->_begin + j));
				}
				for (size_type j = 0; j < this->_size; j++)
					this->_allocator.destroy(this->_begin + j);
				this->_allocator.deallocate(this->_begin);
				this->_begin = tmp;
				this->_size += n;
				this->_lenght = this->_size * 2;
			}

			template <class InputIterator>
				void insert(iterator position, InputIterator first, InputIterator last) {
					size_type i = 0, k = 0;
					pointer tmp = this->_allocator.allocate(this->_size + (last - first) * 2);
					iterator it = this->_begin;
					while (it != position) {
						*it++;
						i++;
					}
					for (size_type j = 0; j < this->_size + (last - first); j++) {
						if (j == i) {
							while (k < last - first) {
								this->_allocator.construct(tmp + j, *first++);
								k++;
							}
							j += k;
						}
						else
							this->_allocator.construct(tmp + j, *(this->_begin + j));
					}
					for (size_type j = 0; j < this->_size; j++)
						this->_allocator.destroy(this->_begin + j);
					this->_allocator.deallocate(this->_begin);
					this->_begin = tmp;
					this->_size += last - first;
					this->_lenght = this->_size * 2;
				}

			iterator erase(iterator position) {
				size_type i = 0, k = 0;
				iterator it = this->_begin;
				pointer tmp = this->_allocator.allocate((this->_size - 1) * 2);
				while (it != position) {
					*it++;
					i++;
				}
				for (size_type j = 0; j < this->_size; j++) {
					if (j != i) {
						this->_allocator.construct(tmp + k, *(this->_begin + j));
						k++;
					}
				}
				for (size_type j = 0; j < this->_size; j++)
					this->_allocator.destroy(this->_begin + j);
				this->_allocator.deallocate(this->_begin);
				this->_begin = tmp;
				this->_size--;
				this->_lenght = this->_size * 2;
				return it;
			}

			iterator erase(iterator first, iterator last) {
				size_type i = 0, k = 0, l = 0;
				iterator it = this->_begin;
				iterator it_end = this->_begin;
				pointer tmp = this->_allocator.allocate((this->_begin - (last - first)) * 2);
				while (it != first) {
					*it++;
					i++;
				}
				while (it_end != last) {
					*it_end++;
					k++;
				}
				for (size_type j = 0; j < this->_size; j++) {
					if (j < i && j >= k) {
						this->_allocator.construct(tmp + l, *(this->_begin + j));
						l++;
					}
				}
				for (size_type j = 0; j < this->_size; j++)
					this->_allocator.destroy(this->_begin + j);
				this->_allocator.deallocate(this->_begin);
				this->_begin = tmp;
				this->_size -= (last - first);
				this->_lenght = this->_size * 2;
				return it;
			}

			void swap(vector& x) {
				allocator_type allocator = x._allocator;
				pointer tmp = x._begin;
				size_type size = x._size;
				size_type lenght = x._lenght;

				x._allocator = this->_allocator;
				x._begin = this->_begin;
				x._size = this->_size;
				x._lenght = this->_lenght;

				this->_allocator = allocator;
				this->_begin = tmp;
				this->_size = size;
				this->_lenght = lenght;
			}

			void clear() {
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.destroy(this->_begin + i);
				this->_size = 0;
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
				return (this->_allocator);
			}

			private:

				allocator_type	_allocator;
				pointer			_begin; // pointer to the first element
				size_type		_size; // nb of element in my vector
				size_type		_lenght; // total lenght of my vector
		};

		/*
		##    ##  #######  ##    ##         ##     ## ######## ##     ## ########  ######## ########     ######## ##     ## ##    ##  ######  ######## ####  #######  ##    ##     #######  ##     ## ######## ########  ##        #######     ###    ########
		###   ## ##     ## ###   ##         ###   ### ##       ###   ### ##     ## ##       ##     ##    ##       ##     ## ###   ## ##    ##    ##     ##  ##     ## ###   ##    ##     ## ##     ## ##       ##     ## ##       ##     ##   ## ##   ##     ##
		####  ## ##     ## ####  ##         #### #### ##       #### #### ##     ## ##       ##     ##    ##       ##     ## ####  ## ##          ##     ##  ##     ## ####  ##    ##     ## ##     ## ##       ##     ## ##       ##     ##  ##   ##  ##     ##
		## ## ## ##     ## ## ## ## ####### ## ### ## ######   ## ### ## ########  ######   ########     ######   ##     ## ## ## ## ##          ##     ##  ##     ## ## ## ##    ##     ## ##     ## ######   ########  ##       ##     ## ##     ## ##     ##
		##  #### ##     ## ##  ####         ##     ## ##       ##     ## ##     ## ##       ##   ##      ##       ##     ## ##  #### ##          ##     ##  ##     ## ##  ####    ##     ##  ##   ##  ##       ##   ##   ##       ##     ## ######### ##     ##
		##   ### ##     ## ##   ###         ##     ## ##       ##     ## ##     ## ##       ##    ##     ##       ##     ## ##   ### ##    ##    ##     ##  ##     ## ##   ###    ##     ##   ## ##   ##       ##    ##  ##       ##     ## ##     ## ##     ##
		##    ##  #######  ##    ##         ##     ## ######## ##     ## ########  ######## ##     ##    ##        #######  ##    ##  ######     ##    ####  #######  ##    ##     #######     ###    ######## ##     ## ########  #######  ##     ## ########
		*/

		template <class T, class Alloc>
			bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
				if (lhs.size() == rhs.size())
					return false;
				return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
			}
		template <class T, class Alloc>
			bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
				return !(lhs == rhs);
			}
		template <class T, class Alloc>
			bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
				return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
			}
		template <class T, class Alloc>
			bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
				return !(lhs < rhs);
			}
		template <class T, class Alloc>
			bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
				return (lhs < rhs);
			}
		template <class T, class Alloc>
			bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
				return !(lhs > rhs);
			}
		
		template <class T, class Alloc>
			void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
				x.swap(y);
			}

}