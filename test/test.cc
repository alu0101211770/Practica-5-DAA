/**
 * Universidad de La Laguna
 * ESIT (Escuela Superior de Ingeniería y Tecnología)
 * Grado de Ingeniería Informática
 * Diseño y Análisis de Algoritmos
 *
 * @author Alejandro Peraza González
 * @date 19 Marzo 2021
 */

#include "../include/monomial.h"
#include "../include/polinomial.h"
#include <iostream>


int main(int argc, char const* argv[]) {
  if (argc < 5) {
    std::cout << argv << std::endl;
    // Monomial monito_viren(2, 3);
    // std::cout << monito_viren << std::endl;
    std::vector<int> coefficients = {1, 3, 4};
    Polinomial polinomito_gabriel(coefficients, coefficients.size() - 1);
  } 
}