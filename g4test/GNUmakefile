# $Id: GNUmakefile 68058 2013-03-13 14:47:43Z gcosmo $
# --------------------------------------------------------------
# GNUmakefile for examples module.  Gabriele Cosmo, 06/04/98.
# --------------------------------------------------------------

name := exampleB2a
G4TARGET := $(name)
G4EXLIB := true
CPPFLAGS    += -I/usr/local/Qt-5.4.1/include -fPIC -fPIE
EXTRALIBS   +=  -L/usr/local/Qt-5.4.1/lib -lQt5Core -lQt5Gui -lQt5Widgets -lQt5UiTools
ifndef G4INSTALL
  G4INSTALL = ../../../..
endif

.PHONY: all
all: lib bin

include $(G4INSTALL)/config/architecture.gmk

include $(G4INSTALL)/config/binmake.gmk

visclean:
	rm -f g4*.prim g4*.eps g4*.wrl
	rm -f .DAWN_*

