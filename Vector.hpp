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
				for (size_type i = 0; i < this->_size, i++)
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

			}

			reverse_iterator rend() {

			}

			const_reverse_iterator rbegin() {

			}

			const_reverse_iterator rend() {
				
			}


			private:

				allocator_type	_allocator;
				pointer			_begin; // pointer to the first element
				size_type		_size; // nb of element in my vector
				size_type		_lenght; // total lenght of my vector


		};

}