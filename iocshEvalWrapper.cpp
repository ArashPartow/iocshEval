/**
 * \file iocshEvalWrapper.cpp
 *
 * \defgroup iocshEval
 *
 * \brief Wraps the C++ functions to iocshFunctions
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

#include "iocshEval.hpp"
#include "iocshDeclWrapper.h"

using namespace IocshDeclWrapper;

IOCSH_FUNC_WRAP_REGISTRAR(myRegistrar,
  IOCSH_FUNC_WRAP_QUIET( epicsEnvSetTernary );
)
