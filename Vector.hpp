#pragma once

#include <iostream>
#include <memory>
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
				
				typedef T												value_type;
				typedef Alloc											allocator_type;
				typedef typename allocator_type::reference				reference;
				typedef typename allocator_type::const_reference		const_reference;
				typedef typename allocator_type::pointer 				pointer;
				typedef typename allocator_type::const_pointer 			const_pointer;
				typedef typename ft::random_access_iterator<T>			iterator;
				typedef typename ft::random_access_iterator<const T>	const_iterator;
				typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
				typedef typename ft::reverse_iterator<const iterator>	const_reverse_iterator;
				typedef std::ptrdiff_t									difference_type;
				typedef std::size_t										size_type;
						
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
				vector(InputIterator first, InputIterator last, const_allocator_type& alloc = allocator_type()): _allocator(alloc), _size(last - first), _lenght((last - first) * 2) {
					this->_begin = this->_allocator.allocate(this->_lenght, 0);
					for (size_type i = 0; i < this->_size; i++)
						this->_allocator.construct(this->_begin + i, *first++);
				}
			vector(const vector& x): _allocator(x._allocator), _size(x._size), _lenght(x._lenght) {
				this->_begin = this->_allocator.allocate(this->_lenght, 0);
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.construct(this->_begin + i, *(x._begin + i));
			}

			// Destrcuctor

			~vector() {
				for (size_type i = 0; i < this->_size; i++)
					this->_allocator.detsroy(this->_begin + i);
				this->_allocator.dealocate(this->_begin, this->_lenght);
			}

			// Overload operator=

			vector& operator= (const vector& x) {
				// come back when have code vector::assign
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
				return this->_lenght;
			}

			void resize(size_type n, value_type val = value_type()) {
				if (n < this->_size) {
					for (size_type i = this->_size; i > n; i--)
						this->_allocator.destroy(this->_begin + i);
					this->_size = n;
				}
				else if (n > this->_size) {
					if (n + this->_size <= this->_lenght) {
						for (size_type i = this->_size; i < this->_size + n; i++) {
							this->_allocator.allocator.construct(this->_begin + i, val);
						}
					}
					else if (n + this->_size > this->_lenght) {
						size_type tmp = this->_lenght;
						this->_lenght *= 2;
						this->_begin += this->_allocator.allocate(this->_lenght - tmp, 0);
						for (size_type i = this->_size; i < this->_size + n; i++) {
							this->_allocator.allocator.construct(this->_begin + i, val);
						}
					}
				}
			}

			size_type capacity() const {
				return this->_lenght;
			}

			bool empty() {
				return !this->_size;
			}

			void reserve(type_type n) {
				if (n > this->_lenght) {
					pointer tmp = this->_allocator.allocate(n, 0);
					for (size_type i = 0; i < n; i++)
						this->_allocator.construct(tmp + i, this->_begin + i);
					for (size_type i = 0; i < this->_size; i++)
						this->_allocator.detsroy(this->_begin + i);
					this->_allocator.dealocate(this->_begin, this->_lenght);
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
				return *this->_begin + n;
			}

			const_reference operator[](size_type n) const {
				return *this->_begin + n;
			}

			reference at(size_type n) {
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

			const_reference back() {
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
					this->_allocator.dealocate(this->_begin, this->_lenght);
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
					resize(this->_size + 1, val);
			}

			void	pop_back(){
				if (this->_size > 0) {	
					this->_allocator.destroy(this->_begin + (this->_size - 1));
					this->_size--;
				}
			}

			iterator insert (iterator position, const value_type& val) {

			}

			void insert(iteraor position, size_type n, const value_type& val) {

			}

			template <class InputIterator>
				void insert(iterator position, InputIterator first, InputIterator last) {

				}

			// ReCheck toutes les Exceotion safety a la fin

			private:

				allocator_type	_allocator;
				pointer			_begin; // pointer to the first element
				size_type		_size; // nb of element in my vector
				size_type		_lenght; // total lenght of my vector


		};

}