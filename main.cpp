#include <iostream>
#include <string>

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

#include <stdlib.h>

#define T1 int
#define T2 std::string
typedef ft::map<T1, T2>::value_type T3;
typedef ft::map<T1, T2>::iterator iterator;

static int iter = 0;

template <typename MAP, typename U>
void	ft_insert(MAP &mp, U param)
{
	ft::pair<iterator, bool> tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param);
	//std::cout << "insert return: " << printPair(tmp.first);
	std::cout << "Created new node: " << tmp.second << std::endl;
	//printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_insert(MAP &mp, U param, V param2)
{
	iterator tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param, param2);
	//std::cout << "insert return: " << printPair(tmp);
	//printSize(mp);
}

int		main(void)
{
	ft::map<T1, T2> mp, mp2;

	ft_insert(mp, T3(42, "lol"));
	ft_insert(mp, T3(42, "mdr"));

	ft_insert(mp, T3(50, "mdr"));
	ft_insert(mp, T3(35, "funny"));

	ft_insert(mp, T3(45, "bunny"));
	ft_insert(mp, T3(21, "fizz"));
	ft_insert(mp, T3(38, "buzz"));

	ft_insert(mp, mp.begin(), T3(55, "fuzzy"));

	ft_insert(mp2, mp2.begin(), T3(1337, "beauty"));
	ft_insert(mp2, mp2.end(), T3(1000, "Hello"));
	ft_insert(mp2, mp2.end(), T3(1500, "World"));

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