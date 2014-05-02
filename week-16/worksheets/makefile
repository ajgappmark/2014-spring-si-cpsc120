TEX := $(filter-out %.part.tex,$(wildcard *.tex))
PDF := $(TEX:%.tex=%.pdf)

CPP_FIX   := $(wildcard ./code/*fix*.answer.cpp)
CPP_TRACE := $(wildcard ./code/*trace*.cpp)
CPP_SCOPE := $(wildcard ./code/*scope*.cpp)

DIFF   := $(CPP_FIX:%.cpp=%.cpp.diff)
OUTPUT := $(CPP_FIX:%.cpp=%.cpp.output)
OUTPUT += $(CPP_TRACE:%.cpp=%.cpp.output)
OUTPUT += $(CPP_SCOPE:%.cpp=%.cpp.output)

ANSWER_PAGES := $(wildcard ./answer-pages/*.pdf)

# -----------------------------------------------------------------------------

.PHONY: all clean cleanall

all: $(DIFF) $(OUTPUT) $(PDF)

clean:
	latexmk --shell-escape -lualatex -bibtex -pdf -c $(TEX)
	-rm *.pyg *.pytxcode $(DIFF) $(OUTPUT)

cleanall: clean
	latexmk --shell-escape -lualatex -bibtex -pdf -C $(TEX)

# -----------------------------------------------------------------------------

%.exe: %.cpp
	clang++ $< -o $@

%.answer.cpp.diff: %.cpp %.answer.cpp
	diff -u $^ > $@; echo  # wait for just a tiny second

%.cpp.output: %.exe
	./$< > $@

%.pdf: %.tex
	latexmk --shell-escape -lualatex -bibtex -pdf -g $<

# -----------------------------------------------------------------------------

worksheets--answers.pdf: worksheets--answers.tex
	latexmk --shell-escape -lualatex -bibtex -pdf -g $<
	for n in $(ANSWER_PAGES:./answer-pages/%.pdf=%); do \
		mv $@ temp--$@; \
		pdftk A=temp--$@ B=./answer-pages/$$n.pdf \
		      cat A1-`echo $$n-1|bc` B A`echo $$n+1|bc`-end \
	              output $@; \
		rm temp--$@; \
	done

# -----------------------------------------------------------------------------

$(PDF): $(wildcard *.part.tex) ./code/

