#include <iostream>
#include <StackLstT/StackLstT.hpp>

int main() {
	StackLstT<int> Stack;
	Stack.push(4);
	std::cout << Stack.top() << ' ' << Stack.size() << std::endl;
	Stack.push(5);
	std::cout << Stack.top() << ' ' << Stack.size() << std::endl;
	Stack.push(7);
	std::cout << Stack.top() << ' ' << Stack.size() << std::endl;
	Stack.push(89);
	std::cout << Stack.top() << ' ' << Stack.size() << std::endl;
	Stack.push(1);
	std::cout << Stack.top() << ' ' << Stack.size() << std::endl;
	Stack.push(34);
	std::cout << Stack.top() << ' ' << Stack.size() << std::endl;
	Stack.push(65);
	std::cout << Stack.top() << ' ' << Stack.size() << std::endl;
	Stack.display();


	StackLstT<int> Stack2;
	Stack2.push(4);
	std::cout << Stack2.top() << ' ' << Stack2.size() << std::endl;
	Stack2.push(5);
	std::cout << Stack2.top() << ' ' << Stack2.size() << std::endl;
	Stack2.push(7);
	std::cout << Stack2.top() << ' ' << Stack2.size() << std::endl;
	Stack2.push(89);
	std::cout << Stack2.top() << ' ' << Stack2.size() << std::endl;
	Stack2.push(1);
	std::cout << Stack2.top() << ' ' << Stack2.size() << std::endl;
	Stack2.push(34);
	std::cout << Stack2.top() << ' ' << Stack2.size() << std::endl;
	Stack2.push(65);
	std::cout << Stack2.top() << ' ' << Stack2.size() << std::endl;
	Stack2.display();
	if (Stack == Stack2) {
		std::cout << "Ura pobeda";
	}
	else {
		std::cout << "huy";
	}
}