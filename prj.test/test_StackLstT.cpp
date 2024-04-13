#include <iostream>
#include <StackLstT/StackLstT.hpp>

int main() {
	StackLstT<int> Stack;
	Stack.push(4);
	std::cout << Stack.top() << ' ' << Stack.size() << std::endl;
	Stack.push(5);
	std::cout << Stack.top() << ' ' << Stack.size() << std::endl;
	Stack.pop();
	std::cout << Stack.top() << ' ' << Stack.size() << std::endl;

}