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
  return r;  // !
}
