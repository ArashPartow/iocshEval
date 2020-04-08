/**
 * \file iocshEval.cpp
 *
 * \defgroup iocshEval
 *
 * \brief Provides iocshFunctions for expression evaluation
 *
 * This package provides the ability to evaluated mathematical expression
 *
 * \note this is work in progress
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

#include <epicsExit.h>
#include <epicsThread.h>
#include <epicsExport.h>
#include <epicsVersion.h>
#include <errlog.h>
#include <iocsh.h>
#include <envDefs.h>

#include "evalExprTK.hpp"

int epicsEnvSetTernary(const char *envVarName, const char *expression, const char *trueString, const char *falseString){
  double resultDouble = 0;
  // TODO, throw an exception here?
  if(evalExprTK(expression, &resultDouble) != 0) {
    #ifdef EPICS_VERSIONS_7
      epicsEnvUnset(envVarName);
    #else
      epicsEnvSet(envVarName,"ERROR");
    #endif

    return 1;
  }
  if(resultDouble) {
    epicsEnvSet(envVarName,trueString);
  }
  else{
    epicsEnvSet(envVarName,falseString);
  }

  return 0;
}
