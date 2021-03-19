#include "../include/monomial.h"

Monomial::Monomial(int coefficient, int exponent) {
  coefficient_ = coefficient;
  exponent_ = exponent;
}

Monomial::~Monomial() {}

int Monomial::evaluate(int x) const {
  return coefficient_ * std::pow(exponent_, x);
}

int Monomial::getCoefficient() const {
  return coefficient_;
}

int Monomial::getExponent() const {
  return exponent_;
}

void Monomial::setCoefficient(int coefficient) {
  coefficient_ = coefficient;
}

void Monomial::setExponent(int exponent) {
  exponent_ = exponent;
}

std::ostream& operator<<(std::ostream& os, const Monomial& monomial) {
  // if () {

  // }
  os << monomial.coefficient_ << VARIABLE << '^' << monomial.exponent_;
  return os;
}