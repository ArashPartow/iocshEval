include /ioc/tools/driver.makefile
MODULE = KN82Test

BUILDCLASSES = Linux
ARCH_FILTER = RHEL%

EXCLUDE_VERSIONS+=3

OPT_CXXFLAGS_YES = -O3

#USR_INCLUDES += -I./IocshDeclWrap/iocshDeclWrapper.h
#USR_INCLUDES += -I./IocshDeclWrap
#USR_INCLUDES += -I./exprtk

SOURCES += iocshEvalWrapper.cpp
SOURCES += iocshEval.cpp
SOURCES += evalExprTK.cpp

HEADERS += iocshEval.hpp
#HEADERS += evalExprTK.hpp

DBDS += iocshEvalWrapper.dbd
