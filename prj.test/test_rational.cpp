#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include <rational/rational.hpp>


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
	CHECK(7 == r.den());

	Rational h(5, -7);
	CHECK(-5 == h.num());
	CHECK(7 == h.den());

	Rational k(5, 20);
	CHECK(1 == k.num());
	CHECK(4 == k.den());
}

TEST_CASE("Even") {
	CHECK(Rational(-6, 7) == Rational(12, -14));
	CHECK(Rational(3, 4) < Rational(5, 6));
	CHECK(Rational(3, 4) <= Rational(5, 6));
	CHECK(Rational(5, 6) > Rational(3, 4));
	CHECK(Rational(5, 6) >= Rational(3, 4));
	CHECK(Rational(3, 4) > Rational(-5, 6));
	CHECK(Rational(3, 4) >= Rational(-5, 6));
	CHECK(Rational(-5, 6) < Rational(3, 4));
	CHECK(Rational(-5, 6) <= Rational(3, 4));
	CHECK(Rational(-3, 4) > Rational(-5, 6));
	CHECK(Rational(-3, 4) >= Rational(-5, 6));
	CHECK(Rational(-5, 6) < Rational(-3, 4));
	CHECK(Rational(-5, 6) <= Rational(-3, 4));
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
	t -= h;
	CHECK(t == Rational(6, 7));
	t *= h;
	CHECK(t == Rational(24, 35));
	t /= h;
	CHECK(t == Rational(6, 7));
	Rational a(45, 6);
	a++;
	CHECK(a == Rational(17, 2));
	a--;
	CHECK(a == Rational(45, 6));
	++a;
	CHECK(a == Rational(17, 2));
	--a;
	CHECK(a == Rational(45, 6));
}

TEST_CASE("aritmetics with negative numbers") {
	Rational t(-6, 7);
	Rational h(4, 5);
	CHECK(t + h == Rational(-2, 35));
	CHECK(t - h == Rational(-58, 35));
	CHECK(t * h == Rational(-24, 35));
	CHECK(t / h == Rational(-15, 14));
	t += h;
	CHECK(t == Rational(-2, 35));
	t -= h;
	CHECK(t == Rational(-6, 7));
	t *= h;
	CHECK(t == Rational(-24, 35));
	t /= h;
	CHECK(t == Rational(-6, 7));
	Rational a(-45, 6);
	a++;
	CHECK(a == Rational(-13, 2));
	a--;
	CHECK(a == Rational(-45, 6));
	++a;
	CHECK(a == Rational(-13, 2));
	--a;
	CHECK(a == Rational(-45, 6));
}

TEST_CASE("Rational input/output") {
	Rational t(1, 2);
	std::ostringstream output;
	output << t;
	CHECK(output.str() == "1/2");
}

