// 2022 by Polevoi Dmitry under Unlicense
#include <complex/complex.hpp>
#include <cmath>

Complex Complex::operator-() const noexcept { return Complex(-re, -im); }

bool Complex::operator==(const Complex& rhs) const noexcept {
	if (this->re == rhs.re and this->im == rhs.im) {
		return true;
	}
	else {
		return false;
	}
}
bool Complex::operator!=(const Complex& rhs) const noexcept {
	if (this->re == rhs.re and this->im == rhs.im) {
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
	this->re  = this->re * rhs.re - this->im * rhs.im;
	this->im = this->re * rhs.im + this->im * rhs.re;
	return *this;
}
Complex& Complex::operator*=(const double rhs) noexcept {
	this->re = this->re * rhs;
	this->im = this->im * rhs;
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
	this->re = (this->re * rhs.re + this->im * rhs.im) / (pow(rhs.re, 2) + pow(rhs.im, 2));
	this->im = (this->im * rhs.re - this->re * rhs.im) / (pow(rhs.re, 2) + pow(rhs.im, 2));
	return *this;
}
Complex& Complex::operator/=(const double rhs) {
	this->re = this->re / rhs;
	this->im = this->im / rhs;
	return *this;
}

std::ostream& Complex::WriteTo(std::ostream& ostrm) const noexcept { return ostrm; }
std::istream& Complex::ReadFrom(std::istream& istrm) noexcept { return istrm; }


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