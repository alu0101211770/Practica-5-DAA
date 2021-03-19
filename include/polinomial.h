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

#include "monomial.h"
#include <vector>
#include <map>
#include <string>

/**
 * @brief Representation of a monomial 
 */
class Polinomial
{
 public:
  /**
   * @brief Construct a new Polinomial object
   */
  Polinomial();

  /**
   * @brief Construct a new Polinomial object
   * 
   * @param coefficients Array containing the coefficients
   * @param size Size of the coefficients
   */
  Polinomial(std::vector<int> coefficients);

  /**
   * @brief Destroy the Polinomial object
   */
  ~Polinomial();

  /**
   * @brief Operator << overloading to print a polinomial
   * 
   * @param os Output stream
   * @param monomial Polinomial to print
   * @return std::ostream& 
   */
  friend std::ostream& operator<<(std::ostream& os, const Polinomial& polinomial);

  /**
   * @brief Operator [] overloading to access a monomial of the polinomial
   * 
   * @param degree Of the monomial to access
   * @return Monomial accesed
   */
  Monomial operator[](int degree);

 private:
  std::vector<Monomial> monomials_;
  std::map<int, int> positions_;
  int degree_;
  int terms_;
};

#endif
