##
# Ben Blazak
# week 8
# makefile to generate PDF files
#

CPP := $(wildcard *.cpp)

PDF := $(CPP:%.cpp=%.code.pdf)
PDF += $(CPP:%.cpp=%.output.pdf)

# -----------------------------------------------------------------------------

.PHONY: all clean cleanall

all: $(PDF)
	pdfjoin -o all-code.pdf *.code.pdf
	pdfjoin -o all-output.pdf *.output.pdf
	make clean

clean:
	-rm $(PDF)

cleanall: clean
	-rm all-code.pdf all-output.pdf

# -----------------------------------------------------------------------------

%.output.txt: %.cpp
	clang++ $<; ./a.out > $@; rm a.out

%.code.cpp: %.cpp
	cp $< $@

# -----------------------------------------------------------------------------

%.pdf: %.tex
	latexmk -lualatex -bibtex -pdf $<

%.pdf: %.ps
	ps2pdf $<

%.ps: %.cpp
	mvim --nofork \
	     -c 'set printfont=courier:h10' \
	     -c 'set printoptions=portrait:y' \
	     -c 'set printoptions+=paper:letter' \
	     -c 'set printoptions+=left:5pc,right:5pc' \
	     -c 'set printoptions+=top:5pc,bottom:5pc' \
	     -c ':hardcopy >$@' \
	     -c ':q' \
	     $<;

%.ps: %.txt
	mvim --nofork \
	     -c 'set printfont=courier:h10' \
	     -c 'set printoptions=portrait:y' \
	     -c 'set printoptions+=paper:letter' \
	     -c 'set printoptions+=left:5pc,right:5pc' \
	     -c 'set printoptions+=top:5pc,bottom:5pc' \
	     -c ':hardcopy >$@' \
	     -c ':q' \
	     $<;

