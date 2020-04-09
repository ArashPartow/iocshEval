/**
 * \file iocshEval.cpp
 *
 * \defgroup iocshEval
 *
 * \brief Provides iocshFunctions for expression evaluation
 *
 * This package provides the ability to evaluated mathematical expression
 *
 * The original idea for this feature came from Anders Sandstroem, ESS, Lund, Sweden.
 * He has a function w/ the same functionality in his [ECMC](https://github.com/epics-modules/ecmc/) project.
 * I mearly took the idea and wrapped it differently.
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

#include <iostream>
#include <stdexcept>

// the iocshFunction _epicsEnvUnset_ is not part of Epics base < v7
// fortunately Dirk Zimoch implemented this, the header will only be loaded
// for Epics base < v7
#include <epicsVersion.h>
#ifndef EPICS_VERSION_INT
/**
 * \brief function for EPICS version handling
 */
  #define VERSION_INT(V,R,M,P) ( ((V)<<24) | ((R)<<16) | ((M)<<8) | (P))
#endif

#if !defined(EPICS_VERSION_INT) || EPICS_VERSION_INT < VERSION_INT(7,0,0,0)
  #include "epicsEnvUnset.h"
#endif

#include "evalExprTK.hpp"

int epicsEnvSetTernary(const char *envVarName, const char *expression, const char *trueString, const char *falseString){
  double resultDouble = 0;
  try {
    evalExprTK(expression, &resultDouble);
  } catch(const std::runtime_error& e) {
    epicsEnvUnset(envVarName);
    std::cerr << e.what() << std::endl;
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
