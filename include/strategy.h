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

#include "polinomial.h"

class Strategy
{
 public:
  virtual ~Strategy() = default;
  virtual Polinomial PolinomialProduct(Polinomial &p, Polinomial &q) = 0;
};

#endif
