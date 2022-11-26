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
		typedef Iterator::difference_type	difference_type;
		typedef	Iterator::value_type		value_type;
		typedef	Iterator::pointer			pointer;
		typedef Iterator::reference			reference;
		typedef Iterator::iterator_category	iterator_category;
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
		
			typedef Iterator							iterator_type;
			typedef Iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef Iterator_traits<Iterator>::value_type			value_type;
			typedef Iterator_traits<Iterator>::difference_type		difference_type;
			typedef	Iterator_traits<Iterator>::pointer				pointer;
			typedef Iterator_traits<Iterator>::reference			reference;


			reverse_iterator() {};
			explicit reverse_iterator (iterator_type it) {};
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) {};


	};

}