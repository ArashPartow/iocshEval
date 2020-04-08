include /ioc/tools/driver.makefile
MODULE = KN82Test

BUILDCLASSES = Linux

# build just for RHEL for now
ARCH_FILTER = RHEL%

# do not build for Epics3+
EXCLUDE_VERSIONS+=3

OPT_CXXFLAGS_YES = -O3

# include submodules
USR_INCLUDES += -I../IocshDeclWrap
USR_INCLUDES += -I../exprtk

# Sources
SOURCES += iocshEvalWrapper.cpp
SOURCES += iocshEval.cpp
SOURCES += evalExprTK.cpp

HEADERS += iocshEval.hpp
#HEADERS += evalExprTK.hpp

DBDS += iocshEvalWrapper.dbd
