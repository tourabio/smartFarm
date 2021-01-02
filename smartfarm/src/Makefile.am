## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = smartfarm

smartfarm_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	ouvrierCrud.c ouvrierCrud.h \
	tropauxCrud.c tropauxCrud.h \
	equipementCrud.c equipementCrud.h \
	clientCrud.c clientCrud.h \
	capteurCrud.c capteurCrud.h \
	agricultureCrud.c agricultureCrud.h \
	dashboard.c dashboard.h 

smartfarm_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

