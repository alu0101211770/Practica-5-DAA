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
  p.split(p_l, p_h); // ! 1
  q.split(q_l, q_h); // ! 1
  Polynomial r_l = PolinomialProduct(p_l, q_l); // ?
  Polynomial r_h = PolinomialProduct(p_h, q_h); // ?
  Polynomial left = p_l + p_h; // ! 2
  Polynomial right = q_l + q_h; // ! 2
  Polynomial r_m = PolinomialProduct(left, right); // ?
  Polynomial r1 = (r_m - r_l - r_h) * (p.getTerms() / 2); // ! 2 y 3
  Polynomial r2 = r_h * (p.getTerms() / 2 * 2); // ! 3
  std::cout << "hola\n";
  std::cout << "r_l:\n" << r_l << std::endl;
  std::cout << "r1:\n" << r1 << std::endl;
  std::cout << "r2:\n" << r2 << std::endl;
  Polynomial r = r_l + r1 + r2; // ! 2
  std::cout << "hola2\n";
  return r;
}
