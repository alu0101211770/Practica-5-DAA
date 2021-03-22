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
 * @brief Representation of a monomial
 */
class Polynomial {
 public:
  /**
   * @brief Construct a new Polynomial object
   */
  Polynomial();

  /**
   * @brief Construct a new Polynomial object
   *
   * @param coefficients Array containing the coefficients
   */
  Polynomial(std::vector<int> coefficients);

  /**
   * @brief Destroy the Polynomial object
   */
  ~Polynomial();

  /**
   * @brief Get the Degree object
   *
   * @return Degree of the polynomial
   */
  int getDegree() const;

  /**
   * @brief Get the Degree object
   *
   * @param Degree of the polynomial
   */
  void setDegree(int degree);

  /**
   * @brief Get the Terms object
   *
   * @return Terms of the polynomial
   */
  int getTerms() const;

  /**
   * @brief Inserts a monomial
   *
   * @param monomial Monomial to be inserted
   */
  void insert(Monomial monomial);

  /**
   * @brief Method that splits a vector in half
   *
   * @param lower_half Elements within the lower half
   * @param upper_half Elements within the upper half
   */
  void split(Polynomial &lower_half, Polynomial &upper_half);

  /**
   * @brief Method to access a monomial of the polynomial
   *
   * @param degree Of the monomial to access
   * @return Monomial accesed
   */
  Monomial at(int degree) const;

  /**
   * @brief Operator << overloading to print a polynomial
   *
   * @param os Output stream
   * @param monomial Polynomial to print
   * @return std::ostream&
   */
  friend std::ostream &operator<<(std::ostream &os,
                                  const Polynomial &polynomial);

  /**
   * @brief Operator [] overloading to access a monomial of the polynomial
   *
   * @param degree Of the monomial to access
   * @return Monomial accesed
   */
  Monomial operator[](int degree);

  /**
   * @brief Operator + overloading to add two polynomials
   *
   * @param y Second polynomial to add
   * @return Polynomial with the result of the addition
   */
  Polynomial operator+(const Polynomial &y);

  /**
   * @brief Operator - overloading to substract two polynomials
   *
   * @param y Second polynomial to substract
   * @return Polynomial with the result of the substraction
   */
  Polynomial operator-(const Polynomial &y);

  /**
   * @brief Operator * overloading to multiply a polynomial with a
   * exponent.
   *
   * @param y Integer exponent
   * @return Polynomial with the result of the multiplication
   */
  Polynomial operator*(const int &y);

 private:
  std::vector<Monomial> monomials_;
  std::map<int, int> positions_;
  int degree_;
  int terms_;
};

#endif
