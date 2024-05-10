#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include <StackLstT/StackLstT.hpp>


TEST_CASE("Stack with int") {
	StackLstT<int> a;
	a.push(6);
	CHECK(1 == a.size());
	CHECK(6 == a.top());
	a.push(7);
	CHECK(2 == a.size());
	CHECK(7 == a.top());
	a.pop();
	CHECK(1 == a.size());
	CHECK(6 == a.top());
	a.push(-4);
	CHECK(2 == a.size());
	CHECK(-4 == a.top());
	a.push(78);
	CHECK(3 == a.size());
	CHECK(78 == a.top());
	StackLstT<int> b(a);
	CHECK(3 == b.size());
	CHECK(78 == b.top());
	b.push(32);
	StackLstT<int> h;
	h = a;
	CHECK(3 == h.size());
	CHECK(78 == h.top());
	CHECK(true == (h == a));
	CHECK(false == (a == b));
	CHECK(false == (h != a));
	CHECK(true == (a != b));
	b.swap(h);
	CHECK(false == (h == a));
	CHECK(true == (b == a));
	h.merge(b);
	CHECK(7 == h.size());
	CHECK(78 == h.top());
}

TEST_CASE("Stack with string") {
	StackLstT<std::string> a;
	a.push("6");
	CHECK(1 == a.size());
	CHECK("6" == a.top());
	a.push("7");
	CHECK(2 == a.size());
	CHECK("7" == a.top());
	a.pop();
	CHECK(1 == a.size());
	CHECK("6" == a.top());
	a.push("- 4");
	CHECK(2 == a.size());
	CHECK("- 4" == a.top());
	a.push("78");
	CHECK(3 == a.size());
	CHECK("78" == a.top());
	StackLstT<std::string> b(a);
	CHECK(3 == b.size());
	CHECK("78" == b.top());
	b.push("32");
	StackLstT<std::string> h;
	h = a;
	CHECK(3 == h.size());
	CHECK("78" == h.top());
	CHECK(true == (h == a));
	CHECK(false == (a == b));
	CHECK(false == (h != a));
	CHECK(true == (a != b));
	b.swap(h);
	CHECK(false == (h == a));
	CHECK(true == (b == a));
	h.merge(b);
	CHECK(7 == h.size());
	CHECK("78" == h.top());
}

TEST_CASE("Stack with double") {
	StackLstT<double> a;
	a.push(6.7);
	CHECK(1 == a.size());
	CHECK(6.7 == a.top());
	a.push(7.7);
	CHECK(2 == a.size());
	CHECK(7.7 == a.top());
	a.pop();
	CHECK(1 == a.size());
	CHECK(6.7 == a.top());
	a.push(-4.7);
	CHECK(2 == a.size());
	CHECK(-4.7 == a.top());
	a.push(78.7);
	CHECK(3 == a.size());
	CHECK(78.7 == a.top());
	StackLstT<double> b(a);
	CHECK(3 == b.size());
	CHECK(78.7 == b.top());
	b.push(32.7);
	StackLstT<double> h;
	h = a;
	CHECK(3 == h.size());
	CHECK(78.7 == h.top());
	CHECK(true == (h == a));
	CHECK(false == (a == b));
	CHECK(false == (h != a));
	CHECK(true == (a != b));
	b.swap(h);
	CHECK(false == (h == a));
	CHECK(true == (b == a));
	h.merge(b);
	CHECK(7 == h.size());
	CHECK(78.7 == h.top());
}

TEST_CASE("shit that dont work") {
	StackLstT<int> stack = { 1, 2, 3 };
	CHECK(stack.top() == 3);
	CHECK(stack.size() == 3);
	int i = 3;
	while (!stack.empty()) {
		CHECK(stack.top() == i);
		stack.pop();
		--i;
	}
}


