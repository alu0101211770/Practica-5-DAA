/**
 * University of La Laguna
 * ESIT (Escuela Superior de Ingeniería y Tecnología)
 * Degree of Computer Engineering
 * Interactive Application Programming
 *
 * @author Alejandro Peraza González
 * @date 22 March 2021
 */

#include <iostream>
#include "../include/classic_strategy.h"
#include "../include/context_interface.h"
#include "../include/divide_conquer_strategy.h"
#include "../include/polynomial.h"

int main() {
  try {
    std::vector<int> coefficients = {5, 2, 3, 6};
    Polynomial p(coefficients);
    std::vector<int> coefficients2 = {2, 3, 4, 7};
    Polynomial q(coefficients2);

    Context *c = new Context(new ClassicStrategy());
    Context *c2 = new Context(new DivideConquerStrategy());
    Polynomial result = c->ContextInterface(p, q);
    Polynomial result2 = c2->ContextInterface(p, q);
    std::cout << "Classic Polynomial product:\n" << result << std::endl;
    std::cout << "Divide and conquer product:\n" << result2 << std::endl;
    delete c;
    delete c2;
  } catch (...) {
    std::cerr << "Exitting the execution due to errors" << '\n';
  }
}