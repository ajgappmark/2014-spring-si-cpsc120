TEX := $(filter-out %.part.tex,$(wildcard *.tex))
PDF := $(TEX:%.tex=%.pdf)

CPP_SCOPE  := $(wildcard ./code/*scope*.cpp)
CPP_MEMORY := $(wildcard ./code/*memory*.cpp)
CPP_FIX    := $(wildcard ./code/*fix*.answer.cpp)
CPP_TRACE  := $(wildcard ./code/*trace*.cpp)

DIFF   := $(CPP_FIX:%.cpp=%.cpp.diff)
OUTPUT := $(CPP_SCOPE:%.cpp=%.cpp.output)
OUTPUT += $(CPP_MEMORY:%.cpp=%.cpp.output)
OUTPUT += $(CPP_FIX:%.cpp=%.cpp.output)
OUTPUT += $(CPP_TRACE:%.cpp=%.cpp.output)

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

.INTERMEDIATE: %.exe

%.exe: %.cpp
	clang++ $< -o $@

%.answer.cpp.diff: %.cpp %.answer.cpp
	diff -u $^ > $@; echo  # wait for just a tiny second

%.cpp.output: %.exe
	./$< > $@

%.pdf: %.tex
	latexmk --shell-escape -lualatex -bibtex -pdf -g $<

# -----------------------------------------------------------------------------

.INTERMEDIATE: ./code/6-trace-2.exe

worksheets--answers.pdf: worksheets--answers.tex ./answer-pages/
	latexmk --shell-escape -lualatex -bibtex -pdf -g $<
	for n in $(ANSWER_PAGES:./answer-pages/%.pdf=%); do \
		mv $@ temp--$@; \
		pdftk A=temp--$@ B=./answer-pages/$$n.pdf \
		      cat A1-`echo $$n-1|bc` B A`echo $$n+1|bc`-end \
	              output $@; \
		rm temp--$@; \
	done

./code/6-trace-2.cpp.output: ./code/6-trace-2.exe
	echo "11 7 1 13 5 9 3" | ./$< > $@

# -----------------------------------------------------------------------------

$(PDF): $(wildcard *.part.tex) ./code/

