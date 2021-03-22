/**
 * University of La Laguna
 * ESIT (Escuela Superior de Ingeniería y Tecnología)
 * Degree of Computer Engineering
 * Interactive Application Programming
 *
 * @author Alejandro Peraza González
 * @date 19 March 2021
 */

#include "../include/polynomial.h"

Polynomial::Polynomial() {
  degree_ = -1;
  terms_ = 0;
}

Polynomial::~Polynomial() {}

Polynomial::Polynomial(std::vector<int> coefficients) {
  degree_ = coefficients.size() - 1;
  terms_ = coefficients.size();
  for (size_t i = 0; i < coefficients.size(); i++) {
    if (coefficients[i] != 0) {
      Monomial current_monomial(coefficients[i], i);
      monomials_.push_back(current_monomial);
    }
  }
}

int Polynomial::getDegree() const { return degree_; }

void Polynomial::setDegree(int degree) { degree_ = degree; }

int Polynomial::getTerms() const { return terms_; }

void Polynomial::insert(Monomial monomial) {
  monomials_.push_back(monomial);
  degree_++;
  terms_++;
}

void Polynomial::split(Polynomial &lower_half, Polynomial &upper_half) {
  int half = terms_ / 2;
  for (size_t i = 0; i < monomials_.size(); i++) {
    if (i < half) {
      lower_half.insert(at(i));
    } else {
      Monomial upper_monomial = at(i);
      upper_monomial.setExponent(upper_monomial.getExponent() - half);
      upper_half.insert(upper_monomial);
    }
  }
}

std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial) {
  bool first = true;

  for (size_t i = 0; i < polynomial.monomials_.size(); i++) {
    Monomial currentMonomial = polynomial.at(i);
    int coefficient = currentMonomial.getCoefficient();
    if (coefficient != 0) {
      if (!first) {
        std::string sign = coefficient > 0 ? "+ " : "- ";
        os << sign;
      } else {
        first = false;
      }
      os << currentMonomial << " ";
    }
  }
  return os;
}

Monomial Polynomial::at(int degree) const {
  if (degree > degree_) {
    Monomial zero(0, degree);
    return zero;
  }
  return monomials_[degree];
}

Monomial Polynomial::operator[](int degree) { return at(degree); }

Polynomial Polynomial::operator+(const Polynomial &y) {
  Polynomial result;
  size_t it1 = 0;
  size_t it2 = 0;

  while (it1 < monomials_.size() && it2 < y.monomials_.size()) {
    Monomial m1 = at(it1);
    Monomial m2 = y.at(it2);
    if (m1.getExponent() < m2.getExponent()) {
      result.insert(m1);
      it1++;
    } else if (m1.getExponent() > m2.getExponent()) {
      result.insert(m2);
      it2++;
    } else {
      result.insert(m1 + m2);
      it1++;
      it2++;
    }
  }
  while (it1 < monomials_.size()) {
    result.insert(at(it1++));
  }
  while (it2 < y.monomials_.size()) {
    result.insert(y.at(it2++));
  }
  // !
  return result;
}

Polynomial Polynomial::operator-(const Polynomial &y) {
  Polynomial result;
  size_t it1 = 0;
  size_t it2 = 0;

  while (it1 < monomials_.size() && it2 < y.monomials_.size()) {
    Monomial m1 = at(it1);
    Monomial m2 = y.at(it2);
    if (m1.getExponent() < m2.getExponent()) {
      result.insert(m1);
      it1++;
    } else if (m1.getExponent() > m2.getExponent()) {
      result.insert(m2);
      it2++;
    } else {
      result.insert(m1 - m2);
      it1++;
      it2++;
    }
  }
  while (it1 < monomials_.size()) {
    result.insert(at(it1++));
  }
  while (it2 < y.monomials_.size()) {
    result.insert(y.at(it2++));
  }
  // !

  return result;
}
// TODO
Polynomial Polynomial::operator*(const int &y) {
  Polynomial result;
  result.degree_ = y - 1;
  result.terms_ = y - 1;

  for (int i = 0; i < terms_; i++) {
    Monomial current_monomial = at(i);
    current_monomial.setExponent(current_monomial.getExponent() + y);
    result.insert(current_monomial);
  }
  return result;
}