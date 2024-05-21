#include "IContainerBase/IContainerBase.hpp"
#include "IContainerBase/CustomCLass.hpp"
#include <iostream>

int main() {
	CustomContainer fuck;
	for (int i = 6; i < 9; ++i) {
		fuck.add(i);
		std::cout << fuck.contains(i) << std::endl;
	}
	std::cout << fuck.contains(14) << std::endl;
	std::cout << fuck.contains(6);
}