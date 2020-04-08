include /ioc/tools/driver.makefile

BUILDCLASSES = Linux

# build just for RHEL for now
ARCH_FILTER = RHEL%
ARCH_FILTER = SL6%

# do not build for Epics3+
EXCLUDE_VERSIONS += 3.14.8 3.15 3.16 7.0.1

OPT_CXXFLAGS_YES = -O3

# include submodules
USR_INCLUDES += -I../IocshDeclWrap
USR_INCLUDES += -I../exprtk

# Sources
SOURCES += iocshEvalWrapper.cpp
SOURCES += iocshEval.cpp
SOURCES += evalExprTK.cpp

DBDS += iocshEvalWrapper.dbd
