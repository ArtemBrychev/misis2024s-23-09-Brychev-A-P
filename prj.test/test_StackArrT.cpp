#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include <StackArrT/StackArrT.hpp>

TEST_CASE("Stack with int") {
	StackArrT<int> a;
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
	StackArrT<int> b(a);
	CHECK(3 == b.size());
	CHECK(78 == b.top());
	StackArrT<int> h;
	h = a;
	CHECK(3 == h.size());
	CHECK(78 == h.top());
}