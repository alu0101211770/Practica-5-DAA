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

class Strategy {
 public:
  virtual ~Strategy() = default;
  virtual Polynomial PolinomialProduct(Polynomial &p, Polynomial &q) = 0;
};

#endif
