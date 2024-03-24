#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include <rational/rational.hpp>

//int main() {
//	Rational h;
//	Rational j(4, 5);
//	std::cout << h << " - " << h.num() << ' ' << h.den() << std::endl;
//	std::cout << h * j;
//	h += j;
//	std::cout << std::endl << h;
//}


TEST_CASE("rational ctor") {
  Rational r_def;
  CHECK(0 == r_def.num());
  CHECK(1 == r_def.den());

  Rational r_int(3);
  CHECK(3 == r_int.num());
  CHECK(1 == r_int.den());

  CHECK_THROWS(void(Rational(1, 0)));
}

TEST_CASE("Small functions") {
	Rational r(-5, 7);
	CHECK(-5 == r.num());
	CHECK(7 == r.

	/*Rational h(5, -7);
	CHECK(-5 == h.num());
	CHECK(7 == h.den());*/

	Rational k(5, 20);
	CHECK(1 == k.num());
	CHECK(4 == k.den());
	///Нужно внести сокращение дроби при создании или вводе, инкремент, декремент, посмотреть что там со сравнением.
}

TEST_CASE("aritmetics with positive numbers") {
	Rational t(6,  7);
	Rational h(4, 5);
	CHECK(t + h == Rational(58,35));
	CHECK(t - h == Rational(2, 35));
	CHECK(t * h == Rational(24, 35));
	CHECK(t / h == Rational(15, 14));
	t += h;
	CHECK(t == Rational(58, 35));
	///Реализовать операторы -=, +=, *=, /= для всех видов арифметики как написано выше(Только для тестов).
}

TEST_CASE("aritmetics with negative numbers") {
	Rational t(-6, 7);
	Rational h(4, 5);
	CHECK(t + h == Rational(2, 35));
	CHECK(t - h == Rational(-58, 35));
	CHECK(t * h == Rational(-24, 35));
	CHECK(t / h == Rational(-15, 14));
}

//TEST_CASE("Rational input/output") {
//	Rational t(1, 2);
//	std::ostringstream output;
//	output << t;
//	CHECK(output.str() == "1/2");
//	Rational m;
//	std::istringstream input("5");
//	input >> m;
//	CHECK(m == Rational(5, 3));
//}

