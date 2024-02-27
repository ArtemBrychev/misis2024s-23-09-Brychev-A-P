// 2022 by Polevoi Dmitry under Unlicense
#include <complex/complex.hpp>
#include <iostream>

int main() {
  Complex c1(23, 4);
  Complex c2(45, 12);
  Complex c3 = c1 / c2;
  Complex c4 = c1 * c2;
  std::cout << c3.re << ' ' << c3.im << std::endl;
  std::cout << c4.re << ' ' << c4.im;
}