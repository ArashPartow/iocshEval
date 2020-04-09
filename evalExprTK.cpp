/**
 * \file evalExprTK.cpp
 *
 * \ingroup iocshEval
 *
 * \brief expression evalator
 *
 * This file hold functions for the expression evaluation.
 *
 * \author Dr. Niko Kivel
 *
 * \version 0.1
 *
 * \date 2020/04
 *
 * Contact: niko.kivel@psi.ch
 *
 */

#include <iostream>
#include <string>
#include <stdexcept>

#include "exprtk.hpp"

void evalExprTK(const char* expressionStr, double *result) {

  typedef exprtk::symbol_table<double> symbol_table_t;
  typedef exprtk::expression<double>     expression_t;
  typedef exprtk::parser<double>             parser_t;
  typedef exprtk::parser_error::type          error_t;

  std::string expression_str = expressionStr;

  // Instantiate symbol_table
  symbol_table_t symbol_table;

  // Instantiate expression and register symbol_table
  expression_t expression;
  expression.register_symbol_table(symbol_table);

  // Instantiate parser and compile the expression
  parser_t parser;
  if(!parser.compile(expression_str,expression)) {
    char errMsg [100];
    for(size_t i = 0; i < parser.error_count(); ++i){
      const error_t error = parser.get_error(i);
      snprintf( errMsg, 100, "Error: %02d Position: %02d Type: [%s]\nMsg: %s Expr: %s\n",
                              static_cast<int>(i),
                              static_cast<int>(error.token.position),
                              exprtk::parser_error::to_str(error.mode).c_str(),
                              error.diagnostic.c_str(),
                              expression_str.c_str());
    }
    throw std::runtime_error(errMsg);
  }
  // Set the expression value to the result pointer
  *result = expression.value();
}
