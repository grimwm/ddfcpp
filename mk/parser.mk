BISON		= bison
BISONFLAGS	= -d

%.yy.cc: %.l
	$(LEX)++ $(LEXFLAGS) $^

%.yy.c: %.l
	$(LEX) $(LEXFLAGS) $^

%.tab.c %.tab.h: %.y
	$(BISON) $(BISONFLAGS) $<
