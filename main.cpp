#include <iostream>
 #include <string>

 #if 0 //CREATE A REAL STL EXAMPLE
 	#include <map>
 	#include <stack>
 	#include <vector>
 	namespace ft = std;
 #else
 	#include "map.hpp"
 	#include "stack.hpp"
 	#include "vector.hpp"
 #endif

// #include <stdlib.h>

// #define T1 int
// #define T2 std::string
// typedef ft::map<T1, T2>::value_type T3;
// typedef ft::map<T1, T2>::iterator iterator;

// static int iter = 0;

// template <typename MAP, typename U>
// void	ft_insert(MAP &mp, U param)
// {
// 	ft::pair<iterator, bool> tmp;

// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	tmp = mp.insert(param);
// 	//std::cout << "insert return: " << printPair(tmp.first);
// 	std::cout << "Created new node: " << tmp.second << std::endl;
// 	//printSize(mp);
// }

// template <typename MAP, typename U, typename V>
// void	ft_insert(MAP &mp, U param, V param2)
// {
// 	iterator tmp;

// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	tmp = mp.insert(param, param2);
// 	//std::cout << "insert return: " << printPair(tmp);
// 	//printSize(mp);
// }

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
    o << "key: " << iterator->first << " | value: " << iterator->second;
    if (nl)
        o << std::endl;
    return ("");
}

 int		main(void)
 {
     ft::map<int, std::string> mp;
     ft::map<int, std::string>::iterator it;
     ft::pair<ft::map<int, std::string>::iterator, bool> tmp;
     ft::pair<ft::map<int, std::string>::iterator, bool> tmp2;
     ft::pair<ft::map<int, std::string>::iterator, bool> tmp3;
     ft::pair<ft::map<int, std::string>::iterator, bool> tmp4;

     tmp = mp.insert(ft::pair<int, std::string>(1, "salut"));
     tmp2 = mp.insert(ft::pair<int, std::string>(7, "bonjour"));
     tmp3 = mp.insert(ft::pair<int, std::string>(5, "pour"));
     tmp4 = mp.insert(ft::pair<int, std::string>(6, "lolo"));

     std::cout << tmp.second << "value : " << printPair(tmp.first);
     std::cout << tmp2.second << "value : " << printPair(tmp2.first);
     std::cout << tmp3.second << "value : " << printPair(tmp3.first);
     std::cout << tmp4.second << "value : " << printPair(tmp4.first);;

 	return (0);
 }


// int main() {
// 	std::cout << "////////-- Vector -- ////////" << std::endl;
// 	std::cout << std::endl;
// 	ft::vector<int> vector; // empty vector
// 	ft::vector<int> vector2(5, 100); // vector of 5 ints of value 100
// 	ft::vector<int> vector3(vector2.begin(), vector2.end()); // same as 2 but through iteration
// 	ft::vector<int> vector4(vector3); // copy of 3

// 	std::cout << "empty vector : " << vector.empty() << std::endl;
// 	for (size_t i = 0; i < vector2.size(); i++)
// 		std::cout<< "vector2 through index : " << vector2[i] << " | ";
// 	std::cout << std::endl;
// 	std::cout << std::endl;
// 	ft::vector<int>::iterator it(vector3.begin());
// 	while (it != vector3.end()) {
// 		std::cout << "vector3 through iterator : " << *it++ << " | ";
// 	}
// 	std::cout << std::endl;
// 	std::cout << std::endl;
// 	it = vector4.begin();
// 	while (it != vector4.end()) {
// 		std::cout << "vector4 through iterator : " << *it++ << " | ";
// 	}
// 	std::cout << std::endl;
// 	std::cout << std::endl;
// 	ft::vector<int> vect(5, 89);
// 	vector4.assign(vect.begin(), vect.end());
// 	vector4.push_back(13);
// 	it = vector4.begin();
// 	while (it != vector4.end()) {
// 		std::cout << "vector4 after push_back : " << *it++ << " | ";
// 	}
// 	std::cout << std::endl;
// 	std::cout << std::endl;
// 	vector4.pop_back();
// 	it = vector4.begin();
// 	while (it != vector4.end()) {
// 		std::cout << "vector after pop_back : " << *it++ << " | ";
// 	}
// 	std::cout << std::endl;
// 	std::cout << std::endl;
// 	vector.push_back(56);
// 	if (vector.empty())
// 		std::cout << "Vector1 is empty" << std::endl;
// 	else
// 		std::cout << "Vector1 is not empty" << std::endl;
// 	std::cout << "////////-- Map -- ////////" << std::endl;
// 	std::cout << std::endl;
// 	ft::map<int, std::string> first;
// 	first.insert(ft::pair<int, std::string>(1, "moi"));
// 	//first.insert(ft::pair<int, std::string>(2, "moi"));
// 	//first.insert(ft::pair<int, std::string>(3, "moi"));
// 	//first.insert(ft::pair<int, std::string>(4, "moi"));
// 	//ft::map<int, std::string>::iterator it_map = first.begin();
// 	//std::cout << it_map << std::endl;
// 	return 0;
// }

//#include "vector.hpp"
//#include "map.hpp"
//#include "stack.hpp"
//
//#include <vector>
//#include <map>
//#include <stack>
//#include <list>

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define PINK "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

