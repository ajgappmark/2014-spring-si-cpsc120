TEX := $(wildcard *.tex)
CPP := $(wildcard *.cpp)

PDF := $(TEX:%.tex=%.pdf)
# PDF += $(CPP:%.cpp=%.code.pdf)
# PDF += $(CPP:%.cpp=%.output.pdf)

# -----------------------------------------------------------------------------

.PHONY: all clean cleanall

all: $(PDF)

clean:
	latexmk -lualatex -bibtex -pdf -c $(TEX)

cleanall: clean
	latexmk -lualatex -bibtex -pdf -C $(TEX)
	-rm $(PDF)

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

