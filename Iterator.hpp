#pragma once

#include <iostream>

namespace ft {

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <class T>
	class Iterator_traits{
	public:
		typedef typename T::difference_type		difference_type;
		typedef	typename T::value_type			value_type;
		typedef	typename T::pointer				pointer;
		typedef typename T::reference			reference;
		typedef typename T::iterator_category	iterator_category;
	};

	template <class T>
	class Iterator_traits<T*> {
	public:
		typedef ptrdiff_t					difference_type;
		typedef	T							value_type;
		typedef	T*							pointer;
		typedef T&							reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template <class T>
	class Iterator_traits<const T*> {
	public:
		typedef ptrdiff_t					difference_type;
		typedef	T							value_type;
		typedef	const T*					pointer;
		typedef const T&					reference;
		typedef random_access_iterator_tag	iterator_category;
	};


	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator {
	public:
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};


			// Reverse Iterator


	template <class Iterator>
	class reverse_iterator {
		
		public:
		
			typedef Iterator								iterator_type;
			typedef typename Iterator::iterator_category	iterator_category;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::difference_type		difference_type;
			typedef	typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;


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
						return (*(*this + n));
				}

				// Addition operator

				reverse_iterator	 operator+(difference_type n) const {
					return (reverse_iterator(this->_it - n));
				}

				// Substraction operator

				reverse_iterator operator-(difference_type n) const {
					return (reverse_iterator(this->_it + n));
				}
				
				// incrementation operator (pre and post ++)

				reverse_iterator	&operator++() { // pre
					--this->_it;
					return *this;
				}

				reverse_iterator	operator++(int) { // post
					reverse_iterator tmp(*this);
					--this->_it;
					return tmp;
				}

				// Decrementation iterator (pre and post --)

				reverse_iterator	&operator--() { // pre
					++this->_it;
					return *this;
				}

				reverse_iterator	operator--(int) { //post
					reverse_iterator tmp(*this);
					operator--();
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

		protected:

			iterator_type	_it;

	};

	// Non-member functions

	// Relational operators (==, !=, <, <=, >, >=)

	template <class Iterator_, class Iter>
		bool operator==(const reverse_iterator<Iterator_>& lhs, const reverse_iterator<Iter>& rhs) {
			return (rhs.base() == lhs.base());
		}

	template <class Iterator_, class Iter>
		bool operator!=(const reverse_iterator<Iterator_>& lhs, const reverse_iterator<Iter>& rhs) {
			return (rhs.base() != lhs.base());
		}
	
	template <class Iterator_, class Iter>
		bool operator<(const reverse_iterator<Iterator_>& lhs, const reverse_iterator<Iter>& rhs) {
			return (rhs.base() < lhs.base());
		}

	template <class Iterator_, class Iter>
		bool operator<=(const reverse_iterator<Iterator_>& lhs, const reverse_iterator<Iter>& rhs) {
			return (rhs.base() <= lhs.base());
		}

	template <class Iterator_, class Iter>
		bool operator>(const reverse_iterator<Iterator_>& lhs, const reverse_iterator<Iter>& rhs) {
			return (rhs.base() > lhs.base());
		}

	template <class Iterator_, class Iter>
		bool operator>=(const reverse_iterator<Iterator_>& lhs, const reverse_iterator<Iter>& rhs) {
			return (rhs.base() >= lhs.base());
		}

	// Addition operator (template function)

	template <class Iterator_>
		reverse_iterator<Iterator_> operator+(typename reverse_iterator<Iterator_>::difference_type n, const reverse_iterator<Iterator_>& rev_it) {
			return (reverse_iterator<Iterator_>(rev_it.base() - n));	
		}

	// Substraction operator (template function)

	template <class Iterator_>
		typename reverse_iterator<Iterator_>::difference_type operator-(const reverse_iterator<Iterator_>& lhs, const reverse_iterator<Iterator_>& rhs) {
			return (lhs.base() - rhs.base());
		}

	template<typename _IteratorL, typename _IteratorR>
		typename reverse_iterator<_IteratorL>::difference_type	operator-(const reverse_iterator<_IteratorL> &rhs, const reverse_iterator<_IteratorR> &lhs) { 
			return lhs.base() - rhs.base();
		}