//#ifndef NAMESPACE
//# define NAMESPACE ft
//#endif
//
//
//template <typename T>
//class foo {
//	public:
//		typedef T	value_type;
//
//		foo(void) : value(), _verbose(false) { };
//		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
//		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
//		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
//		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
//		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
//		foo &operator=(value_type src) { this->value = src; return *this; };
//		foo &operator=(foo const &src) {
//			if (this->_verbose || src._verbose)
//				std::cout << "foo::operator=(foo) CALLED" << std::endl;
//			this->value = src.value;
//			return *this;
//		};
//		value_type	getValue(void) const { return this->value; };
//		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };
//
//		operator value_type(void) const {
//			return value_type(this->value);
//		}
//	private:
//		value_type	value;
//		bool		_verbose;
//};
//
//template <typename T>
//std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
//	o << bar.getValue();
//	return o;
//}
//
//#define T1 char
//#define T2 foo<float>
//typedef NAMESPACE::map<T1,T2>::value_type T3;
//typedef NAMESPACE::map<T1,T2>::iterator ft_iterator;
//typedef NAMESPACE::map<T1,T2>::const_iterator const_it;
//typedef NAMESPACE::map<T1, T2> _map;
//
//static unsigned int i = 0;
//
//template <typename T>
//std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
//{
//	o << "key: " << iterator->first << " | value: " << iterator->second;
//	if (nl)
//		o << std::endl;
//	return ("");
//}
//
//void	ft_comp(const _map &mp, const const_it &it1, const const_it &it2)
//{
//	bool res[2];
//
//	std::cout << "\t-- [" << ++i << "] --" << std::endl;
//	res[0] = mp.key_comp()(it1->first, it2->first);
//	res[1] = mp.value_comp()(*it1, *it2);
//	std::cout << "with [" << it1->first << " and " << it2->first << "]: ";
//	std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
//}

// template <typename MAP>
// void	ft_bound(MAP &mp, const T1 &param)
// {
// 	ft_iterator ite = mp.end(), it[2];
// 	ft::pair<ft_iterator, ft_iterator> ft_range;

// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	std::cout << "with key [" << param << "]:" << std::endl;
// 	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
// 	ft_range = mp.equal_range(param);
// 	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
// 	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
// 	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
// }

// template <typename MAP>
// void	ft_const_bound(const MAP &mp, const T1 &param)
// {
// 	ft_const_iterator ite = mp.end(), it[2];
// 	ft::pair<ft_const_iterator, ft_const_iterator> ft_range;

// 	std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
// 	std::cout << "with key [" << param << "]:" << std::endl;
// 	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
// 	ft_range = mp.equal_range(param);
// 	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
// 	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
// 	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
// }

//int		main(void)
//{
//	_map	mp;
//
//	mp['a'] = 2.3;
//	mp['b'] = 1.4;
//	mp['c'] = 0.3;
//	mp['d'] = 4.2;
//
//	for (const_it it1 = mp.begin(); it1 != mp.end(); ++it1)
//		for (const_it it2 = mp.begin(); it2 != mp.end(); ++it2)
//			ft_comp(mp, it1, it2);

	// std::list<T3> lst;
	// unsigned int lst_size = 10;
	// for (unsigned int i = 0; i < lst_size; ++i)
	// 	lst.push_back(T3(i + 1, (i + 1) * 3));
	// NAMESPACE::map<T1, foo<int> > mp(lst.begin(), lst.end());

	// ft_const_bound(mp, -10);
	// ft_const_bound(mp, 1);
	// ft_const_bound(mp, 5);
	// ft_const_bound(mp, 10);
	// ft_const_bound(mp, 50);

	// mp.lower_bound(3)->second = 404;
	// mp.upper_bound(7)->second = 842;
	// ft_bound(mp, 5);
	// ft_bound(mp, 7);
//


