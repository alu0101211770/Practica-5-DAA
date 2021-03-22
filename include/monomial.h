/**
 * University of La Laguna 
 * ESIT (Escuela Superior de Ingeniería y Tecnología)
 * Degree of Computer Engineering
 * Interactive Application Programming
 *
 * @author Alejandro Peraza González
 * @date 19 March 2021
 */

#ifndef MONOMIAL_H_
#define MONOMIAL_H_

#include <iostream>
#include <math.h>
#include <exception>

const char VARIABLE = 'x';

/**
 * @brief Representation of a Monomial .
 */
class Monomial {
 public:
  /**
   * @brief Construct a new Monomial object.
   */
  Monomial();

  /**
   * @brief Construct a new Monomial object.
   * 
   * @param coefficient Coefficient of the Monomial.
   * @param exponent Exponent of the Monomial.
   */
  Monomial(int coefficient, int exponent);

  /**
   * @brief Destroy the Monomial object.
   */
  ~Monomial();

  /**
   * @brief Evaluates the Monomial given an value of x.
   * 
   * @param x Value of x given.
   * @return Value obtained after replacing the x.
   */
  int evaluate(int x) const;

  /**
   * @brief Get the Coefficient attribute.
   * 
   * @return Coefficient of the Monomial.
   */
  int getCoefficient() const;

  /**
   * @brief Get the Exponent attribute.
   * 
   * @return Exponent of the Monomial.
   */
  int getExponent() const;

  /**
   * @brief Set the Coefficient attribute.
   * 
   * @param coefficient Coefficient of the Monomial.
   */
  void setCoefficient(int coefficient);

  /**
   * @brief Set the Exponent attribute.
   * 
   * @param exponent Exponent of the Monomial.
   */
  void setExponent(int exponent);
  
  /**
   * @brief Operator << overloading to print a Monomial.
   * 
   * @param os Output stream.
   * @param monomial Monomial to print.
   * @return std::ostream& 
   */
  friend std::ostream& operator<<(std::ostream& os, const Monomial& monomial);

  /**
   * @brief Operator + overloading to add two Monomials.
   * 
   * @param y Second monomial to add.
   * @return Monomial with the result of the addition.
   */
  Monomial operator+(const Monomial &y);

  /**
   * @brief Operator - overloading to substract two Monomials.
   * 
   * @param y Second Monomial to substract.
   * @return Monomial with the result of the substraction.
   */
  Monomial operator-(const Monomial &y);

  /**
   * @brief Operator * overloading to multiply two Monomials.
   * 
   * @param y Second Monomial to multiply.
   * @return Monomial with the result of the multiplication.
   */
  Monomial operator*(const Monomial &y);

 private:
  int coefficient_;
  int exponent_;
};

#endif
