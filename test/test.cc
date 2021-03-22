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
    // std::random_device rd;
    // std::default_random_engine eng(rd());
    // std::uniform_int_distribution<int> distr(MIN_RAND, MAX_RAND);
    // std::vector<int> coefficients = {};
    // std::vector<int> coefficients2 = {};
    // for (int i = 0; i < SIZE; i++) {
    //   coefficients.push_back(distr(eng));
    //   coefficients2.push_back(distr(eng));
    // }
    
    std::vector<int> coefficients = {5, 2, 3, 6};
    Polynomial p(coefficients);
    // std::cout << polinomio1 << std::endl;
    std::vector<int> coefficients2 = {2, 3, 4, 7};
    Polynomial q(coefficients2);


    // Polynomial p_l, p_h, q_l, q_h;
    // p.split(p_l, p_h);
    // q.split(q_l, q_h);
    // std::cout << "P_l:\n" << p_l << std::endl;
    // std::cout << "P_h:\n" << p_h << std::endl;
    // std::cout << "Q_l:\n" << q_l << std::endl;
    // std::cout << "Q_h:\n" << q_h << std::endl;

    Context *c = new Context(new ClassicStrategy());
    // std::cout << p << std::endl;
    // std::cout << q << std::endl;
    auto t1 = std::chrono::high_resolution_clock::now();
    Polynomial result = c->ContextInterface(p, q);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = t2 - t1;


    // p * 2;
    // std::cout << p << std::endl;
    std::cout << duration.count() << " ms" << std::endl;
    std::cout << result << std::endl;
    Context *c2 = new Context(new DivideConquerStrategy());

    auto t3 = std::chrono::high_resolution_clock::now();
    Polynomial result2 = c2->ContextInterface(p, q);
    auto t4 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration2 = t4 - t3;

    std::cout << duration2.count() << " ms" << std::endl;
    std::cout << result2 << std::endl;
    delete c;
    delete c2;
  } catch (...) {
    std::cerr << "Exitting the execution because of errors" << '\n';
  }
}