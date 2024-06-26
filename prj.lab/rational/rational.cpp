#include <rational/rational.hpp>

#include <stdexcept>
#include <iostream>
#include <sstream>

int64_t nod(int64_t a, int64_t b) {
    if (a < 0) {
        a = a * -1;
        while (a && b)
            if (a > b) a %= b;
            else b %= a;
        return a + b;
    }
    else {
        while (a && b)
            if (a > b) a %= b;
            else b %= a;
        return a + b;
    }
}

Rational::Rational(const std::int64_t num, const std::int64_t den):num_(num), den_(den)
{
  if (0 == den_) {
    throw std::invalid_argument("Zero denumenator in Rational ctor");
  }
  else {
      if (den < 0) {
          num_ = -1 * num / nod(-1 * num, -1 * den);
          den_ = -1 * den / nod(-1 * num, -1 * den);
      }
      else {
          num_ = num / nod(num, den);
          den_ = den / nod(num, den);
      }
  }
}

bool Rational::operator==(const Rational& rhs) const noexcept {
    if (this->num_ * rhs.den_ == rhs.num_ * this->den_) {
        return true;
    }
    else {
        return false;
    }
}
bool Rational::operator!=(const Rational& rhs) const noexcept {
    if (this == &rhs) {
        return false;
    }
    else{
        return true;
    }
}
bool Rational::operator<(const Rational& rhs) const noexcept { 
    if ((this->num_ * rhs.den_) < (rhs.num_ * this->den_)) {
        return true;
    }
    else {
        return false;
    }
}
bool Rational::operator<=(const Rational& rhs) const noexcept { 
    if (((this->num_ * rhs.den_) < (rhs.num_ * this->den_)) or (this->num_ * rhs.den_ == rhs.num_ * this->den_)) {
        return true;
    }
    else {
        return false;
    }
}
bool Rational::operator>(const Rational& rhs) const noexcept {
    if ((this->num_ * rhs.den_) > (rhs.num_ * this->den_)) {
        return true;
    }
    else {
        return false;
    }
}
bool Rational::operator>=(const Rational& rhs) const noexcept { 
    if (((this->num_ * rhs.den_) < (rhs.num_ * this->den_) or (this->num_ * rhs.den_ == rhs.num_ * this->den_))) {
        return false;
    }
    else {
        return true;
    }
}

Rational& Rational::operator+=(const Rational& rhs) noexcept { 
    int64_t n = this->num_ * rhs.den_ + this->den_ * rhs.num_;
    int64_t d = this->den_ * rhs.den_;
    this->num_ = n / nod(n, d);
    this->den_ = d / nod(n, d);
    return *this;
};
Rational& Rational::operator-=(const Rational& rhs) noexcept {
    int64_t n = this->num_ * rhs.den_ - this->den_ * rhs.num_;
    int64_t d = this->den_ * rhs.den_;
    this->num_ = n / nod(n, d);
    this->den_ = d / nod(n, d);
    return *this;
};
Rational& Rational::operator*=(const Rational& rhs) noexcept { 
    int64_t n = this->num_  * rhs.num_;
    int64_t d = this->den_ * rhs.den_;
    this->num_ = n / nod(n, d);
    this->den_ = d / nod(n, d);
    return *this;
};
Rational& Rational::operator/=(const Rational& rhs) {
    if (rhs.num_ != 0) {
        int64_t n = this->num_ * rhs.den_;
        int64_t d = this->den_ * rhs.num_;
        this->num_ = n / nod(n, d);
        this->den_ = d / nod(n, d);
        return *this;
    }
    else {
        throw std::invalid_argument("Dividing by zero");
    }
};

Rational& Rational::operator+=(const int64_t rhs) noexcept { return operator+=(Rational(rhs)); };
Rational& Rational::operator-=(const int64_t rhs) noexcept { return operator-=(Rational(rhs)); };
Rational& Rational::operator*=(const int64_t rhs) noexcept { return operator*=(Rational(rhs)); };
Rational& Rational::operator/=(const int64_t rhs) { return operator/=(Rational(rhs)); };


Rational operator+(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } += rhs; }
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } -= rhs; }
Rational operator*(const Rational& lhs, const Rational& rhs) noexcept { return Rational{ lhs } *= rhs; }
Rational operator/(const Rational& lhs, const Rational& rhs) { return Rational{lhs} /= rhs; }

Rational operator+(const Rational& lhs, const int64_t rhs) noexcept { return Rational{ lhs } += rhs; }
Rational operator-(const Rational& lhs, const int64_t rhs) noexcept { return Rational{ lhs } -= rhs; };
Rational operator*(const Rational& lhs, const int64_t rhs) noexcept { return Rational{ lhs } *= rhs; };
Rational operator/(const Rational& lhs, const int64_t rhs) { return Rational{ lhs } /= rhs; }

Rational operator+(const int64_t lhs, const Rational& rhs) noexcept { return operator+(rhs, lhs); }
Rational operator-(const int64_t lhs, const Rational& rhs) noexcept { return operator+(rhs, lhs); }
Rational operator*(const int64_t lhs, const Rational& rhs) noexcept { return operator+(rhs, lhs); }
Rational operator/(const int64_t lhs, const Rational& rhs) { return operator+(rhs, lhs); }

Rational& Rational::operator++() {
    num_ += den_;
    return *this;
}

Rational& Rational::operator++(int) {
    Rational temp = *this;
    ++(*this);
    return temp;
}

Rational& Rational::operator--() {
    num_ -= den_;
    return *this;
}

Rational& Rational::operator--(int) {
    Rational temp = *this;
    --(*this);
    return temp;
}



std::istream& Rational::ReadFrom(std::istream& istrm) noexcept {
    std::int64_t numerator(0);
    char comma(0);
    std::int64_t denominator(0);
    istrm >> numerator >> comma >> denominator;
    if (istrm.good()) {
        if ((Rational::separator == comma) and (denominator != 0)) {
            num_ = numerator;
            den_ = denominator;
        }
        else if (denominator == 0) {
            throw std::invalid_argument("Zero denumenator in Rational ctor");
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

std::ostream& Rational::WriteTo(std::ostream& ostrm) const noexcept {
    ostrm << num_ << separator << den_;
    return ostrm;
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept {
    return rhs.WriteTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept {
    return rhs.ReadFrom(istrm);
}
