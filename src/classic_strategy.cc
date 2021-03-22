/**
 * University of La Laguna
 * ESIT (Escuela Superior de Ingeniería y Tecnología)
 * Degree of Computer Engineering
 * Interactive Application Programming
 *
 * @author Alejandro Peraza González
 * @date 19 March 2021
 */

#include "../include/classic_strategy.h"

Polynomial ClassicStrategy::PolinomialProduct(Polynomial &p, Polynomial &q) {
  Polynomial r;
  for (int i = 0; i <= p.getDegree() + q.getDegree(); i++) {
    int sum = 0;
    for (int j = 0; j <= i; j++) {
      sum += p[j].getCoefficient() * q[i - j].getCoefficient();
    }
    Monomial current(sum, i);
    r.insert(current);
  }
  return r;
}
