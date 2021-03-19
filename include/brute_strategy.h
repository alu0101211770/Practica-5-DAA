/**
 * University of La Laguna 
 * ESIT (Escuela Superior de Ingeniería y Tecnología)
 * Degree of Computer Engineering
 * Interactive Application Programming
 *
 * @author Alejandro Peraza González
 * @date 19 March 2021
 */

#ifndef BRUTE_STRATEGY_H_
#define BRUTE_STRATEGY_H_

#include "strategy.h"

class Brute_strategy : public Strategy
{
 public:
  Polinomial PolinomialProduct(Polinomial &p, Polinomial &q);
};

#endif