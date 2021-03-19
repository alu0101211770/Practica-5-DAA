/**
 * University of La Laguna 
 * ESIT (Escuela Superior de Ingeniería y Tecnología)
 * Degree of Computer Engineering
 * Interactive Application Programming
 *
 * @author Alejandro Peraza González
 * @date 19 March 2021
 */

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
  if (monomial.coefficient_ != 0) {
    os << abs(monomial.coefficient_);
    if (monomial.exponent_ != 0) {
      os << VARIABLE;
      if (monomial.exponent_ != 1) {
        os << '^' << monomial.exponent_;
      }
    } 
  }
  return os;
}