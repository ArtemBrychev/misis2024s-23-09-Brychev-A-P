#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <complex/complex.hpp>
#include <iostream>
#include <sstream>

TEST_CASE("Inicialization") {
	Complex a(4, 6);
	CHECK(a == Complex(4, 6));
	Complex b(7);
	CHECK(b == Complex(7, 0));
	Complex c(5, 6);
	CHECK(-c == Complex(-5, -6));
}

TEST_CASE("Even") {
	Complex a(4, 5);
	Complex f(7, 8);
	CHECK(a != f);
	CHECK(a == Complex(4, 5));
	CHECK(a != Complex(7, 8));
}

TEST_CASE("Arithnetics") {
	Complex a(4, 5);
	Complex b(7, 8);
	CHECK(a + b == Complex(11, 13));
	CHECK(a - b == Complex(-3, -3));
	CHECK(a * b == Complex(-12, 67));
	CHECK(Complex(2, 1) / Complex(2, -1) == Complex(0.6, 0.8));
	CHECK(a + 2 == Complex(6, 5));
	CHECK(a - 2 == Complex(2, 5));
	CHECK(a * 2 == Complex(8, 10));
	CHECK(a / 2 == Complex(2, 2.5));
}

TEST_CASE("Input/output") {
	Complex t(1, 2);
	std::ostringstream output;
	output << t;
	CHECK(output.str() == "{1,2}");
	Complex m;
	std::istringstream input("{5,3}");
	input >> m;
	CHECK(m == Complex(5, 3));

}