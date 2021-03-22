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
    sub_result.insert(p[0] * q[0]);
    // std::cout << p << std::endl << q << std::endl;
    // std::cout << "Subresult...\n";
    // std::cout << sub_result << std::endl;
    return sub_result;
  }
  // dividir los polinomios en l y h
  Polynomial p_l, p_h, q_l, q_h;
  // std::cout << "Splitting...\n";
  p.split(p_l, p_h);
  q.split(q_l, q_h);
  // std::cout << "P_l:\n" << p_l << std::endl;
  // std::cout << "P_h:\n" << p_h << std::endl;
  // std::cout << "Q_l:\n" << q_l << std::endl;
  // std::cout << "Q_h:\n" << q_h << std::endl;
  Polynomial r_l = PolinomialProduct(p_l, q_l);
  // std::cout << "Hola...\n";
  // std::cout << r_l << std::endl;
  Polynomial r_h = PolinomialProduct(p_h, q_h);
  // std::cout << "Hola2...\n";
  Polynomial left = p_l + p_h;
  Polynomial right = q_l + q_h;
  // std::cout << "\nleft:\n" << left << std::endl;
  // std::cout << "right:\n" << right << std::endl;
  Polynomial r_m = PolinomialProduct(left, right);
  // std::cout << "Hola3...\n";
  // std::cout << "r_l:\n" << r_l << std::endl;
  // std::cout << "r_m:\n" << r_m << std::endl;
  // std::cout << "r_h:\n" << r_h << std::endl;
  // Polynomial r;
  Polynomial r1 = (r_m - r_l - r_h);
  r1 *(p.getTerms() / 2);
  // std::cout << "r1:\n" << r1 << std::endl;
  Polynomial r2 = r_h;
  // std::cout << p.getTerms() << std::endl;
  // std::cout << "r2:\n" << r2 << std::endl;
  r2 *((p.getTerms() / 2 * 2));
  // std::cout << "r2:\n" << r2 << std::endl;
  // std::cout << "Hola4...\n";
  // std::cout <<

  // std::cout << "Hola5...\n";
  Polynomial r = r_l + r1 + r2;
  // std::cout << "r: " << r << std::endl;

  return r;
}
