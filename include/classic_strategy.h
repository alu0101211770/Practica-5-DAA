/**
 * University of La Laguna
 * ESIT (Escuela Superior de Ingeniería y Tecnología)
 * Degree of Computer Engineering
 * Interactive Application Programming
 *
 * @author Alejandro Peraza González
 * @date 19 March 2021
 */

#ifndef CLASSIC_STRATEGY_H_
#define CLASSIC_STRATEGY_H_

#include "strategy.h"

class ClassicStrategy : public Strategy {
 public:
  /**
   * @brief Method for the Polynomial product using the classic algorithm.
   * 
   * @param p First Polynomial.
   * @param q Second Polynomial.
   * @return Result Polynomial.
   */
  Polynomial PolinomialProduct(Polynomial &p, Polynomial &q);
};

#endif
