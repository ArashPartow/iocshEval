#include <string.h>
#include <stdio.h>
#include "exprtkWrap.h"

#define ENVSETCALC_RESULT_VAR "RESULT"

int evalExprTK(const char* expression, double *result) {

  // Evaluate expression
  exprtkWrap *exprtk = new exprtkWrap();
  if(!exprtk) {
     printf ("Failed allocation of exprtk expression parser.\n");
    return 1;
  }
  double resultDouble = 0;

  exprtk->addVariable(ENVSETCALC_RESULT_VAR, resultDouble);

  std::string exprStr="";

  // Check if "RESULT" variable in str. If not then simple expression.. Add in beginning
  if(strstr(expression,ENVSETCALC_RESULT_VAR)) {
    exprStr = expression;   
  }
  else {
    exprStr = ENVSETCALC_RESULT_VAR;   
    exprStr += ":=";
    exprStr += expression;       
  }

  //Check if need to add ";" last
  if(exprStr.c_str()[strlen(exprStr.c_str())-1] != ';') {
    exprStr += ";";
  }
  
  if(exprtk->compile(exprStr)) {
    printf ("Failed compile of expression with error message: %s.\n", exprtk->getParserError().c_str());
    return 1;
  }
  exprtk->refresh();
  delete exprtk;  // not needed anymore (result in "resultDouble")

  *result = resultDouble;
  return 0;
}
