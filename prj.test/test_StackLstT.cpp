#include <iostream>
#include <StackLstT/StackLstT.hpp>

int main() {
	StackLstT<int> Stack;
	Stack.push(4);
	std::cout << Stack.top() << ' ' << Stack.size() << std::endl;
	Stack.push(5);
	std::cout << Stack.top() << ' ' << Stack.size() << std::endl;
	Stack.push(7);
	Stack.push(89);
	Stack.push(1);
	Stack.push(34);
	Stack.push(65);
	std::cout << "Stack size is: " << Stack.size() << ". And it contains: ";
	Stack.display();
}