#pragma once

#include <iostream>

namespace ft {

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_acces_iterator_tag : public bidirectional_iterator_tag {};
	
	template <class Iterator>
	class Iterator_traits{
		typedef typename Iterator::difference_type	difference_type;
		typedef	typename Iterator::value_type		value_type;
		typedef	typename Iterator::pointer			pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	class Iterator_traits<T*> {
		typedef ptrdiff_t					difference_type;
		typedef	T							value_type;
		typedef	T*							pointer;
		typedef T&							reference;
		typedef random_acces_iterator_tag	iterator_category;
	};

	template <class T>
	class Iterator_traits<const T*> {
		typedef ptrdiff_t					difference_type;
		typedef	T							value_type;
		typedef	const T*					pointer;
		typedef const T&					reference;
		typedef random_acces_iterator_tag	iterator_category;
	};


	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T			value_type;
		typedef Distance	distance_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	template <class Iterator>
	class reverse_iterator {
		
		public:
		
			typedef Iterator												iterator_type;
			typedef typename Iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename Iterator_traits<Iterator>::value_type			value_type;
			typedef typename Iterator_traits<Iterator>::difference_type		difference_type;
			typedef	typename Iterator_traits<Iterator>::pointer				pointer;
			typedef typename Iterator_traits<Iterator>::reference			reference;


		// Member functions

			// Constructors

			reverse_iterator(): _it() {};
			explicit reverse_iterator (iterator_type it): _it(it) {};
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it): _it(rev_it.base()) {};

			// Base

			iterator_type base() const {
				return this->_it;
			}

			// Overload operators
				// Dereference operator
				
				reference operator*() const {
					iterator_type copy = this->_it;
					return (*--copy);
				}

				pointer operator->() const {
					return &(operator*());
				}

				// Addition operator

				template <class Iterator>
					reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
						return (reverse_iterator<Iterator>(rev_it.base() - n));	
					}


		protected:

			iterator_type	_it;

	};

}