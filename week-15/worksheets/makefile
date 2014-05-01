TEX := $(filter-out %.part.tex,$(wildcard *.tex))

CPP_FIX   := $(wildcard ./code/*fix*.answer.cpp)
CPP_TRACE := $(wildcard ./code/*trace*.cpp)

DIFF   := $(CPP_FIX:%.cpp=%.cpp.diff)
OUTPUT := $(CPP_FIX:%.cpp=%.cpp.output) $(CPP_TRACE:%.cpp=%.cpp.output)

# -----------------------------------------------------------------------------

.PHONY: all clean cleanall

all: $(DIFF) $(OUTPUT)
	latexmk --shell-escape -lualatex -bibtex -pdf $(TEX)

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

