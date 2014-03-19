# this makefile is used for compilation using openbgi (http://openbgi.sourceforge.net/)

LIB = -Llib -lopenbgi -lgdi32 
# -lcomdlg32 -luuid -loleaut32 -lole32 # needed or not?

INCLUDE = -Ilib

MODE = debug
# release or debug

ifeq ($(MODE), release)
FLAGS = -Wall -O2
else
FLAGS = -Wall -O0 -g
endif

all : bin/libgraph.o bin/trans.o bin/point.o bin/main.o
	g++ -o bin/main bin/libgraph.o bin/trans.o bin/point.o bin/main.o $(LIB)
	
bin/main.o: src/main.cpp
	g++ -c src/main.cpp -o bin/main.o $(INCLUDE) $(FLAGS)

bin/libgraph.o: src/libgraph.cpp
	g++ -c src/libgraph.cpp -o bin/libgraph.o $(INCLUDE) $(FLAGS)
	
bin/point.o: src/point.cpp
	g++ -c src/point.cpp -o bin/point.o $(INCLUDE) $(FLAGS)
	
bin/trans.o: src/trans.cpp
	g++ -c src/trans.cpp -o bin/trans.o $(INCLUDE) $(FLAGS)
	
run:
	bin/main

clean:
	rm -rf bin/main
	
cleanall:
	rm -rf bin/*
