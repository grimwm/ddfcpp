MCS=		gmcs
GACUTIL=	gacutil
SN=		sn

MCSFLAGS=

ifeq (1, ${DEBUG})
MCSFLAGS+=	-debug
endif

.SUFFIXES: .cs .dll

%.dll: %.cs
	$(MCS) $(MCSFLAGS) -t:library -out:$@ $^
