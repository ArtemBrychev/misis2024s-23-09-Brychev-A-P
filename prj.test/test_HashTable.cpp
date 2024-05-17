#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <vector>
#include "doctest.h"
#include "HashTable/HashTable.hpp"

TEST_CASE("Adding and returning keys and values(int, int edition)") {
	hashTable<int, int> table;
	int i(0), j(57);
	while (i < 57 && j>0) {
		table.insert(i, j);
		++i;
		--j;
	}
	i = 0;
	j = 57;
	while (i < 57 && j>0) {
		CHECK(table.contains(i) == true);
		++i;
		--j;
	}
	for (auto x : table) {
		CHECK(table[x.first] == x.second);
	}

	hashTable<int, int> table2;
	i = 0;
	j = 5;
	while (i < 5 && j>0) {
		table2.insert(i, j);
		++i;
		--j;
	}
	i = 0;
	j = 5;
	while (i < 5 && j>0) {
		CHECK(table2.contains(i) == true);
		++i;
		--j;
	}
	for (auto x : table2) {
		CHECK(table2[x.first] == x.second);
	}
}

TEST_CASE("Border patrol(Don't pay attention to it)") {
	hashTable<int, int> table;
	std::vector<int> borderline = { 4, 11, 34, 49, 30, 33, 52 };
	int i(0), j(57);
	while (i < 57 && j>0) {
		if (std::find(borderline.begin(), borderline.end(), i) == borderline.end()) {
			table.insert(i, j);
		}
		++i;
		--j;
	}
	i = 0;
	j = 57;
	//std::cout << " " << std::endl << "---------------------" << std::endl << " " << std::endl;
	int c = 0;
	for (auto x : table) {
		CHECK(table.contains(x.first) == true);
		CHECK(table[x.first] == x.second);
		//c++;
		//std::cout << x.first << ' ' << x.second << std::endl;
	}
	//std::cout << "Number of " << c;
}