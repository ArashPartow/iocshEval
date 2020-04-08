#include "iocshEval.hpp"
#include "iocshDeclWrapper.h"

using namespace IocshDeclWrapper;

IOCSH_FUNC_WRAP_REGISTRAR(myRegistrar,
  //IOCSH_FUNC_WRAP( epicsEnvSetTernary );
  IOCSH_FUNC_WRAP_QUIET( epicsEnvSetTernary );
)
