/**
 * University of La Laguna
 * ESIT (Escuela Superior de Ingeniería y Tecnología)
 * Degree of Computer Engineering
 * Interactive Application Programming
 *
 * @author Alejandro Peraza González
 * @date 19 March 2021
 */

#ifndef CONTEXT_INTERFACE_H_
#define CONTEXT_INTERFACE_H_

#include "polynomial.h"
#include "strategy.h"

/**
 * @brief Context Interface to use the strategies.
 */
class Context {
 private:
  Strategy *_strategy;

 public:
  /**
   * @brief Construct a new Context object.
   *
   * @param strategy Chosen strategy.
   */
  Context(Strategy *strategy);

  /**
   * @brief Destroy the Context object. Destroys the Strategy as well.
   */
  ~Context();

  /**
   * @brief Method to use the current Strategy
   *
   * @param p First Polynomial.
   * @param q Second Polynomial.
   * @return Polynomial result.
   */
  Polynomial ContextInterface(Polynomial &p, Polynomial &q);
};

#endif