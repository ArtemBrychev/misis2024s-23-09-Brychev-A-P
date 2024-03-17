#include "complex.hpp"
#include <cmath>
#include <iostream>
#include <sstream>


Complex Complex::operator-() const noexcept { return Complex(-re, -im); }

Complex& Complex::operator+=(const Complex& rhs) noexcept {
	this->re = this->re + rhs.re;
	this->im = this->im + rhs.im;
	return *this;
}
Complex& Complex::operator+=(const double rhs) noexcept { return operator+=(Complex(rhs)); }

Complex& Complex::operator-=(const Complex& rhs) noexcept {
	this->re = this->re - rhs.re;
	this->im = this->im - rhs.im;
	return *this;
}
Complex& Complex::operator-=(const double rhs) noexcept { return operator-=(Complex(rhs)); }

Complex& Complex::operator*=(const Complex& rhs) noexcept {
	double a = this->re;
	double b = this->im;
	this->re = a * rhs.re - b * rhs.im;
	this->im = a * rhs.im + b * rhs.re;
	return *this;
}
Complex& Complex::operator*=(const double rhs) noexcept {
	this->re = this->re * rhs;
	this->im = this->im * rhs;
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
	if (rhs.re == 0 && rhs.im == 0) {
		throw std::runtime_error("Div by zero");
	}
	else {
		auto real = float(re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
		auto imagin = float(im * rhs.re - re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
		re = real;
		im = imagin;
	}
	return *this;
}
Complex& Complex::operator/=(const double rhs) {
	if (rhs == 0) {
		throw std::runtime_error("Div by zero");
	}
	else {
		this->re = this->re / rhs;
		this->im = this->im / rhs;
		return *this;
	}
	return *this;

}

std::ostream& Complex::WriteTo(std::ostream& ostrm) const noexcept {
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}
std::istream& Complex::ReadFrom(std::istream& istrm) noexcept {
	char leftBrace(0);
	double real(0.0);
	char comma(0);
	double imaganery(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaganery >> rightBrace;
	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) && (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaganery;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}

void Complex::conjugate() {
	im *= -1;
}

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }
Complex operator+(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) += rhs; }
Complex operator+(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }
Complex operator-(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) -= rhs; }
Complex operator-(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }
Complex operator*(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) *= rhs; }
Complex operator*(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }

Complex operator/(const Complex& lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }
Complex operator/(const Complex& lhs, const double rhs) { return Complex(lhs) /= rhs; }
Complex operator/(const double lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }