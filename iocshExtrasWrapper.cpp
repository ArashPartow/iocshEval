#include "iocshExtras.hpp"

#include "./IocshDeclWrap/iocshDeclWrapper.h"

using namespace IocshDeclWrapper;

IOCSH_FUNC_WRAP_REGISTRAR(myRegistrar,
  IOCSH_FUNC_WRAP( epicsEnvSetTernary );
)

