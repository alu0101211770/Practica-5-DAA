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
 * @brief Representation of a monomial 
 */
class Monomial {
 public:
  /**
   * @brief Construct a new Monomial object
   */
  Monomial();

  /**
   * @brief Construct a new Monomial object
   * 
   * @param coefficient Coefficient of the monomial
   * @param exponent Exponent of the monomial
   */
  Monomial(int coefficient, int exponent);

  /**
   * @brief Destroy the Monomial object
   */
  ~Monomial();

  /**
   * @brief Evaluates the monomial given an 'x'
   * 
   * @param x 
   * @return int 
   */
  int evaluate(int x) const;

  /**
   * @brief Get the Coefficient object
   * 
   * @return Coefficient of the monomial
   */
  int getCoefficient() const;

  /**
   * @brief Get the Exponent object
   * 
   * @return Exponent of the monomial
   */
  int getExponent() const;

  /**
   * @brief Set the Coefficient object
   * 
   * @param coefficient Coefficient of the monomial
   */
  void setCoefficient(int coefficient);

  /**
   * @brief Set the Exponent object
   * 
   * @param exponent Exponent of the monomial
   */
  void setExponent(int exponent);
  
  /**
   * @brief Operator << overloading to print a monomial
   * 
   * @param os Output stream
   * @param monomial Monomial to print
   * @return std::ostream& 
   */
  friend std::ostream& operator<<(std::ostream& os, const Monomial& monomial);

  /**
   * @brief Operator >> overloading to read a monomial
   * 
   * @param is Intput stream
   * @param monomial Monomial to save read the information in
   * @return std::istream& 
   */
  friend std::istream& operator>>(std::istream& is, const Monomial& monomial);

  /**
   * @brief Operator + overloading to add two monomials
   * 
   * @param x First monomial to add
   * @param y Second monomial to add
   * @return Monomial with the result of the add
   */
  Monomial operator+(const Monomial &y);

 private:
  int coefficient_;
  int exponent_;
};

#endif
