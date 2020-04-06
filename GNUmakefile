include /ioc/tools/driver.makefile
MODULE = KN82Test

BUILDCLASSES = Linux
ARCH_FILTER = RHEL%

EXCLUDE_VERSIONS+=3

OPT_CXXFLAGS_YES = -O3

USR_INCLUDES += -I./IocshDeclWrap/iocshDeclWrapper.h

SOURCES += iocshExtrasWrapper.cpp
SOURCES += iocshExtras.cpp
SOURCES += evalExprTK.cpp

HEADERS += iocshExtras.hpp
#HEADERS += evalExprTK.hpp

DBDS += iocshExtrasWrapper.dbd

