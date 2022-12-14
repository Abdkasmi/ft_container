#pragma once

#include <iostream>

namespace ft {
    
    /*
    ########  #######  ##     ##    ###    ##
    ##       ##     ## ##     ##   ## ##   ##
    ##       ##     ## ##     ##  ##   ##  ##
    ######   ##     ## ##     ## ##     ## ##
    ##       ##  ## ## ##     ## ######### ##
    ##       ##    ##  ##     ## ##     ## ##
    ########  ##### ##  #######  ##     ## ########
    */

    template <class InputIterator1, class InputIterator2>
        bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 ) {
            while (first1!=last1) {
                if (!(*first1 == *first2))
                    return false;
            ++first1; ++first2;
            }
            return true;
        }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
        bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
            while (first1!=last1) {
                if (!pred(*first1,*first2))
                    return false;
                ++first1; ++first2;
            }
            return true;
        }

    /*
    ##       ######## ##     ## ####  ######   #######   ######   ########     ###    ########  ##     ## ####  ######     ###    ##           ######   #######  ##     ## ########     ###    ########  ########
    ##       ##        ##   ##   ##  ##    ## ##     ## ##    ##  ##     ##   ## ##   ##     ## ##     ##  ##  ##    ##   ## ##   ##          ##    ## ##     ## ###   ### ##     ##   ## ##   ##     ## ##
    ##       ##         ## ##    ##  ##       ##     ## ##        ##     ##  ##   ##  ##     ## ##     ##  ##  ##        ##   ##  ##          ##       ##     ## #### #### ##     ##  ##   ##  ##     ## ##
    ##       ######      ###     ##  ##       ##     ## ##   #### ########  ##     ## ########  #########  ##  ##       ##     ## ##          ##       ##     ## ## ### ## ########  ##     ## ########  ######
    ##       ##         ## ##    ##  ##       ##     ## ##    ##  ##   ##   ######### ##        ##     ##  ##  ##       ######### ##          ##       ##     ## ##     ## ##        ######### ##   ##   ##
    ##       ##        ##   ##   ##  ##    ## ##     ## ##    ##  ##    ##  ##     ## ##        ##     ##  ##  ##    ## ##     ## ##          ##    ## ##     ## ##     ## ##        ##     ## ##    ##  ##
    ######## ######## ##     ## ####  ######   #######   ######   ##     ## ##     ## ##        ##     ## ####  ######  ##     ## ########     ######   #######  ##     ## ##        ##     ## ##     ## ########
    */

    template <class InputIterator1, class InputIterator2>
        bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
            while (first1!=last1) {
                if (first2==last2 || *first2<*first1) return false;
            else if (*first1<*first2) return true;
                ++first1; ++first2;
            }
        return (first2!=last2);
        }

    /*
    ##     ##    ###    ##       ##     ## ########          ######   #######  ##     ## ########
    ##     ##   ## ##   ##       ##     ## ##               ##    ## ##     ## ###   ### ##     ##
    ##     ##  ##   ##  ##       ##     ## ##               ##       ##     ## #### #### ##     ##
    ##     ## ##     ## ##       ##     ## ######           ##       ##     ## ## ### ## ########
     ##   ##  ######### ##       ##     ## ##               ##       ##     ## ##     ## ##
      ## ##   ##     ## ##       ##     ## ##               ##    ## ##     ## ##     ## ##
       ###    ##     ## ########  #######  ######## #######  ######   #######  ##     ## ##
    */

    // template <class Key, class T, class Compare, class Alloc>
    // class map : public binary_function<std::false,value_type,bool> {
    //     friend class map;
    //     protected:
    //     Compare comp;
    //     value_compare (Compare c) : comp(c) {}
    //     public:
    //     typedef bool result_type;
    //     typedef value_type first_argument_type;
    //     typedef value_type second_argument_type;
    //     bool operator() (const value_type& x, const value_type& y) const
    //     {
    //         return comp(x.first, y.first);
    //     }
    // };

    /*
    ######## ##    ##    ###    ########  ##       ########    #### ########
    ##       ###   ##   ## ##   ##     ## ##       ##           ##  ##
    ##       ####  ##  ##   ##  ##     ## ##       ##           ##  ##
    ######   ## ## ## ##     ## ########  ##       ######       ##  ######
    ##       ##  #### ######### ##     ## ##       ##           ##  ##
    ##       ##   ### ##     ## ##     ## ##       ##           ##  ##
    ######## ##    ## ##     ## ########  ######## ########    #### ##
    */

    template <bool Cond, class T = void>
        struct enable_if {};
    template<class T> 
        struct enable_if<true, T> { typedef T type; };

    /*
    ####  ######     #### ##    ## ######## ########  ######   ########     ###    ##
     ##  ##    ##     ##  ###   ##    ##    ##       ##    ##  ##     ##   ## ##   ##
     ##  ##           ##  ####  ##    ##    ##       ##        ##     ##  ##   ##  ##
     ##   ######      ##  ## ## ##    ##    ######   ##   #### ########  ##     ## ##
     ##        ##     ##  ##  ####    ##    ##       ##    ##  ##   ##   ######### ##
     ##  ##    ##     ##  ##   ###    ##    ##       ##    ##  ##    ##  ##     ## ##
    ####  ######     #### ##    ##    ##    ########  ######   ##     ## ##     ## ########
    */

    template <class T, T v>
        struct integral_constant {
            static const T value = v;
            typedef T value_type;
            typedef integral_constant<T,v> type;
        };
    
    typedef integral_constant<bool,true> true_type;
    typedef integral_constant<bool,false> false_type;
    
    template <typename>
        struct is_integral : public false_type{};

    template <>
        struct is_integral<bool> : public true_type{};
    template <>
        struct is_integral<char> : public true_type{};
    template <>
        struct is_integral<char16_t> : public true_type{};
    template <>
        struct is_integral<char32_t> : public true_type{};
    template <>
        struct is_integral<wchar_t> : public true_type{};
    template <>
        struct is_integral<signed char> : public true_type{}; 
    template <>
        struct is_integral<short int> : public true_type{};
    template <>
        struct is_integral<int> : public true_type{};
    template <>
        struct is_integral<long int> : public true_type{};
    template <>
        struct is_integral<long long int> : public true_type{};
    template <>
        struct is_integral<unsigned char> : public true_type{};
    template <>
        struct is_integral<unsigned short int> : public true_type{};
    template <>
        struct is_integral<unsigned int> : public true_type{};
    template <>
        struct is_integral<unsigned long int> : public true_type{};
    template <>
        struct is_integral<unsigned long long int> : public true_type{};
}