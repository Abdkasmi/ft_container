#pragma once

#include <iostream>

namespace ft {

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	//make random access iterator goofy dev;
	
	template <class T>
	class Iterator_traits{
		typedef typename T::difference_type		difference_type;
		typedef	typename T::value_type			value_type;
		typedef	typename T::pointer				pointer;
		typedef typename T::reference			reference;
		typedef typename T::iterator_category	iterator_category;
	};

	template <class T>
	class Iterator_traits<T*> {
		typedef ptrdiff_t					difference_type;
		typedef	T							value_type;
		typedef	T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template <class T>
	class Iterator_traits<const T*> {
		typedef ptrdiff_t					difference_type;
		typedef	T							value_type;
		typedef	const T*					pointer;
		typedef const T&					reference;
		typedef random_access_iterator_tag	iterator_category;
	};


	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T			value_type;
		typedef Distance	distance_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};


			// Reverse Iterator


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

				operator reverse_iterator<const Iterator>() const
				{
					return this->current;
				}

				// Dereference operator
				
				reference operator*() const {
					iterator_type copy = this->_it;
					return (*--copy);
				}

				pointer operator->() const {
					return &(operator*());
				}

				reference operator[] (difference_type n) const {	
						return *this->_it[n];
				}

				// Addition operator

				reverse_iterator	 operator+(difference_type n) const {
					return (reverse_iterator(this->_it - n));
				}

				// Substraction operator

				reverse_iterator& operator-(difference_type n) const {
					return (reverse_iterator(this->_it + n));
				}
				
				// incrementation operator (pre and post ++)

				reverse_iterator	&operator++() { // pre
					--this->_it;
					return *this;
				}

				reverse_iterator	&operator++(int) { // post
					reverse_iterator tmp = *this;
					++(*this);
					return tmp;
				}

				// Decrementation iterator (pre and post --)

				reverse_iterator	&operator--() { // pre
					++this->_it;
					return *this;
				}

				reverse_iterator	operator--(int) { //post
					reverse_iterator tmp = *this;
					--(*this);
					return tmp;					
				}

				// Advance and retrocede iterators

				reverse_iterator& operator+=(difference_type n) {
					this->_it -= n;
					return *this;
				}

				reverse_iterator& operator-=(difference_type n) {
					this->_it += n;
					return *this;
				}
				
		// Non-member functions

			// Relational operators (==, !=, <, <=, >, >=)

			template <class Iterator_>
				friend bool operator==(const reverse_iterator<Iterator_>& lhs, const reverse_iterator<Iterator_>& rhs) {
					return (lhs.base() == rhs.base());
				}

			template <class Iterator_>
				friend bool operator!=(const reverse_iterator<Iterator_>& lhs, const reverse_iterator<Iterator_>& rhs) {
					return (lhs.base() != rhs.base());
				}
			
			template <class Iterator_>
				friend bool operator<(const reverse_iterator<Iterator_>& lhs, const reverse_iterator<Iterator_>& rhs) {
					return (lhs.base() < rhs.base());
				}

			template <class Iterator_>
				friend bool operator<=(const reverse_iterator<Iterator_>& lhs, const reverse_iterator<Iterator_>& rhs) {
					return (lhs.base() <= rhs.bsae());
				}

			template <class Iterator_>
				friend bool operator>(const reverse_iterator<Iterator_>& lhs, const reverse_iterator<Iterator_>& rhs) {
					return (lhs.base() > rhs.base());
				}

			template <class Iterator_>
				friend bool operator>=(const reverse_iterator<Iterator_>& lhs, const reverse_iterator<Iterator_>& rhs) {
					return (lhs.base() >= rhs.base());
				}

			// Addition operator (template function)

			template <class Iterator_>
				friend reverse_iterator<Iterator_> operator+(typename reverse_iterator<Iterator_>::difference_type n, const reverse_iterator<Iterator_>& rev_it) {
					return (reverse_iterator<Iterator_>(rev_it.base() - n));	
				}

			// Substraction operator (template function)

			template <class Iterator_>
				friend typename reverse_iterator<Iterator_>::difference_type operator-(const reverse_iterator<Iterator_>& lhs, const reverse_iterator<Iterator_>& rhs) {
					return (reverse_iterator<Iterator_>(lhs.base() - rhs.base()));
					}

		protected:

			iterator_type	_it;

	};

		// Random Access Iterator


	// template<typename T>
	// class random_access_iterator {

	// };


}