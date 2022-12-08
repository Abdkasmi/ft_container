#pragma once

#include <iostream>
#include "Vector.hpp"
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

		/*
		##     ## ######## ##     ## ########  ######## ########     ######## ##     ## ##    ##  ######  ######## ####  #######  ##    ##  ######
		###   ### ##       ###   ### ##     ## ##       ##     ##    ##       ##     ## ###   ## ##    ##    ##     ##  ##     ## ###   ## ##    ##
		#### #### ##       #### #### ##     ## ##       ##     ##    ##       ##     ## ####  ## ##          ##     ##  ##     ## ####  ## ##
		## ### ## ######   ## ### ## ########  ######   ########     ######   ##     ## ## ## ## ##          ##     ##  ##     ## ## ## ##  ######
		##     ## ##       ##     ## ##     ## ##       ##   ##      ##       ##     ## ##  #### ##          ##     ##  ##     ## ##  ####       ##
		##     ## ##       ##     ## ##     ## ##       ##    ##     ##       ##     ## ##   ### ##    ##    ##     ##  ##     ## ##   ### ##    ##
		##     ## ######## ##     ## ########  ######## ##     ##    ##        #######  ##    ##  ######     ##    ####  #######  ##    ##  ######
		*/

			// Constructor

			explicit stack(const conatiner_type& ctnr = container_type()): _container(ctnr) {};

			// Empty

			bool empty() const {
				return _container.empty();
			}

			// Size

			size_type size() const {
				return _constainer.size();
			}

			// Top

			value_type& top() {
				return _container.back();
			}

			const value_type& top const() {
				return _container.back();
			}

			// Push

			void push(const value_type& val) {
				this->_container.push_back(val);
			}

			// Pop

			void pop() {
				this->_container.pop_back();
			}

		protected:

			container_type _container;

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
					return (lhs._container == rhs._ccontainer);
				}
			template <class T, class Container>
 				bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
					return (lhs._container != rhs._ccontainer);
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