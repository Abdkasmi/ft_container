#pragma once

#include <iostream>
#include <memory>

namespace ft {

		template <class T, class Alloc = allocator<T> > 
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
				typedef Allocator										allocator_type;
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


		};

};