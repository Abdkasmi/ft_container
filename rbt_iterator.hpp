#pragma once

#include <iostream> 
#include "rb_tree.hpp"
#include "Iterator.hpp"
#include <functional>

namespace ft {

    template<class Key, class T, class Compare = std::less<Key> >
    class RbtIterator {//: ft::iterator<ft::bidirectional_iterator_tag, Compare>

        public :

            typedef Key                                                         key_type;
			typedef typename ft::bidirectional_iterator_tag	                    iterator_category; might be std instead of ft
			typedef typename Iterator_traits<T>::value_type			            value_type;
			typedef typename Iterator_traits<T>::difference_type		        difference_type;
			typedef	typename Iterator_traits<T>::pointer				        pointer;
			typedef typename Iterator_traits<T>::reference			            reference;

        
            
            
        
        
        private :

            iterator_category _it;

    };

}