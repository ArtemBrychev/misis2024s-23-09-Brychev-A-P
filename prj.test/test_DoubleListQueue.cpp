#include <iostream>
#include <DoubleListQueue/DoubleListQueue.hpp>

int main() {
	DoubleListQueue<std::string> a;
	a.push("4f");
	std::cout << a.getSize() << ' ' << a.getBack() << std::endl;
	a.push("5f");
	std::cout <<a.getSize() << ' ' <<  a.getBack() << ' ' << a.getFront() << std::endl;
	a.push("56f");
	std::cout << a.getSize() << ' ' << a.getBack() << ' ' << a.getFront() << std::endl;
	std::cout << a.top() << std::endl;
	std::cout << a.getSize() << ' ' <<  a.getBack() << ' ' << a.getFront() << std::endl;

}