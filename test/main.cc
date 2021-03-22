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
#include <random>
#include <chrono>

#include "../include/classic_strategy.h"
#include "../include/context_interface.h"
#include "../include/divide_conquer_strategy.h"
#include "../include/polynomial.h"

const int MIN_RAND = 1;
const int MAX_RAND = 9;

int main(int argc, char const *argv[]) {
  if (argc == 2) {
    try {
      int sz = std::atoi(argv[1]);
      const int SIZE = pow(2, sz);
      std::random_device rd;
      std::default_random_engine eng(rd());
      std::uniform_int_distribution<int> distr(MIN_RAND, MAX_RAND);
      std::vector<int> coefficients = {};
      std::vector<int> coefficients2 = {};
      for (int i = 0; i < SIZE; i++) {
        coefficients.push_back(distr(eng));
        coefficients2.push_back(distr(eng));
      }
      Polynomial p(coefficients);
      Polynomial q(coefficients2);
      Context *c = new Context(new ClassicStrategy());
      Context *c2 = new Context(new DivideConquerStrategy());

      auto t1 = std::chrono::high_resolution_clock::now();
      Polynomial result = c->ContextInterface(p, q);
      auto t2 = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double, std::milli> duration = t2 - t1;
      std::cout <<  "Classic Polynomial product:\n\t--> " << duration.count() << " ms" << std::endl;

      auto t3 = std::chrono::high_resolution_clock::now();
      Polynomial result2 = c2->ContextInterface(p, q);
      auto t4 = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double, std::milli> duration2 = t4 - t3;
      std::cout << "Divide and conquer product:\n\t--> " << duration2.count() << " ms" << std::endl;
      
      delete c;
      delete c2;
    } catch (...) {
      std::cerr << "Exitting the execution due to errors" << '\n';
    } 
  } else {
    std::cerr << "Incorrent amount of parameters given" << '\n';
  }
}