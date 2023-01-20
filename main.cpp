#include <iostream>
#include <string>
#include <deque>
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
	for (int i = 0; i < 4; i++)
		std::cout<< "vector through index : " << vector2[i] << " ";
	std::cout << std::endl;
	ft::vector<int>::iterator it(vector3.begin());
	while (it != vector3.end()) {
		std::cout << "vector through iterator : " << *it++ << " ";
	}
	std::cout << std::endl;
	it = vector4.begin();
	while (it != vector4.end()) {
		std::cout << "vector through iterator : " << *it++ << " ";
	}
	std::cout << std::endl;
	vector4.push_back(13);
	std::cout << "vector push_back : " << ++*it << std::endl;
	vector4.pop_back();
	it = vector4.begin();
	while (it != vector4.end()) {
		std::cout << "vector after pop_back : " << *it++ << " ";
	}
	std::cout << std::endl;
	if (vector.empty())
		std::cout << "Vector is empty" << std::endl;
	else
		std::cout << "Vector has size of " << vector4.size() << std::endl;
	return 0;
}