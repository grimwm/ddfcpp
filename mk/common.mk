# Installation directories.
PREFIX=		/usr/local

BIN_PREFIX=	$(PREFIX)/bin
ETC_PREFIX=	$(PREFIX)/etc
INC_PREFIX=	$(PREFIX)/include
LIB_PREFIX=	$(PREFIX)/lib
SBIN_PREFIX=	$(PREFIX)/sbin
SRC_PREFIX=	$(PREFIX)/src

SHARE_PREFIX=	$(PREFIX)/share

DOC_PREFIX=	$(SHARE_PREFIX)/doc
MAN_PREFIX=	$(SHARE_PREFIX)/man

# Project directories.
BUILD_DIR=		$(TOPDIR)/build
BIN_DIR=		$(BUILD_DIR)/bin
DOC_DIR=		$(BUILD_DIR)/doc
ETC_DIR=		$(BUILD_DIR)/etc
INC_DIR=		$(BUILD_DIR)/include
LIB_DIR=		$(BUILD_DIR)/lib
MAN_DIR=		$(BUILD_DIR)/man
OBJ_DIR=		$(BUILD_DIR)/obj
SBIN_DIR=		$(BUILD_DIR)/sbin
SRC_DIR=		$(TOPDIR)/src
TMP_DIR=		$(BUILD_DIR)/tmp

CLEAN_FILES=	$(BUILD_DIR)/*/* *.out *.order

CWD=		`pwd`

# Used to create macros that are used with inline code.
MACROS=

MV=		mv

# Flags that work with multiple compilers.
FLAGS=		-Wall -Wshadow -I$(INC_DIR) -L$(LIB_DIR) $(MACROS)
FLAGS+=		-L/usr/local/lib -O3 -D`uname -s`_OS__

LD=		$(CC)
LDFLAGS=	$(FLAGS)

LEX=		flex
LEXFLAGS= 

AR=		gar
RANLIB=		ranlib

CP=		cp
RM=		rm -f
MKDIR=		mkdir -p
RMDIR=		$(RM) -r
INSTALL=	install

# Conditional compilation checks.

ifeq (1, ${DEBUG})
FLAGS+=		-g3
FLAGS+=		-DDEBUG
endif

ifeq (1, ${PROFILE})
FLAGS+=		-pg
LDFLAGS+=	-pg
endif

ifdef NDEBUG
FLAGS+=		-DNDEBUG
endif

# Pattern rules.

#.SUFFIXES: .a .bin

#%.a: %.o
#	$(AR) r $@ $^
#	$(RANLIB) $@

#%.bin: %.o
#	$(LD) $(LDFLAGS) -o $@ $^ $(LIBRARIES)
