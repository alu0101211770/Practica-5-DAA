/**
 * University of La Laguna 
 * ESIT (Escuela Superior de Ingeniería y Tecnología)
 * Degree of Computer Engineering
 * Interactive Application Programming
 *
 * @author Alejandro Peraza González
 * @date 19 March 2021
 */

#include "../include/polinomial.h"

Polinomial::Polinomial() {}

Polinomial::~Polinomial() {}

Polinomial::Polinomial(std::vector<int> coefficients) {
  degree_ = coefficients.size() - 2;
  terms_ = coefficients.size() - 1;
  for (size_t i = 0; i < coefficients.size(); i++) {
    if (coefficients[i] != 0) {
      Monomial current_monomial(coefficients[i], i);
      monomials_.push_back(current_monomial);
      positions_[i] = monomials_.size() - 1;
      // std::cout << "degree: " << i << ' ';
      // std::cout << "location: " << positions_[i] << std::endl;
    }
  } 
}

std::ostream& operator<<(std::ostream& os, const Polinomial& polinomial) {
  for (size_t i = 0; i < polinomial.terms_; i++) {
    int coefficient = polinomial.monomials_[i].getCoefficient();
    if (coefficient != 0) {
      if (i != 0) {
        std::string sign = coefficient > 0 ? "+ " : "- ";
        os << sign;
      }
      os << polinomial.monomials_[i] << " ";
    }
  }
  
  return os;
}

Monomial Polinomial::operator[](int degree) {
  
}
