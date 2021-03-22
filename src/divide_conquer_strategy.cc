/**
 * University of La Laguna
 * ESIT (Escuela Superior de Ingeniería y Tecnología)
 * Degree of Computer Engineering
 * Interactive Application Programming
 *
 * @author Alejandro Peraza González
 * @date 21 March 2021
 */

#include "../include/divide_conquer_strategy.h"

Polynomial DivideConquerStrategy::PolinomialProduct(Polynomial &p, Polynomial &q) {
  if (p.getTerms() == 1 && q.getTerms() == 1) {
    Polynomial sub_result;
    sub_result.insert(p[0] * q[0]); // ?
    return sub_result;
  }
  Polynomial p_l, p_h, q_l, q_h;
  p.split(p_l, p_h); 
  q.split(q_l, q_h);
  Polynomial r_l = PolinomialProduct(p_l, q_l); // ?
  Polynomial r_h = PolinomialProduct(p_h, q_h); // ?
  Polynomial left = p_l + p_h;
  Polynomial right = q_l + q_h;
  Polynomial r_m = PolinomialProduct(left, right); // ?
  Polynomial r1 = (r_m - r_l - r_h) * (p.getTerms() / 2);
  Polynomial r2 = r_h * (p.getTerms() / 2 * 2);
  Polynomial r = r_l + r1 + r2;
  return r;
}
