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

int main() {
	std::cout << "////////-- Vector -- ////////" << std::endl;
	std::cout << std::endl;
	ft::vector<int> vector; // empty vector
	ft::vector<int> vector2(5, 100); // vector of 5 ints of value 100
	ft::vector<int> vector3(vector2.begin(), vector2.end()); // same as 2 but through iteration
	ft::vector<int> vector4(vector3); // copy of 3

	std::cout << "empty vector : " << vector.empty() << std::endl;
	for (size_t i = 0; i < vector2.size(); i++)
		std::cout<< "vector2 through index : " << vector2[i] << " | ";
	std::cout << std::endl;
	std::cout << std::endl;
	ft::vector<int>::iterator it(vector3.begin());
	while (it != vector3.end()) {
		std::cout << "vector3 through iterator : " << *it++ << " | ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	it = vector4.begin();
	while (it != vector4.end()) {
		std::cout << "vector4 through iterator : " << *it++ << " | ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	vector4.push_back(13);
	it = vector4.begin();
	while (it != vector4.end()) {
		std::cout << "vector4 after push_back : " << *it++ << " | ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	vector4.pop_back();
	it = vector4.begin();
	while (it != vector4.end()) {
		std::cout << "vector after pop_back : " << *it++ << " | ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	vector.push_back(56);
	if (vector.empty())
		std::cout << "Vector1 is empty" << std::endl;
	else
		std::cout << "Vector1 is not empty" << std::endl;
	std::cout << "////////-- Map -- ////////" << std::endl;
	std::cout << std::endl;
	ft::map<int, std::string> first;
	first[0] = "salut";
	return 0;
}