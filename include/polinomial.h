/**
 * Universidad de La Laguna
 * ESIT (Escuela Superior de Ingeniería y Tecnología)
 * Grado de Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Alejandro Peraza González
 * @date 19 Marzo 2021
 */

#ifndef POLINOMIAL_H_
#define POLINOMIAL_H_

#include "monomial.h"
#include <vector>

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

 private:
  std::vector<Monomial> monomials_;
  int degree_;
  int terms_;
};

#endif
