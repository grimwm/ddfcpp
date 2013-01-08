RM=			rm
RMFLAGS=		-f
LATEX=			latex
BIBTEX=			bibtex
DVI2PDF=		dvipdf
OMNI_GRAFFLE_CONVERTER=	osascript scripts/OmniGraffleConverter.scpt

.SUFFIXES: .dvi .eps .graffle .tex

.graffle.eps:
	#$(OMNI_GRAFFLE_CONVERTER) $(PWD)/$< $(PWD)/$(<:.graffle=.eps)
	for i in $(EPS_FILES) ; do \
		outfile="$(PWD)/$$i" ;\
		infile=`echo $$outfile | sed 's/\.eps/\.graffle/;'` ;\
		if [ $$infile -nt $$outfile ] ; then \
			files="$$files $$infile $$outfile" ;\
		fi ;\
	done ;\
	$(OMNI_GRAFFLE_CONVERTER) $$files

.tex.dvi:
	$(LATEX) $<
	$(BIBTEX) $(<:.tex=)
	$(LATEX) $<
	$(LATEX) $<

.dvi:
	$(DVI2PDF) $<
