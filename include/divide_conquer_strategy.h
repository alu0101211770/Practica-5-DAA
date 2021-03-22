/**
 * University of La Laguna
 * ESIT (Escuela Superior de Ingeniería y Tecnología)
 * Degree of Computer Engineering
 * Interactive Application Programming
 *
 * @author Alejandro Peraza González
 * @date 21 March 2021
 */

#ifndef DIVIDE_CONQUER_STRATEGY_H_
#define DIVIDE_CONQUER_STRATEGY_H_

#include "strategy.h"

class DivideConquerStrategy : public Strategy {
 public:
  /**
   * @brief Method for the Polynomial product using divide and conquer.
   * 
   * @param p First Polynomial.
   * @param q Second Polynomial.
   * @return Result Polynomial.
   */
  Polynomial PolinomialProduct(Polynomial &p, Polynomial &q);
};

#endif
