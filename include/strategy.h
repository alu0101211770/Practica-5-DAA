/**
 * University of La Laguna
 * ESIT (Escuela Superior de Ingeniería y Tecnología)
 * Degree of Computer Engineering
 * Interactive Application Programming
 *
 * @author Alejandro Peraza González
 * @date 19 March 2021
 */

#ifndef STRATEGY_H_
#define STRATEGY_H_

#include "polynomial.h"

/**
 * @brief Parent Strategy class
 */
class Strategy {
 public:
  /**
   * @brief Destroy the Strategy object.
   */
  virtual ~Strategy() = default;

  /**
   * @brief Pure virtual method for the Polynomial product.
   * 
   * @param p First Polynomial.
   * @param q Second Polynomial.
   * @return Result Polynomial.
   */
  virtual Polynomial PolinomialProduct(Polynomial &p, Polynomial &q) = 0;
};

#endif
