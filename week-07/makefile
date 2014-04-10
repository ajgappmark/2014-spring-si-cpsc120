##
# Ben Blazak
# week 7
# makefile for LaTeX (*.tex) documents
#

TEX := worksheet--truth-tables--blank.tex \
       worksheet--truth-tables--filled.tex

PDF := $(TEX:%.tex=%.pdf)

# -----------------------------------------------------------------------------

.PHONY: all clean cleanall

all: $(PDF)

clean:
	latexmk -lualatex -bibtex -pdf -c $(TEX)

cleanall:
	latexmk -lualatex -bibtex -pdf -C $(TEX)

# -----------------------------------------------------------------------------

%.pdf: %.tex
	latexmk -lualatex -bibtex -pdf $<

# -----------------------------------------------------------------------------

worksheet--truth-tables--blank.pdf: worksheet--truth-tables.part.tex
worksheet--truth-tables--filled.pdf: worksheet--truth-tables.part.tex

