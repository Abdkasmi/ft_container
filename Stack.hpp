#pragma once

#include <iostream>
#include "vector.hpp"
#include "Utils.hpp"

namespace ft {

	template <class T, class Container = ft::vector<T> >
	class stack {
		
		public:

		/*
		##     ## ######## ##     ## ########  ######## ########     ######## ##    ## ########  ########
		###   ### ##       ###   ### ##     ## ##       ##     ##       ##     ##  ##  ##     ## ##
		#### #### ##       #### #### ##     ## ##       ##     ##       ##      ####   ##     ## ##
		## ### ## ######   ## ### ## ########  ######   ########        ##       ##    ########  ######
		##     ## ##       ##     ## ##     ## ##       ##   ##         ##       ##    ##        ##
		##     ## ##       ##     ## ##     ## ##       ##    ##        ##       ##    ##        ##
		##     ## ######## ##     ## ########  ######## ##     ##       ##       ##    ##        ########
		*/

			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		protected:

			container_type _container;

		/*
		##     ## ######## ##     ## ########  ######## ########     ######## ##     ## ##    ##  ######  ######## ####  #######  ##    ##  ######
		###   ### ##       ###   ### ##     ## ##       ##     ##    ##       ##     ## ###   ## ##    ##    ##     ##  ##     ## ###   ## ##    ##
		#### #### ##       #### #### ##     ## ##       ##     ##    ##       ##     ## ####  ## ##          ##     ##  ##     ## ####  ## ##
		## ### ## ######   ## ### ## ########  ######   ########     ######   ##     ## ## ## ## ##          ##     ##  ##     ## ## ## ##  ######
		##     ## ##       ##     ## ##     ## ##       ##   ##      ##       ##     ## ##  #### ##          ##     ##  ##     ## ##  ####       ##
		##     ## ##       ##     ## ##     ## ##       ##    ##     ##       ##     ## ##   ### ##    ##    ##     ##  ##     ## ##   ### ##    ##
		##     ## ######## ##     ## ########  ######## ##     ##    ##        #######  ##    ##  ######     ##    ####  #######  ##    ##  ######
		*/

		public:

			// Constructor

			explicit stack(const container_type& ctnr = container_type()): _container(ctnr) {};

			// Empty

			bool empty() const {
				return (this->_container.empty());
			}

			// Size

			size_type size() const {
				return this->_container.size();
			}

			// Top

			value_type& top() {
				return this->_container.back();
			}

			const value_type& top() const {
				return this->_container.back();
			}

			// Push

			void push(const value_type& val) {
				this->_container.push_back(val);
			}

			// Pop

			void pop() {
				this->_container.pop_back();
			}

			template <class T2, class Container2>
  			friend bool operator== (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);

			template <class T2, class Container2>
  			friend bool operator!= (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);

			template <class T2, class Container2>
  			friend bool operator< (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);

			template <class T2, class Container2>
  			friend bool operator<= (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);
	
			template <class T2, class Container2>
  			friend bool operator> (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);
			  	
			template <class T2, class Container2>
  			friend bool operator>= (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);

	};

			/*
			##    ##  #######  ##    ##    ##     ## ######## ##     ## ########  ######## ########     ######## ##     ## ##    ##  ######  ######## ####  #######  ##    ##     #######  ##     ## ######## ########  ##        #######     ###    ########   ######
			###   ## ##     ## ###   ##    ###   ### ##       ###   ### ##     ## ##       ##     ##    ##       ##     ## ###   ## ##    ##    ##     ##  ##     ## ###   ##    ##     ## ##     ## ##       ##     ## ##       ##     ##   ## ##   ##     ## ##    ##
			####  ## ##     ## ####  ##    #### #### ##       #### #### ##     ## ##       ##     ##    ##       ##     ## ####  ## ##          ##     ##  ##     ## ####  ##    ##     ## ##     ## ##       ##     ## ##       ##     ##  ##   ##  ##     ## ##
			## ## ## ##     ## ## ## ##    ## ### ## ######   ## ### ## ########  ######   ########     ######   ##     ## ## ## ## ##          ##     ##  ##     ## ## ## ##    ##     ## ##     ## ######   ########  ##       ##     ## ##     ## ##     ##  ######
			##  #### ##     ## ##  ####    ##     ## ##       ##     ## ##     ## ##       ##   ##      ##       ##     ## ##  #### ##          ##     ##  ##     ## ##  ####    ##     ##  ##   ##  ##       ##   ##   ##       ##     ## ######### ##     ##       ##
			##   ### ##     ## ##   ###    ##     ## ##       ##     ## ##     ## ##       ##    ##     ##       ##     ## ##   ### ##    ##    ##     ##  ##     ## ##   ###    ##     ##   ## ##   ##       ##    ##  ##       ##     ## ##     ## ##     ## ##    ##
			##    ##  #######  ##    ##    ##     ## ######## ##     ## ########  ######## ##     ##    ##        #######  ##    ##  ######     ##    ####  #######  ##    ##     #######     ###    ######## ##     ## ########  #######  ##     ## ########   ######
			*/

			// Relationnal operators

			template <class T, class Container>
 				bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
					return (lhs._container == rhs._container);
				}
			template <class T, class Container>
 				bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
					return (lhs._container != rhs._container);
				}
			template <class T, class Container>
				bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
					return lhs._container < rhs._container;
				}
			template <class T, class Container>
				bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
					return lhs._container <= rhs._container;
				}
			template <class T, class Container>
				bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
					return lhs._container > rhs._container;
				}
			template <class T, class Container>
				bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
					return lhs._container >= rhs._container;
				}

}