#include "../include/polinomial.h"

Polinomial::Polinomial() {}

Polinomial::~Polinomial() {}

Polinomial::Polinomial(std::vector<int> coefficients) {
  degree_ = coefficients.size() - 2;
  terms_ = coefficients.size() - 1;
  for (size_t i = 0; i < coefficients.size(); i++) {
    Monomial current_monomial(coefficients[i], i);
    monomials_.push_back(current_monomial);
  }

  for (size_t i = 0; i < monomials_.size(); i++) {
    std::cout << monomials_[i] << " ";
  } std::cout << std::endl;
  
}
