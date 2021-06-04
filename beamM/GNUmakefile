#$Id: GNUmakefile,v 1.2 2000-10-19 12:22:10 stanaka Exp $
# --------------------------------------------------------------
# GNUmakefile for examples module.  Gabriele Cosmo, 06/04/98.
# --------------------------------------------------------------

name := beamM
G4TARGET := $(name)
G4EXLIB := true

ifndef G4INSTALL
  G4INSTALL = /home/Rui/geant4/
endif
CPPFLAGS    += -I`root-config --incdir`
EXTRALIBS   += `root-config --glibs`
CPPFLAGS    += -std=c++17
.PHONY: all
all: lib bin

include $(G4INSTALL)/config/binmake.gmk

visclean:
	rm -f *.heprep
	rm -f *.root
