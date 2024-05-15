#include <iostream>
#include "HashTable/HashTable.hpp"

int main() {
	hashTable<int, int> g;
	g.insert(5, 6);
	g.insert(4, 8);
	std::cout << g.contains(5) << " " << g.contains(4) << " " << g.contains(45) << std::endl;
	std::cout << g[4] << " " << g[5];
}