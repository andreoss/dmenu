# dwm version
VERSION = 6.4

# Customize below to fit your system

# paths
PREFIX = /usr/local
MANPREFIX = ${PREFIX}/share/man

X11INC = /usr/X11R6/include
X11LIB = /usr/X11R6/lib

# Xinerama, comment if you don't want it
XINERAMALIBS  = -lXinerama
XINERAMAFLAGS = -DXINERAMA

# freetype
FREETYPELIBS = -lfontconfig -lXft
FREETYPEINC = /usr/include/freetype2

# OpenBSD (uncomment)
FREETYPEINC = ${X11INC}/freetype2

MANPREFIX = ${PREFIX}/man
BDLIBS = $(shell pkg-config --libs fribidi)
BDINC = $(shell pkg-config --cflags fribidi)

# includes and libs
INCS = -I${X11INC} -I${FREETYPEINC} ${BDINC}
LIBS = -L${X11LIB} -lX11 ${XINERAMALIBS} ${FREETYPELIBS} $(BDLIBS) -lxcb -lxcb-keysyms -lutil
# flags
CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700L -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS}
CFLAGS   = -std=c17 -pedantic -Wall -Wno-deprecated-declarations -Os ${INCS} ${CPPFLAGS}
LDFLAGS  = ${LIBS}

# compiler and linker
CC = cc
