/**
 * University of La Laguna 
 * ESIT (Escuela Superior de Ingeniería y Tecnología)
 * Degree of Computer Engineering
 * Interactive Application Programming
 *
 * @author Alejandro Peraza González
 * @date 19 March 2021
 */

#include "../include/monomial.h"
#include "../include/polinomial.h"
#include <iostream>


int main() {
  // Monomial monito_viren(2, 3);
  // std::cout << monito_viren << std::endl;
  std::vector<int> coefficients = {1, -3, 0, 4};
  Polinomial polinomito_gabriel(coefficients);
  std::cout << polinomito_gabriel << std::endl;
}