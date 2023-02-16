#include <iostream>
 #include <string>

#include <map>

#include <vector>

 #if 0 //CREATE A REAL STL EXAMPLE
 	#include <map>
 	#include <stack>
 	#include <vector>
 	namespace ft = std;
 #else
 	#include "Map.hpp"
 	#include "Stack.hpp"
 	#include "Vector.hpp"
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

//template <typename T>
//std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
//{
//    o << "key: " << iterator->first << " | value: " << iterator->second;
//    if (nl)
//        o << std::endl;
//    return ("");
//}
//
// int		main(void)
// {
//     ft::map<int, std::string> mp;
//     ft::map<int, std::string>::iterator it;
//     ft::pair<ft::map<int, std::string>::iterator, bool> tmp;
//     ft::pair<ft::map<int, std::string>::iterator, bool> tmp2;
//     ft::pair<ft::map<int, std::string>::iterator, bool> tmp3;
//     ft::pair<ft::map<int, std::string>::iterator, bool> tmp4;
//     ft::pair<ft::map<int, std::string>::iterator, bool> tmp5;
//     ft::pair<ft::map<int, std::string>::iterator, bool> tmp6;
//     ft::pair<ft::map<int, std::string>::iterator, bool> tmp7;
//
//     tmp = mp.insert(ft::pair<int, std::string>(10, "pouette"));
//     tmp2 = mp.insert(ft::pair<int, std::string>(5, "bonjour"));
//     tmp3 = mp.insert(ft::pair<int, std::string>(58, "pour"));
//     tmp4 = mp.insert(ft::pair<int, std::string>(6, "lolo"));
//     tmp5 = mp.insert(ft::pair<int, std::string>(30, "hihi"));
//     tmp6 = mp.insert(ft::pair<int, std::string>(8, "hohhohohoo"));
//     tmp7 = mp.insert(ft::pair<int, std::string>(4, "lyly"));

//     mp.erase(5);

//     it = ++(++(++mp.begin()));
//     ft::map<int, std::string>::iterator it2;
//     while(it != mp.end()){
//         std::cout << "key : " << it->first << " | value : " << it->second << std::endl;
//         it2 = it;
//         it++;
//     }
//     it2 = mp.end();
//     while(it2 != mp.begin()) {
//         std::cout << "key : " << it2->first << " | value : " << it2->second << std::endl;
//         it2--;
//     }
//     std::cout << "key : " << it2->first << " | value : " << it2->second << std::endl;
//     mp._inorder();

 	return (0);
 }


