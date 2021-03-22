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

#include <random>
#include <chrono>

const int MIN_RAND = 1;
const int MAX_RAND = 9;
const int SIZE = pow(2, 12);


int main() {
  try {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::vector<int> coefficients = {};
    std::vector<int> coefficients2 = {};
    std::uniform_int_distribution<int> distr(MIN_RAND, MAX_RAND);
    for (int i = 0; i < SIZE; i++) {
      coefficients.push_back(distr(eng));
      coefficients2.push_back(distr(eng));
    }
    
    Polynomial polinomio1(coefficients);
    Polynomial polinomio2(coefficients2);

    Context *c = new Context(new ClassicStrategy());

    auto t1 = std::chrono::high_resolution_clock::now();
    Polynomial result = c->ContextInterface(polinomio1, polinomio2);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = t2 - t1;

    std::cout << duration.count() << " ms" << std::endl;
    // std::cout << result << std::endl;
    Context *c2 = new Context(new DivideConquerStrategy());

    auto t3 = std::chrono::high_resolution_clock::now();
    Polynomial result2 = c2->ContextInterface(polinomio1, polinomio2);
    auto t4 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration2 = t4 - t3;

    std::cout << duration2.count() << " ms" << std::endl;
    // std::cout << result2 << std::endl;
    delete c;
    delete c2;
  } catch (...) {
    std::cerr << "Exitting the execution because of errors" << '\n';
  }
}