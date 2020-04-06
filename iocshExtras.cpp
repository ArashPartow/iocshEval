#include <stdio.h>
#include <stdint.h>
#include <epicsExit.h>
#include <epicsThread.h>
#include <errlog.h>
#include <epicsExport.h>
#include <string>
#include <string.h>
#include <complex>
#include <iocsh.h>
#include <envDefs.h>

#include "evalExprTK.hpp"

int epicsEnvSetTernary(const char *envVarName, const char *expression, const char *trueString, const char *falseString)
{
  printf("ENVVAR:     %s\n", envVarName );
  printf("EXPRESSION: %s\n", expression );
  printf("TRUE:       %s\n", trueString );
  printf("FALSE:      %s\n", falseString );

  double resultDouble = 0;
  if(evalExprTK(expression, &resultDouble) != 0) {
    return 1;
  }
  printf("exprtk eval: %f\n", resultDouble );
  if(resultDouble) {
    epicsEnvSet(envVarName,trueString);
  }
  else{
    epicsEnvSet(envVarName,falseString);
  }
  /* cannot just hand 'm' back since it may not outlive
   * this function call!
   */
  return 0;
}

