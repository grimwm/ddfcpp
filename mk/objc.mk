OBJCC		= gcc

GNUSTEP_ROOT		= /usr/local/GNUstep
GNUSTEP_SYSTEM_ROOT	= $(GNUSTEP_ROOT)/System
GNUSTEP_LIBRARY_ROOT	= $(GNUSTEP_SYSTEM_ROOT)/Library

OBJCCFLAGS	= $(FLAGS)
OBJCCFLAGS	+= -I$(GNUSTEP_LIBRARY_ROOT)/Headers
OBJCCFLAGS	+= -L$(GNUSTEP_LIBRARY_ROOT)/Libraries
OBJCCFLAGS	+= -fconstant-string-class=NSConstantString
OBJCCFLAGS	+= -Wno-import

LDFLAGS		+= -L$(GNUSTEP_LIBRARY_ROOT)/Libraries -lgnustep-base

%.o: %.m
	$(OBJCC) $(OBJCCFLAGS) -c $^
