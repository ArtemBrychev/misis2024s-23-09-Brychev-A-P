#include "final_test/IContainerBase2.hpp"
#include "final_test/CustomCLass.hpp"
#include <iostream>
#include <iostream>

int main() {
	CustomContainer jfk;
	for (int i = 0; i < 57; i++) {
		std::pair<int, int> p = { i, i + 24 };
		jfk.add(p);
	}
	for (int i = 0; i < 57; i++) {
		std::pair<int, int> p = { i, i + 24 };
		if (jfk.contains(p) == false) {
			std::cout << "fuck";
		}
	}
}