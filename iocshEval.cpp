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
#include <errlog.h>
#include <iocsh.h>
#include <envDefs.h>

// the iocshFunction _epicsEnvUnset_ is not part of Epics base < v7
// fortunately Dirk Zimoch implemented this, the header will only be loaded
// for Epics base < v7
#include <epicsVersion.h>
#ifndef EPICS_VERSION_INT
#define VERSION_INT(V,R,M,P) ( ((V)<<24) | ((R)<<16) | ((M)<<8) | (P))
#endif

#if !defined(EPICS_VERSION_INT) || EPICS_VERSION_INT < VERSION_INT(7,0,0,0)
#include "epicsEnvUnset.h"
#endif

#include "evalExprTK.hpp"

int epicsEnvSetTernary(const char *envVarName, const char *expression, const char *trueString, const char *falseString){
  double resultDouble = 0;
  // TODO, throw an exception here?
  if(evalExprTK(expression, &resultDouble) != 0) {
    epicsEnvUnset(envVarName);
    
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