	//	Random Access Iterator


	template<typename T>
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T> {

		public:

			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;

		protected:

			pointer	ptr;

		public:

			// default constructor

			random_access_iterator(): ptr(NULL) {}

			random_access_iterator(pointer ptrr): ptr(ptrr) {}

			// copy constructor

			random_access_iterator(random_access_iterator const & x): ptr(x.ptr) {}

			// destructor

			~random_access_iterator() {}

			// operator=

			random_access_iterator& operator=(random_access_iterator const &rhs) {
				if (this != &rhs)
					this->ptr = rhs.ptr;
				return *this;
			}

			operator	random_access_iterator<const T>(void) const { 
				return (this->ptr);
			}

			// base()

			pointer base() const {
				return this->ptr;
			}

			// overload operators

			reference operator*() const {
				return *(this->ptr);
			}

			pointer operator->() const {
				return &(operator*());
			}

			reference operator[] (difference_type n) const {
				return this->ptr[n];
			}
			
			random_access_iterator &operator++() {
				++this->ptr;

				return *this;
			}

			random_access_iterator operator++(int) {
				random_access_iterator tmp(*this);
				operator++();
				return tmp;
			}

			random_access_iterator& operator--() {
				--this->ptr;
				return *this;
			}

			random_access_iterator operator--(int) {
				random_access_iterator tmp(*this);
				operator--();
				return tmp;
			}

			random_access_iterator operator+(difference_type n) const {
				return this->ptr + n;
			}

			random_access_iterator operator-(difference_type n) const {
				return this->ptr - n;
			}

			random_access_iterator &operator+=(difference_type n) {
				this->ptr += n;
				return *this;
			}

			random_access_iterator &operator-=(difference_type n) {
				this->ptr -= n;
				return *this;
			}
	};

	// relational operator 

	template < typename IteratorL, typename IteratorR >
		bool operator==(random_access_iterator<IteratorL> const &lhs, random_access_iterator<IteratorR> const &rhs)
		{
			return (lhs.base() == rhs.base());
		}

	template < typename IteratorL, typename IteratorR >
		bool operator!=(random_access_iterator<IteratorL> const &lhs, random_access_iterator<IteratorR> const &rhs)
		{
			return (!(lhs.base() == rhs.base()));
		}

	template < typename IteratorL, typename IteratorR >
		bool operator<(random_access_iterator<IteratorL> const &lhs, random_access_iterator<IteratorR> const &rhs)
		{
			return (lhs.base() < rhs.base());
		}

	template < typename IteratorL, typename IteratorR >
		bool operator>(random_access_iterator<IteratorL> const &lhs, random_access_iterator<IteratorR> const &rhs)
		{
			return (rhs.base() < lhs.base());
		}

	template < typename IteratorL, typename IteratorR >
		bool operator<=(random_access_iterator<IteratorL> const &lhs, random_access_iterator<IteratorR> const &rhs)
		{
			return (!(rhs.base() < lhs.base()));
		}

	template < typename IteratorL, typename IteratorR >
		bool operator>=(random_access_iterator<IteratorL> const &lhs, random_access_iterator<IteratorR> const &rhs)
		{
			return (!(lhs.base() < rhs.base()));
		}

	// arithmetic operators

	template < typename Iterator >
		random_access_iterator<Iterator> operator+(typename random_access_iterator<Iterator>::difference_type n, random_access_iterator<Iterator> const &rhs) {
			return (random_access_iterator<Iterator>(rhs.base() + n));
		}

	template < typename IteratorL, typename IteratorR >
		typename random_access_iterator<IteratorL>::difference_type operator-(random_access_iterator<IteratorL> const &lhs, random_access_iterator<IteratorR> const &rhs) {
			return (lhs.base() - rhs.base());
		}

	template <class Iterator>
		random_access_iterator<Iterator>	operator-(typename random_access_iterator<Iterator>::difference_type n, random_access_iterator<Iterator> const &x) {
			return (random_access_iterator<Iterator>(x.base() - n));
		}

}