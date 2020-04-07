#include <iostream>
#include <string.h>
#include <stdexcept>

#include "exprtk/exprtk.hpp"

int evalExprTK(const char* expressionStr, double *result) {

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
  try {
    if(!parser.compile(expression_str,expression)) throw std::runtime_error(parser.error().c_str());
  } catch (std::exception& e) {
    std::cerr << "exception caught: " << e.what() << '\n';
    for (std::size_t i = 0; i < parser.error_count(); ++i){
      const error_t error = parser.get_error(i);
      char errMsg [100];
      snprintf ( errMsg, 100, "Error: %02d Position: %02d Type: [%s] Msg: %s Expr: %s\n",
                        static_cast<int>(i),
                        static_cast<int>(error.token.position),
                        exprtk::parser_error::to_str(error.mode).c_str(),
                        error.diagnostic.c_str(),
                        expression_str.c_str());
      fprintf( stderr,  errMsg);
      }
    return 1;
  }

  *result = expression.value();
  return 0;
}
