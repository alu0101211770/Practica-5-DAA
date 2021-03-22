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
  // TODO PENSAR
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
      positions_[i] = monomials_.size() - 1;
      // std::cout << i << ' ' << positions_[i] << ' ' << at(i) << std::endl;
      // std::cout << "degree: " << i << ' ';
      // std::cout << "location: " << positions_[i] << std::endl;
    }
  }
}

int Polynomial::getDegree() const { return degree_; }

void Polynomial::setDegree(int degree) { degree_ = degree; }

int Polynomial::getTerms() const { return terms_; }

void Polynomial::insert(Monomial monomial) {
  monomials_.push_back(monomial);
  positions_[++degree_] = monomials_.size() - 1;
  terms_++;
}

void Polynomial::split(Polynomial &lower_half, Polynomial &upper_half) {
  // std::cout << terms_ / 2 << std::endl;
  int half = terms_ / 2;
  //TODO first / second
  for (auto it = positions_.begin(); it != positions_.end(); it++) {
    if (it->first < half) {
      // std::cout << it->first << " " << it->second << std::endl;
      // std::cout << at(it->second) << std::endl;
      lower_half.insert(at(it->first));
    } else {
      // std::cout << it->first << ' ' << at(it->second) << std::endl;
      Monomial upper_monomial = at(it->first);
      // std::cout << it->first << " " << it->second << std::endl;
      // std::cout << upper_monomial << std::endl;
      upper_monomial.setExponent(upper_monomial.getExponent() - half);
      upper_half.insert(upper_monomial);
    }
    // std::cout << it->first << " " << it->second << ' ' << at(it->first) <<
    // std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial) {
  bool first = true;
  for (int i = 0; i < polynomial.terms_; i++) {
    Monomial currentMonomial = polynomial.at(i);
    // std::cout << i << ": ";
    // std::cout << currentMonomial << std::endl;
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
  auto it = positions_.find(degree);
  if (it == positions_.end()) {
    Monomial zero(0, degree);
    return zero;
  }
  return monomials_[it->second];
}

Monomial Polynomial::operator[](int degree) { return at(degree); }

Polynomial Polynomial::operator+(const Polynomial &y) {
  Polynomial result;
  // std::cout << result.getTerms() << std::endl;
  // int terms = y.getTerms();
  // std::cout << terms_ << std::endl;
  // std::cout << terms_ << ' ' << y.getTerms() << std::endl;
  int terms = terms_ >= y.getTerms() ? terms_ : y.getTerms();
  for (int i = 0; i < terms; i++) {
    // std::cout << at(i) << " + " << y.at(i) << std::endl;
    result.insert(at(i) + y.at(i));
  }
  return result;
}

Polynomial Polynomial::operator-(const Polynomial &y) {
  Polynomial result;
  int terms = terms_ >= y.getTerms() ? terms_ : y.getTerms();
  for (int i = 0; i < terms; i++) {
    result.insert(at(i) - y.at(i));
  }
  return result;
}
// TODO
void Polynomial::operator*(const int &y) {
  // std::cout << getDegree() << " " <<  getTerms() << std::endl;
  Polynomial result;
  result.setDegree(y - 1);
  result.terms_ = y;
  result.positions_.clear();
  for (int i = 0; i < terms_; i++) {
    Monomial current_monomial = at(i);
    current_monomial.setExponent(current_monomial.getExponent() + y);
    result.insert(current_monomial);
  }
  // std::cout << getTerms() << std::endl;
  *this = result;
  // std::cout << getTerms() << std::endl;
  // for (auto i = positions_.begin(); i != positions_.end(); i++) {
  //   std::cout << i->first << ' ' << i->second << std::endl;
  // }
}