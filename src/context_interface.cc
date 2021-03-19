/**
 * University of La Laguna 
 * ESIT (Escuela Superior de Ingeniería y Tecnología)
 * Degree of Computer Engineering
 * Interactive Application Programming
 *
 * @author Alejandro Peraza González
 * @date 19 March 2021
 */

#include "../include/context_interface.h"

Context::Context(Strategy *strategy) {
  _strategy = strategy; 
}

Context::~Context() {
  delete _strategy; 
}

Polinomial Context::ContextInterface(Polinomial &p, Polinomial &q) { 
  return _strategy->PolinomialProduct(p, q); 
}