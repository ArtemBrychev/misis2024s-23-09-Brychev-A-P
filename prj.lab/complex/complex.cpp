// 2022 by Polevoi Dmitry under Unlicense
#include "complex.hpp"
#include <cmath>
#include <iostream>

Complex Complex::operator-() const noexcept { return Complex(-re, -im); }

bool Complex::operator==(const Complex& rhs) const noexcept {
	if ((this->re == rhs.re) && (this->im == rhs.im)) {
		return true;
	}
	else {
		return false;
	}
}
bool Complex::operator!=(const Complex& rhs) const noexcept {
	if (this->re == rhs.re && this->im == rhs.im) {
		return false;
	}
	else {
		return true;
	}
}

Complex& Complex::operator+=(const Complex& rhs) noexcept {
	this->re  = this->re  + rhs.re;
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
	this->re  = a * rhs.re - b * rhs.im;
	this->im = a * rhs.im + b * rhs.re;
	return *this;
}
Complex& Complex::operator*=(const double rhs) noexcept {
	this->re = this->re * rhs;
	this->im = this->im * rhs;
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
	double a = this->re;
	double b = this->im;
	this->re = (a * rhs.re + b * rhs.im) / (pow(rhs.re, 2) + pow(rhs.im, 2));
	this->im = (b * rhs.re - a * rhs.im) / (pow(rhs.re, 2) + pow(rhs.im, 2));
	return *this;
}
Complex& Complex::operator/=(const double rhs) {
	this->re = this->re / rhs;
	this->im = this->im / rhs;
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
		if ((Complex::leftBrace == rightBrace) && (Complex::separator == comma) && (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaganery;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
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