#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include <BinaryTree/BinaryTree.hpp>

TEST_CASE("Testing tree") {
	BinarySearchTree tree;
	tree.add(8);
	tree.add(3);
	tree.add(1);
	tree.add(10);
	tree.add(6);
	tree.add(14);
	tree.add(4);
	tree.add(7);
	tree.add(13);
	int arr[9] = { 8, 3, 1, 10, 6, 14, 4, 7, 13 };
	for (auto x : arr) {
		CHECK(tree.has(x) == true);
	}
	for (int i = 15; i < 20; ++i) {
		CHECK(tree.has(i) != true);
	}
	CHECK(tree.root() == tree.find(8));
	CHECK(tree.min() == 1);
	CHECK(tree.max() == 14);
}

TEST_CASE("TEsting pesky remove fucntion"){
	BinarySearchTree tree;
	tree.add(8);
	tree.add(334);
	tree.add(123);
	tree.add(10);
	tree.add(65);
	tree.add(4);
	tree.add(45);
	tree.add(7);
	tree.add(1);
	CHECK(tree.min() == 1);
	CHECK(tree.max() == 334);
	tree.remove(1);
	tree.remove(334);
	CHECK(tree.max() == 123);
	CHECK(tree.min() == 4);
	tree.remove(65);
	CHECK(tree.has(65) == false);
}

TEST_CASE("Should I really remove root of the tree?") {
	BinarySearchTree tree;
	tree.add(8);
	tree.remove(8);
	CHECK(tree.has(8) == false);
	tree.add(8);
	tree.add(3);
	tree.remove(3);
	CHECK(tree.has(3) == false);
	tree.add(3);
	tree.add(1);
	tree.add(10);
	tree.remove(10);
	CHECK(tree.has(10) == false);
	tree.add(10);
	tree.add(6);
	tree.add(14);
	tree.add(4);
	tree.add(7);
	tree.add(13);
	tree.remove(8);
	CHECK(tree.root() == tree.find(10));
}
