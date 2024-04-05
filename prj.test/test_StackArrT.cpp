#include <iostream>
#include <StackArrT/StackArrT.hpp>

int main() {
	StackArrT<int> Stack(4);
	std::cout << Stack.size() << std::endl;
	Stack.push(5);
	std::cout << Stack.top() << std::endl;
	int h = 7;
	Stack.push(h);
	std::cout << Stack.top() << std::endl;
	Stack.push(5);
	std::cout << Stack.top() << std::endl;
	Stack.push(34);
	std::cout << Stack.top() << std::endl;
	Stack.pop();
	std::cout << Stack.top() << std::endl;
	std::cout << "-------------------------" << std::endl;
	StackArrT<int> Stack2(4);
	std::cout << Stack2.size() << std::endl;
	Stack2.push(5);
	std::cout << Stack2.top() << std::endl;
	int j = 7;
	Stack2.push(j);
	Stack2.push(5);
	Stack2.push(34);
	std::cout << "-------------------------" << std::endl;
	Stack.merge(Stack2);
	std::cout << Stack.size() << std::endl;
}