#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include <StackArrT/StackArrT.hpp>

//int main() {
//	StackArrT<int> a(4);
//	StackArrT<std::string> b(3);
//	b.push("Hello, world!");
//	b.push("by by");
//	b.pop();
//	StackArrT<std::string> h(3);
//	h = b;
//	StackArrT<std::string> j(3);
//	j.push("This can go fuck itself");
//	j.push("Sorry for bad words");
//	j.swap(h);
//	std::cout << "Last try " << j.top();
//	
//}

TEST_CASE("Creating stacks") {
	StackArrT<int> a(4);
	CHECK(4 == a.size());
	CHECK(a.empty() == true);
	StackArrT<std::string> b(3);
	CHECK(3 == b.size());
	CHECK(b.empty() == true);
	b.push("Hello, world!");
	CHECK(b.top() == "Hello, world!");
	CHECK(b.empty() == false);
	b.push("by by");
	b.pop();
	CHECK(b.top() == "Hello, world!");
	StackArrT<std::string> h(3);
	h = b;
	CHECK(h.top() == "Hello, world!");
	StackArrT<std::string> j(3);
	j.push("This can go fuck itself");
	j.push("Sorry for bad words");
	j = h;
 	CHECK(j.top() == "Hello, world!");
}