#include <iostream>
#include <BinaryTree/BinaryTree.hpp>

int main() {
	BinarySearchTree fuck;
	fuck.add(8);
	fuck.add(3);
	fuck.add(1);
	fuck.add(10);
	fuck.add(6);
	fuck.add(14);
	fuck.add(4);
	fuck.add(7);
	fuck.add(13);
	std::cout << "Worked? -";
	if (fuck.has(64)) {
		std::cout << "No ";
	}
	else {
		std::cout << "Yes ";
	}
	std::cout << fuck.find(54) << std::endl;
	std::cout << fuck.min() << std::endl;
	std::cout << fuck.max() << std::endl;
}