// int		main(void)
// {

	// {	/*------------------------------ VECTOR -----------------------------*/
	// 	std::cout << YELLOW << "///////////////// -VECTOR- /////////////////" << std::endl;
	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// DEFAULT CONSTRUCTOR
	// 		std::cout << "DEFAULT CONSTRUCTOR :" << std::endl;
	// 		NAMESPACE::vector<int>	vector;	// DEFAULT CONSTRUCTOR
	// 		std::cout << "EMPTY : " << vector.empty() << std::endl;	// EMPTY
	// 		std::cout << "SIZE : " << vector.size() << std::endl;	// SIZE
	// 		std::cout << "CAPACITY : " << vector.capacity() << std::endl;	// CAPACITY
	// 		std::cout << "MAX SIZE : " << vector.max_size() << std::endl;	// MAX_SIZE
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// FILL CONSTRUCTOR
	// 		std::cout << "FILL CONSTRUCTOR :" << std::endl;
	// 		NAMESPACE::vector<int>	vector(10, -10);	// FILL CONSTRUCTOR
	// 		std::cout << "EMPTY : " << vector.empty() << std::endl;
	// 		std::cout << "SIZE : " << vector.size() << std::endl;
	// 		std::cout << "CAPACITY : " << vector.capacity() << std::endl;
	// 		std::cout << "MAX SIZE : " << vector.max_size() << std::endl;
	// 		std::cout << "PRINT CONTENT WITH OPERATOR [] :" << std::endl;
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector[i] << " ";	// OPERATOR []
	// 		std::cout << std::endl;
			
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// RANGE CONSTRUCTOR
	// 		NAMESPACE::vector<int>	vector2(10, -10);

	// 		std::cout << "RANGE CONSTRUCTOR :" << std::endl;
	// 		NAMESPACE::vector<int>	vector(vector2.begin(), vector2.end());	// RANGE CONSTRUCTOR
	// 		std::cout << "EMPTY : " << vector.empty() << std::endl;
	// 		std::cout << "SIZE : " << vector.size() << std::endl;
	// 		std::cout << "CAPACITY : " << vector.capacity() << std::endl;
	// 		std::cout << "MAX SIZE : " << vector.max_size() << std::endl;
	// 		std::cout << "PRINT CONTENT WITH AT :" << std::endl;
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector.at(i) << " ";	// AT
	// 		std::cout << std::endl;
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// COPY CONSTRUCTOR
	// 		NAMESPACE::vector<int>	vector2(10, -10);

	// 		std::cout << "COPY CONSTRUCTOR :" << std::endl;
	// 		NAMESPACE::vector<int>	vector(vector2);	// COPY CONSTRUCTOR
	// 		std::cout << "EMPTY : " << vector.empty() << std::endl;
	// 		std::cout << "SIZE : " << vector.size() << std::endl;
	// 		std::cout << "CAPACITY : " << vector.capacity() << std::endl;
	// 		std::cout << "MAX SIZE : " << vector.max_size() << std::endl;

	// 		NAMESPACE::vector<int>::iterator	it = vector.begin();	// ITERATOR
	// 		NAMESPACE::vector<int>::iterator	ite = vector.end();	// ITERATOR
	// 		std::cout << "PRINT CONTENT WITH ITERATOR :" << std::endl;
	// 		for (; it != ite; it++)
	// 			std::cout << *it << " ";
	// 		std::cout << std::endl;
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// OPERATOR =
	// 		NAMESPACE::vector<int>	vector2(10, -10);

	// 		std::cout << "OPERATOR = :" << std::endl;
	// 		NAMESPACE::vector<int>	vector = vector2;	// OPERATOR =
	// 		std::cout << "EMPTY : " << vector.empty() << std::endl;
	// 		std::cout << "SIZE : " << vector.size() << std::endl;
	// 		std::cout << "CAPACITY : " << vector.capacity() << std::endl;
	// 		std::cout << "MAX SIZE : " << vector.max_size() << std::endl;

	// 		NAMESPACE::vector<int>::const_iterator	it = vector.begin();	// CONST_ITERATOR
	// 		NAMESPACE::vector<int>::const_iterator	ite = vector.end();	// CONST_ITERATOR
	// 		std::cout << "PRINT CONTENT WITH CONST ITERATOR :" << std::endl;
	// 		for (; it != ite; it++)
	// 			std::cout << *it << " ";
	// 		std::cout << std::endl;
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// PUSH_BACK
	// 		NAMESPACE::vector<int>	vector;
	// 		std::cout << "EMPTY : " << vector.empty() << std::endl;
	// 		std::cout << "SIZE : " << vector.size() << std::endl;
	// 		std::cout << "CAPACITY : " << vector.capacity() << std::endl;

	// 		std::cout << "- PUSH BACK -" << std::endl;
	// 		for (size_t i = 0; i < 10; i++)
	// 			vector.push_back(i * 10);		// PUSH_BACK

	// 		std::cout << "EMPTY : " << vector.empty() << std::endl;
	// 		std::cout << "SIZE : " << vector.size() << std::endl;
	// 		std::cout << "CAPACITY : " << vector.capacity() << std::endl;

	// 		NAMESPACE::vector<int>::iterator	it = vector.begin();
	// 		NAMESPACE::vector<int>::iterator	ite = vector.end();
	// 		std::cout << "PRINT CONTENT WITH ITERATOR :" << std::endl;
	// 		for (; it != ite; it++)
	// 			std::cout << *it << " ";
	// 		std::cout << std::endl;

	// 		NAMESPACE::vector<int>::reverse_iterator	rit = vector.rbegin();	// REVERSE_ITERATOR
	// 		NAMESPACE::vector<int>::reverse_iterator	rite = vector.rend();	// REVERSE_ITERATOR
	// 		std::cout << "PRINT CONTENT WITH REVERSE ITERATOR :" << std::endl;
	// 		for (; rit != rite; rit++)
	// 			std::cout << *rit << " ";
	// 		std::cout << std::endl;
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// OPERATOR [] & AT
	// 		std::cout << "OPERATOR [] & AT :" << std::endl;
	// 		NAMESPACE::vector<int>	vector;

	// 		for (size_t i = 0; i < 10; i++)
	// 			vector.push_back(i * 25);

	// 		std::cout << "CONTENT : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 		{
	// 			if (i && !(i % 5))
	// 				std::cout << std::endl;
	// 			std::cout << "[" << i << "] = " << vector[i] << " ";	// OPERATOR[]
	// 		}
	// 		std::cout << std::endl << std::endl;

	// 		std::cout << "VECTOR AT(7) : " << vector.at(7) << std::endl;	// AT
	// 		std::cout << "VECTOR[8] : " << vector[8] << std::endl;	// OPERATOR[]

	// 		std::cout << "VECTOR AT(7) = 9" << std::endl;
	// 		vector.at(7) = 9;	// AT
	// 		std::cout << "VECTOR[8] = 11" << std::endl << std::endl;
	// 		vector[8] = 11;	// OPERATOR[]

	// 		std::cout << "CONTENT : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 		{
	// 			if (i && !(i % 5))
	// 				std::cout << std::endl;
	// 			std::cout << "[" << i << "] = " << vector[i] << " ";	// OPERATOR[]
	// 		}
	// 		std::cout << std::endl << std::endl;

	// 		std::cout << "VECTOR AT(19) : ";
	// 		try
	// 		{
	// 			std::cout << vector.at(19) << std::endl;
	// 		}
	// 		catch(const std::exception& e)
	// 		{
	// 			std::cout << e.what() << std::endl;
	// 		}
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	//	RESERVE
	// 		NAMESPACE::vector<int>	vector;
	// 		std::cout << "EMPTY : " << vector.empty() << std::endl;
	// 		std::cout << "SIZE : " << vector.size() << std::endl;
	// 		std::cout << "CAPACITY : " << vector.capacity() << std::endl;

	// 		std::cout << std::endl << "- RESERVE 10 -" << std::endl << std::endl;
	// 		vector.reserve(10);	//	RESERVE

	// 		std::cout << "EMPTY : " << vector.empty() << std::endl;
	// 		std::cout << "SIZE : " << vector.size() << std::endl;
	// 		std::cout << "CAPACITY : " << vector.capacity() << std::endl;

	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// FRONT & BACK
	// 		NAMESPACE::vector<int>	vector;

	// 		for (size_t i = 0; i < 10; i++)
	// 			vector.push_back(i * 2);

	// 		std::cout << "CONTENT : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector[i] << " ";
	// 		std::cout << std::endl;

	// 		std::cout << "FRONT : " << vector.front() << std::endl;	// FRONT
	// 		std::cout << "BACK : " << vector.back() << std::endl;	// BACK

	// 		std::cout << std::endl << "- POP_BACK -" << std::endl << std::endl;
	// 		vector.pop_back();	// POP_BACK

	// 		std::cout << "CONTENT : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector[i] << " ";
	// 		std::cout << std::endl;

	// 		std::cout << "FRONT : " << vector.front() << std::endl;	// FRONT
	// 		std::cout << "BACK : " << vector.back() << std::endl;	// BACK
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// RESIZE
	// 		NAMESPACE::vector<int>	vector;
	// 		for (size_t i = 0; i < 10; i++)
	// 			vector.push_back(i * 3);

	// 		std::cout << "CONTENT : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector[i] << " ";
	// 		std::cout << std::endl;
	// 		std::cout << "SIZE : " << vector.size() << std::endl;

	// 		std::cout << "- RESIZE 5 -" << std::endl;
	// 		vector.resize(5);	// RESIZE

	// 		std::cout << "CONTENT : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector[i] << " ";
	// 		std::cout << std::endl;
	// 		std::cout << "SIZE : " << vector.size() << std::endl;

	// 		std::cout << "- RESIZE 15 WITH VAL=99 -" << std::endl;
	// 		vector.resize(15, 99);	// RESIZE

	// 		std::cout << "CONTENT : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector[i] << " ";
	// 		std::cout << std::endl;
	// 		std::cout << "SIZE : " << vector.size() << std::endl;

	// 		std::cout << "- RESIZE 19 -" << std::endl;
	// 		vector.resize(19);	// RESIZE

	// 		std::cout << "CONTENT : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector[i] << " ";
	// 		std::cout << std::endl;
	// 		std::cout << "SIZE : " << vector.size() << std::endl;
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// INSERT
	// 		NAMESPACE::vector<int>	vector(10, 5);
	// 		NAMESPACE::vector<int>	vector2;
	// 		for (size_t i = 0; i < 10; i++)
	// 			vector2.push_back(i * 4);

	// 		std::cout << "CONTENT A : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector[i] << " ";
	// 		std::cout << "|SIZE : " << vector.size() << std::endl;
	// 		std::cout << "CONTENT B : ";
	// 		for (size_t i = 0; i < vector2.size(); i++)
	// 			std::cout << vector2[i] << " ";
	// 		std::cout << "|SIZE : " << vector2.size() << std::endl;


	// 		std::cout << std::endl << "- INSERT BEGIN_B AT BEGIN_A + 1 -" << std::endl << std::endl;
	// 		vector.insert(++(vector.begin()), *vector2.begin());	// INSERT

	// 		std::cout << "CONTENT A : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector[i] << " ";
	// 		std::cout << "|SIZE : " << vector.size() << std::endl;
	// 		std::cout << "CONTENT B : ";
	// 		for (size_t i = 0; i < vector2.size(); i++)
	// 			std::cout << vector2[i] << " ";
	// 		std::cout << "|SIZE : " << vector2.size() << std::endl;

	// 		std::cout << std::endl << "- INSERT BEGIN_B + 2 TREE TIME AT BEGIN_A + 2 -" << std::endl << std::endl;
	// 		vector.insert(++(++(vector.begin())), 3, *++(++(vector2.begin())));	// INSERT

	// 		std::cout << "CONTENT A : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector[i] << " ";
	// 		std::cout << "|SIZE : " << vector.size() << std::endl;
	// 		std::cout << "CONTENT B : ";
	// 		for (size_t i = 0; i < vector2.size(); i++)
	// 			std::cout << vector2[i] << " ";
	// 		std::cout << "|SIZE : " << vector2.size() << std::endl;

	// 		std::cout << std::endl << "INSERT B AT THE START OF A -" << std::endl << std::endl;
	// 		vector.insert(vector.begin(), vector2.begin(), vector2.end());	// INSERT

	// 		std::cout << "CONTENT A : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector[i] << " ";
	// 		std::cout << "|SIZE : " << vector.size() << std::endl;
	// 		std::cout << "CONTENT B : ";
	// 		for (size_t i = 0; i < vector2.size(); i++)
	// 			std::cout << vector2[i] << " ";
	// 		std::cout << "|SIZE : " << vector2.size() << std::endl;
	// 	}
	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// SWAP
	// 		NAMESPACE::vector<int>	vector;
	// 		NAMESPACE::vector<int>	vector2;

	// 		for (size_t i = 0; i < 10; i++)
	// 			vector.push_back(i * 4);
	// 		for (size_t i = 0; i < 5; i++)
	// 			vector2.push_back(i * 5);

	// 		std::cout << "CONTENT A : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector[i] << " ";
	// 		std::cout << std::endl;
	// 		std::cout << "SIZE : " << vector.size() << std::endl;
	// 		std::cout << "CAPACITY : " << vector.capacity() << std::endl;
	// 		std::cout << std::endl;

	// 		std::cout << "CONTENT B : ";
	// 		for (size_t i = 0; i < vector2.size(); i++)
	// 			std::cout << vector2[i] << " ";
	// 		std::cout << std::endl;
	// 		std::cout << "SIZE : " << vector2.size() << std::endl;
	// 		std::cout << "CAPACITY : " << vector2.capacity() << std::endl;

	// 		std::cout << "- SWAP -" << std::endl;
	// 		vector.swap(vector2);	// SWAP

	// 		std::cout << "CONTENT A : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector[i] << " ";
	// 		std::cout << std::endl;
	// 		std::cout << "SIZE : " << vector.size() << std::endl;
	// 		std::cout << "CAPACITY : " << vector.capacity() << std::endl;
	// 		std::cout << std::endl;

	// 		std::cout << "CONTENT B : ";
	// 		for (size_t i = 0; i < vector2.size(); i++)
	// 			std::cout << vector2[i] << " ";
	// 		std::cout << std::endl;
	// 		std::cout << "SIZE : " << vector2.size() << std::endl;
	// 		std::cout << "CAPACITY : " << vector2.capacity() << std::endl;
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// ERASE
	// 		NAMESPACE::vector<int>	vector;
	// 		for (size_t i = 0; i < 10; i++)
	// 			vector.push_back(i * 6);
			
	// 		std::cout << "CONTENT : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector[i] << " ";
	// 		std::cout << "|SIZE : " << vector.size() << std::endl;
			
	// 		std::cout << "- ERASE AT BEGIN + 2 -" << std::endl;
	// 		vector.erase(++(++(vector.begin())));	// ERASE

	// 		std::cout << "CONTENT : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector[i] << " ";
	// 		std::cout << "|SIZE : " << vector.size() << std::endl;

	// 		std::cout << "- ERASE ALL EXEPT LAST ELEMENT -" << std::endl;
	// 		vector.erase(vector.begin(), --(vector.end()));	// ERASE

	// 		std::cout << "CONTENT : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector[i] << " ";
	// 		std::cout << "|SIZE : " << vector.size() << std::endl;
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// ASSIGN
	// 		NAMESPACE::vector<int>	vector;
	// 		NAMESPACE::vector<int>	vector2;
	// 		for (size_t i = 0; i < 10; i++)
	// 			vector.push_back(i * 6);
	// 		for (size_t i = 0; i < 7; i++)
	// 			vector2.push_back(i * 2);
			
	// 		std::cout << "CONTENT A : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector[i] << " ";
	// 		std::cout << "|SIZE : " << vector.size() << std::endl;
	// 		std::cout << "CONTENT B : ";
	// 		for (size_t i = 0; i < vector2.size(); i++)
	// 			std::cout << vector2[i] << " ";
	// 		std::cout << "|SIZE : " << vector2.size() << std::endl;

	// 		std::cout << "- ASSIGN 0 -> 5 OF B IN A -" << std::endl;
	// 		vector.assign(vector2.begin(), --(--(vector2.end()))); // ASSIGN

	// 		std::cout << "CONTENT A : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector[i] << " ";
	// 		std::cout << "|SIZE : " << vector.size() << std::endl;
	// 		std::cout << "CONTENT B : ";
	// 		for (size_t i = 0; i < vector2.size(); i++)
	// 			std::cout << vector2[i] << " ";
	// 		std::cout << "|SIZE : " << vector2.size() << std::endl;
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// RELATIONAL OPERATOR
	// 		NAMESPACE::vector<int>	vector;
	// 		NAMESPACE::vector<int>	vector2;
	// 		NAMESPACE::vector<int>	vector3;
	// 		for (size_t i = 0; i < 10; i++)
	// 			vector.push_back(i * 7);
	// 		for (size_t i = 0; i < 15; i++)
	// 			vector2.push_back(i * 10);
	// 		for (size_t i = 0; i < 10; i++)
	// 			vector3.push_back(i * 9);

	// 		std::cout << "CONTENT A : ";
	// 		for (size_t i = 0; i < vector.size(); i++)
	// 			std::cout << vector[i] << " ";
	// 		std::cout << "|SIZE : " << vector.size() << std::endl;
	// 		std::cout << "CONTENT B : ";
	// 		for (size_t i = 0; i < vector2.size(); i++)
	// 			std::cout << vector2[i] << " ";
	// 		std::cout << "|SIZE : " << vector2.size() << std::endl;
	// 		std::cout << "CONTENT C : ";
	// 		for (size_t i = 0; i < vector3.size(); i++)
	// 			std::cout << vector3[i] << " ";
	// 		std::cout << "|SIZE : " << vector3.size() << std::endl;
			
	// 		std::cout << "RELATIONAL OPERATOR :" << std::endl << std::endl;
	// 		std::cout << "- A VS B -" << std::endl;
	// 		std::cout << "== : " << (vector == vector2) << " | != : " << (vector != vector2) << std::endl;	// RELATIONAL OPERATOR
	// 		std::cout << " < : " << (vector < vector2) << " | >  : " << (vector > vector2) << std::endl;	// RELATIONAL OPERATOR
	// 		std::cout << "<= : " << (vector <= vector2) << " | >= : " << (vector >= vector2) << std::endl << std::endl;	// RELATIONAL OPERATOR

	// 		std::cout << "- A VS C -" << std::endl;
	// 		std::cout << "== : " << (vector == vector3) << " | != : " << (vector != vector3) << std::endl;	// RELATIONAL OPERATOR
	// 		std::cout << " < : " << (vector < vector3) << " | >  : " << (vector > vector3) << std::endl;	// RELATIONAL OPERATOR
	// 		std::cout << "<= : " << (vector <= vector3) << " | >= : " << (vector >= vector3) << std::endl << std::endl;	// RELATIONAL OPERATOR

	// 		std::cout << "- B VS C -" << std::endl;
	// 		std::cout << "== : " << (vector2 == vector3) << " | != : " << (vector2 != vector3) << std::endl;	// RELATIONAL OPERATOR
	// 		std::cout << " < : " << (vector2 < vector3) << " | >  : " << (vector2 > vector3) << std::endl;	// RELATIONAL OPERATOR
	// 		std::cout << "<= : " << (vector2 <= vector3) << " | >= : " << (vector2 >= vector3) << std::endl;	// RELATIONAL OPERATOR
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;
	// }


	// {	/*------------------------------- MAP -------------------------------*/
	// 	std::cout << CYAN << "////////////////// -MAP- //////////////////" << std::endl;
	// 	std::cout << "-----------------------------------------------------------" << std::endl;
	// 	std::cout << "DEFAULT CONSTRUCTOR :" << std::endl;	// DEFAULT CONSTRUCTOR
	// 	NAMESPACE::map<int, char> map;
	// 	std::cout << "EMPTY : " << map.empty() << std::endl;	// EMPTY
	// 	std::cout << "SIZE : " << map.size() << std::endl;	// SIZE
	// 	std::cout << "MAX SIZE : " << map.max_size() << std::endl;	// MAX_SIZE

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	std::cout << "INSERT :" << std::endl;
	// 	for (size_t i = 0; i < 10; i++)
	// 		map.insert(NAMESPACE::make_pair(i, 'A' + i));		// INSERT

	// 	std::cout << "EMPTY : " << map.empty() << std::endl;
	// 	std::cout << "SIZE : " << map.size() << std::endl;
	// 	std::cout << "MAX SIZE : " << map.max_size() << std::endl;

	// 	NAMESPACE::map<int, char>::iterator	it(map.begin());	// ITERATOR
	// 	NAMESPACE::map<int, char>::iterator	ite(map.end());

	// 	for (; it != ite; it++)
	// 		std::cout << "[" << it->first << "|" << it->second << "] ";	// PAIR
	// 	std::cout << std::endl;

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// COPY CONSTRUCT
	// 		std::cout << "COPY CONSTRUCT :" << std::endl;
	// 		NAMESPACE::map<int, char> map2(map);	// COPY CONSTRUCT
	// 		std::cout << "EMPTY : " << map2.empty() << std::endl;
	// 		std::cout << "SIZE : " << map2.size() << std::endl;
	// 		std::cout << "MAX SIZE : " << map2.max_size() << std::endl;

	// 		NAMESPACE::map<int, char>::reverse_iterator	it2(map2.rbegin());	// REVERSE ITERATOR
	// 		NAMESPACE::map<int, char>::reverse_iterator	ite2(map2.rend());

	// 		std::cout << "PRINT WITH REVERSE ITERATOR :" << std::endl;
	// 		for (; it2 != ite2; it2++)
	// 			std::cout << "[" << it2->first << "|" << it2->second << "] ";
	// 		std::cout << std::endl;
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// ITERATOR RANGE CONSTRUCTOR
	// 		std::cout << "ITERATOR RANGE CONSTRUCTOR :" << std::endl;
	// 		NAMESPACE::map<int, char> map2(map.begin(), map.end());	// ITERATOR RANGE CONSTRUCTOR
	// 		std::cout << "EMPTY : " << map2.empty() << std::endl;
	// 		std::cout << "SIZE : " << map2.size() << std::endl;
	// 		std::cout << "MAX SIZE : " << map2.max_size() << std::endl;

	// 		NAMESPACE::map<int, char>::iterator	it2(map2.begin());
	// 		NAMESPACE::map<int, char>::iterator	ite2(map2.end());

	// 		for (; it2 != ite2; it2++)
	// 			std::cout << "[" << it2->first << "|" << it2->second << "] ";
	// 		std::cout << std::endl;
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// OPERATOR =
	// 		std::cout << "ASSIGNEMENT OPERATOR :" << std::endl;
	// 		NAMESPACE::map<int, char> map2 = map;	// ASSIGNEMENT OPERATOR
	// 		std::cout << "EMPTY : " << map2.empty() << std::endl;
	// 		std::cout << "SIZE : " << map2.size() << std::endl;
	// 		std::cout << "MAX SIZE : " << map2.max_size() << std::endl;

	// 		NAMESPACE::map<int, char>::iterator	it2(map.begin());
	// 		NAMESPACE::map<int, char>::iterator	ite2(map.end());

	// 		for (; it2 != ite2; it2++)
	// 			std::cout << "[" << it2->first << "|" << it2->second << "] ";
	// 		std::cout << std::endl;
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// OPERATOR []
	// 		NAMESPACE::map<int, char> map2;
	// 		std::cout << "INSERT WITH OPERATOR [] :" << std::endl;
	// 		for (size_t i = 0; i < 26; i++)
	// 			map2[i] = 'A' + i;	// INSERT WITH OPERATOR []

	// 		std::cout << "PRINT WITH OPERATOR [] :" << std::endl;
	// 		for (size_t i = 0; i < 26; i++)
	// 		{
	// 			if (!(i % 9) && i)
	// 				std::cout << std::endl;
	// 			std::cout << "[" << i << "|" << map2[i] << "] ";	// PRINT WITH OPERATOR []
	// 		}
	// 		std::cout << std::endl;
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// ERASE
	// 		NAMESPACE::map<int, char> map2(map);
	// 		std::cout << "EMPTY : " << map2.empty() << std::endl;
	// 		std::cout << "SIZE : " << map2.size() << std::endl;
	// 		std::cout << "ERASE KEY 9 : " << map2.erase(9) << std::endl;	// ERASE INDEX
	// 		std::cout << "ERASE KEY 9 : " << map2.erase(9) << std::endl;
	// 		std::cout << "SIZE : " << map2.size() << std::endl << std::endl;

	// 		std::cout << "ERASE WITH ITERATOR : " << std::endl;
	// 		map2.erase(--(--map2.end()));	// ERASE ITERATOR
	// 		std::cout << "SIZE : " << map2.size() << std::endl;

	// 		std::cout << std::endl << "ERASE ALL WITH ITERATOR RANGE : " << std::endl;
	// 		map2.erase(map2.begin(), map2.end());	// ERASE ITERATOR RANGE
	// 		std::cout << "SIZE : " << map2.size() << std::endl;
	// 		std::cout << "EMPTY : " << map2.empty() << std::endl;
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// CLEAR
	// 		NAMESPACE::map<int, char> map2(map);
	// 		std::cout << "EMPTY : " << map2.empty() << std::endl;
	// 		std::cout << "SIZE : " << map2.size() << std::endl;
	// 		std::cout << std::endl << "--- CLEAR ---" << std::endl << std::endl;
	// 		map2.clear();	// CLEAR
	// 		std::cout << "EMPTY : " << map2.empty() << std::endl;
	// 		std::cout << "SIZE : " << map2.size() << std::endl;
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// SWAP
	// 		NAMESPACE::map<int, char> map2;
	// 		NAMESPACE::map<int, char> map3;

	// 		for (size_t i = 0; i < 10; i++)
	// 			map2[i] = 'A' + i;
	// 		for (size_t i = 10; i < 15; i++)
	// 			map3[i] = 'A' + i;

	// 		std::cout << "MAP2 SIZE : " << map2.size() << std::endl;
	// 		{
	// 			NAMESPACE::map<int, char>::iterator	it2(map2.begin());
	// 			NAMESPACE::map<int, char>::iterator	ite2(map2.end());
	// 			for (; it2 != ite2; it2++)
	// 				std::cout << "[" << it2->first << "|" << it2->second << "] ";
	// 			std::cout << std::endl;
	// 		}

	// 		std::cout << "MAP3 SIZE : " << map3.size() << std::endl;
	// 		{
	// 			NAMESPACE::map<int, char>::iterator	it3(map3.begin());
	// 			NAMESPACE::map<int, char>::iterator	ite3(map3.end());
	// 			for (; it3 != ite3; it3++)
	// 				std::cout << "[" << it3->first << "|" << it3->second << "] ";
	// 			std::cout << std::endl;
	// 		}

	// 		std::cout << std::endl << "--- SWAP ---" << std::endl << std::endl;
	// 		map2.swap(map3);	// SWAP

	// 		std::cout << "MAP2 SIZE : " << map2.size() << std::endl;
	// 		{
	// 			NAMESPACE::map<int, char>::iterator	it2(map2.begin());
	// 			NAMESPACE::map<int, char>::iterator	ite2(map2.end());
	// 			for (; it2 != ite2; it2++)
	// 				std::cout << "[" << it2->first << "|" << it2->second << "] ";
	// 			std::cout << std::endl;
	// 		}

	// 		std::cout << "MAP3 SIZE : " << map3.size() << std::endl;
	// 		{
	// 			NAMESPACE::map<int, char>::iterator	it3(map3.begin());
	// 			NAMESPACE::map<int, char>::iterator	ite3(map3.end());
	// 			for (; it3 != ite3; it3++)
	// 				std::cout << "[" << it3->first << "|" << it3->second << "] ";
	// 			std::cout << std::endl;
	// 		}
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// COUNT
	// 		NAMESPACE::map<int, char> map2;
	// 		for (size_t i = 0; i < 10; i++)
	// 			map2[i * 10] = 'A' + i;

	// 		std::cout << "SIZE : " << map2.size() << std::endl;
	// 		NAMESPACE::map<int, char>::iterator	it2(map2.begin());
	// 		NAMESPACE::map<int, char>::iterator	ite2(map2.end());
	// 		for (; it2 != ite2; it2++)
	// 			std::cout << "[" << it2->first << "|" << it2->second << "] ";
	// 		std::cout << std::endl;
	// 		std::cout << "IS INDEX 99 EXISTING : " << map2.count(99) << std::endl;	// COUNT
	// 		std::cout << "IS INDEX 80 EXISTING : " << map2.count(80) << std::endl;
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// FIND
	// 		std::cout << "FIND :" << std::endl;
	// 		NAMESPACE::map<int, char> map2(map);
	// 		NAMESPACE::map<int, char>::iterator	it2(map2.begin());
	// 		NAMESPACE::map<int, char>::iterator	ite2(map2.end());
	// 		for (; it2 != ite2; it2++)
	// 			std::cout << "[" << it2->first << "|" << it2->second << "] ";
	// 		std::cout << std::endl;
	// 		std::cout << "SIZE : " << map2.size() << std::endl;

	// 		NAMESPACE::map<int, char>::iterator	find1(map2.find(8));
	// 		NAMESPACE::map<int, char>::iterator	find2(map2.find(80));
	// 		std::cout << "DID WE FOUND 8 : ";
	// 		std::cout << "[" << find1->first << "|" << find1->second << "]" << std::endl;
	// 		std::cout << "DID WE FOUND 80 : ";
	// 		std::cout << "[" << find2->first << "|" << find2->second << "] " << std::endl;
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// LOWER_BOUND
	// 		NAMESPACE::map<int, char> map2(map);
	// 		NAMESPACE::map<int, char>::iterator	lb1(map2.lower_bound(-5));	// LOWER_BOUND
	// 		std::cout << "LOWER BOUND OF -5 : ";
	// 		std::cout << "[" << lb1->first << "|" << lb1->second << "]" << std::endl;

	// 		NAMESPACE::map<int, char>::iterator	lb2(map2.lower_bound(5));	// LOWER_BOUND
	// 		std::cout << "LOWER BOUND OF 5 : ";
	// 		std::cout << "[" << lb2->first << "|" << lb2->second << "]" << std::endl;

	// 		NAMESPACE::map<int, char>::iterator	lb3(map2.lower_bound(15));	// LOWER_BOUND
	// 		std::cout << "LOWER BOUND OF 15 : ";
	// 		std::cout << "[" << lb3->first << "|" << lb3->second << "]" << std::endl;
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// UPPER_BOUND
	// 		NAMESPACE::map<int, char> map2(map);
	// 		NAMESPACE::map<int, char>::iterator	lb1(map2.upper_bound(-5));	// UPPER_BOUND
	// 		std::cout << "UPPER BOUND OF -5 : ";
	// 		std::cout << "[" << lb1->first << "|" << lb1->second << "]" << std::endl;

	// 		NAMESPACE::map<int, char>::iterator	lb2(map2.upper_bound(5));	// UPPER_BOUND
	// 		std::cout << "UPPER BOUND OF 5 : ";
	// 		std::cout << "[" << lb2->first << "|" << lb2->second << "]" << std::endl;

	// 		NAMESPACE::map<int, char>::iterator	lb3(map2.upper_bound(15));	// UPPER_BOUND
	// 		std::cout << "UPPER BOUND OF 15 : ";
	// 		std::cout << "[" << lb3->first << "|" << lb3->second << "]" << std::endl;
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;

	// 	{	// RELATIONAL OPERATOR

	// 		NAMESPACE::map<int, char>::iterator	it(map.begin());
	// 		NAMESPACE::map<int, char>::iterator	ite(map.end());
	// 		std::cout << "MAP = ";
	// 		for (; it != ite; it++)
	// 			std::cout << "[" << it->first << "|" << it->second << "] ";
	// 		std::cout << std::endl;

	// 		NAMESPACE::map<int, char> map2;
	// 		for (size_t i = 10; i < 15; i++)
	// 			map2[i] = 'A' + i;
	// 		std::cout << "MAP2 = ";
	// 		NAMESPACE::map<int, char>::iterator	it2(map2.begin());
	// 		NAMESPACE::map<int, char>::iterator	ite2(map2.end());
	// 		for (; it2 != ite2; it2++)
	// 			std::cout << "[" << it2->first << "|" << it2->second << "] ";
	// 		std::cout << std::endl;

	// 		NAMESPACE::map<int, char> map3(map);
	// 		std::cout << "MAP3 = ";
	// 		NAMESPACE::map<int, char>::iterator	it3(map3.begin());
	// 		NAMESPACE::map<int, char>::iterator	ite3(map3.end());
	// 		for (; it3 != ite3; it3++)
	// 			std::cout << "[" << it3->first << "|" << it3->second << "] ";
	// 		std::cout << std::endl;

	// 		std::cout << "RELATIONAL OPERATOR :" << std::endl << std::endl;
	// 		std::cout << "- MAP VS MAP2-" << std::endl;
	// 		std::cout << "== : " << (map == map2) << " | != : " << (map != map2) << std::endl;	// RELATIONAL OPERATOR
	// 		std::cout << " < : " << (map < map2) << " | >  : " << (map > map2) << std::endl;	// RELATIONAL OPERATOR
	// 		std::cout << "<= : " << (map <= map2) << " | >= : " << (map >= map2) << std::endl;	// RELATIONAL OPERATOR

	// 		std::cout << "- MAP VS MAP3 -" << std::endl;
	// 		std::cout << "== : " << (map == map3) << " | != : " << (map != map3) << std::endl;	// RELATIONAL OPERATOR
	// 		std::cout << " < : " << (map < map3) << " | >  : " << (map > map3) << std::endl;	// RELATIONAL OPERATOR
	// 		std::cout << "<= : " << (map <= map3) << " | >= : " << (map >= map3) << std::endl;	// RELATIONAL OPERATOR
	// 	}

	// 	std::cout << "-----------------------------------------------------------" << std::endl;
	// }

	// {	/*----------------------------- STACK -------------------------------*/
	// 	std::cout << PINK << "////////////////// -STACK- //////////////////" << std::endl;
	// 	std::cout << "---------------------------------------------" << std::endl;
	// 	NAMESPACE::stack<int, NAMESPACE::vector<int> > stack_1, stack_2;
	// 	for (size_t i = 0; i < 10; i++)
	// 	{
	// 		stack_1.push(i);	// PUSH
	// 		stack_2.push(i * 10);	// PUSH
	// 	}

	// 	stack_2.pop();	// POP


	// 	std::cout << "SIZE OF STACK_1 : " << stack_1.size() << std::endl;	// SIZE
	// 	std::cout << "SIZE OF STACK_2 : " << stack_1.size() << std::endl;	// SIZE

	// 	std::cout << "---------------------------" << std::endl;

	// 	std::cout << "RELATIONAL OPERATOR :" << std::endl;
	// 	std::cout << "STACK_1 VS STACK_2" << std::endl;
	// 	std::cout << "== : " << (stack_1 == stack_2) << " | != : " << (stack_1 != stack_2) << std::endl;	// RELATIONAL OPERATOR
	// 	std::cout << " < : " << (stack_1 < stack_2) << " | >  : " << (stack_1 > stack_2) << std::endl;	// RELATIONAL OPERATOR
	// 	std::cout << "<= : " << (stack_1 <= stack_2) << " | >= : " << (stack_1 >= stack_2) << std::endl;	// RELATIONAL OPERATOR

	// 	std::cout << "---------------------------" << std::endl;

	// 	std::cout << "STACK_1 = ";
	// 	while (!(stack_1.empty()))	// EMPTY
	// 	{
	// 		std::cout << "[" << stack_1.top() << "] ";	// TOP
	// 		stack_1.pop();
	// 	}
	// 	std::cout << std::endl;

	// 	std::cout << "STACK_2 = ";
	// 	while (!(stack_2.empty()))	// EMPTY
	// 	{
	// 		std::cout << "[" << stack_2.top() << "] ";	// TOP
	// 		stack_2.pop();
	// 	}
	// 	std::cout << std::endl;
	// }

// 	std::cout << GREEN << "///////////////// -THE END- /////////////////" << WHITE << std::endl;
// 	return (0);
// }

// clear && c++ -Wall -Werror -Wextra -D NAMESPACE=ft main.cpp && time ./a.out