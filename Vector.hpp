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
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _allocator(alloc), _begin(val[0]), _size(n) {
				for (int i = 0; i < n; i++)
					_allocator.alloc(val[i]);
			};
			template <class InputIterator>
				vector(InputIterator first, InputIterator last, const_allocator_type& alloc = allocator_type()): _allocator(alloc), _begin(first), _size(last - first), _lenght(last - first) {
					
				};
			vector(const vector& c) {};

			private:

				allocator_type	_allocator;
				pointer			_begin;
				size_type		_size; // nb of element in my vector
				size_type		_lenght; // total lenght of my vector


		};

}