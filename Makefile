# this makefile is used for compilation using openbgi (http://openbgi.sourceforge.net/)

# the module names, without .cpp extension
MODULES = libgraph trans shapes main road obstacle_manager car result text_countdown

LIB = -Llib -lopenbgi
INCLUDE = -Ilib

MODE = debug
# release or debug

ifeq ($(MODE), release)
FLAGS += -O2
LIB += -mwindows
else
FLAGS += -O0 -g
LIB += -lgdi32
endif

# Everything after this is generic

.PHONY: all
   
define module_template =
bin/$(1).o : src/$(1).cpp 
	g++ -c src/$(1).cpp -o bin/$(1).o $(INCLUDE) $(FLAGS)
endef

OBJFILE = $(foreach file,$(MODULES),bin/$(file).o)

all: $(OBJFILE)
	g++ -o bin/main $(OBJFILE) $(LIB)

run:
	./bin/main
	
clean:
	rm -f bin/main bin/*.o

$(foreach file,$(MODULES),$(eval $(call module_template,$(file))))