#include <iostream>
#include "iStack/IStackBase.hpp"
#include "iStack/StackLstT(IBase).hpp"
#include "iStack/StackArrT(IBase).hpp"

int main() {
	StackLstT<int> stack;
	stack.push(7);
}