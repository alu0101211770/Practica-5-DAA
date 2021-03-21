/**
 * University of La Laguna
 * ESIT (Escuela Superior de Ingeniería y Tecnología)
 * Degree of Computer Engineering
 * Interactive Application Programming
 *
 * @author Alejandro Peraza González
 * @date 19 March 2021
 */

#include <iostream>

#include "../include/classic_strategy.h"
#include "../include/context_interface.h"
#include "../include/divide_conquer_strategy.h"
// #include "../include/monomial.h"
#include "../include/polynomial.h"

int main() {
  try {
    std::vector<int> coefficients = {5, 2};
    Polynomial polinomio1(coefficients);
    // std::cout << polinomio1 << std::endl;
    std::vector<int> coefficients2 = {2, 3};
    Polynomial polinomio2(coefficients2);
    // std::cout << polinomio2 << std::endl;
    polinomio1 * 3;
    std::cout << polinomio1 << std::endl;
    Context *c = new Context(new ClassicStrategy());
    // Polynomial result = c->ContextInterface(polinomio1, polinomio2);
    // std::cout << result << std::endl;
    Context *c2 = new Context(new DivideConquerStrategy());
    // Polynomial result2 = c2->ContextInterface(polinomio1, polinomio2);
    // std::cout << result2 << std::endl;
    delete c;
    delete c2;
  } catch (...) {
    std::cerr << "Exitting the execution because of errors" << '\n';
  }
}