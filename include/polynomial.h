/**
 * University of La Laguna
 * ESIT (Escuela Superior de Ingeniería y Tecnología)
 * Degree of Computer Engineering
 * Interactive Application Programming
 *
 * @author Alejandro Peraza González
 * @date 19 March 2021
 */

#ifndef POLINOMIAL_H_
#define POLINOMIAL_H_

#include <map>
#include <string>
#include <vector>

#include "monomial.h"

/**
 * @brief Representation of a Monomial.
 */
class Polynomial {
 public:
  /**
   * @brief Construct a new Polynomial object.
   */
  Polynomial();

  /**
   * @brief Construct a new Polynomial object.
   *
   * @param coefficients Array containing the coefficients.
   */
  Polynomial(std::vector<int> coefficients);

  /**
   * @brief Destroy the Polynomial object.
   */
  ~Polynomial();

  /**
   * @brief Get the Degree attribute.
   *
   * @return Degree of the Polynomial.
   */
  int getDegree() const;

  /**
   * @brief Get the Terms object.
   *
   * @return Terms of the Polynomial.
   */
  int getTerms() const;

  /**
   * @brief Inserts a Monomial into the vector of Monomials.
   *
   * @param monomial Monomial to be inserted.
   */
  void insert(Monomial monomial);

  /**
   * @brief Method that splits a Polynomial in half.
   *
   * @param lower_half Monomials within the lower half.
   * @param upper_half Monomials within the upper half.
   */
  void split(Polynomial &lower_half, Polynomial &upper_half);

  /**
   * @brief Method to access a Monomial of the Polynomial.
   *
   * @param degree Degree of the Monomial to access.
   * @return Monomial accesed.
   */
  Monomial at(int degree) const;

  /**
   * @brief Operator << overloading to print a Polynomial.
   *
   * @param os Output stream.
   * @param Polynomial Polynomial to print.
   * @return std::ostream&
   */
  friend std::ostream &operator<<(std::ostream &os,
                                  const Polynomial &polynomial);

  /**
   * @brief Operator [] overloading to access a Monomial of the Polynomial.
   *
   * @param degree Degree of the Monomial to access.
   * @return Monomial accesed.
   */
  Monomial operator[](int degree);

  /**
   * @brief Operator + overloading to add two Polynomials.
   *
   * @param y Second polynomial to add.
   * @return Polynomial with the result of the addition.
   */
  Polynomial operator+(const Polynomial &y);

  /**
   * @brief Operator - overloading to substract two Polynomials.
   *
   * @param y Second polynomial to substract.
   * @return Polynomial with the result of the substraction.
   */
  Polynomial operator-(const Polynomial &y);

  /**
   * @brief Operator * overloading to multiply a Polynomial with a
   * exponent.
   *
   * @param y Integer exponent.
   * @return Polynomial with the result of the multiplication.
   */
  Polynomial operator*(const int &y);

 private:
  std::vector<Monomial> monomials_;
  std::map<int, int> positions_;
  int degree_;
  int terms_;
};

#endif
