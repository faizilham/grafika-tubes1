# this makefile is used for compilation using openbgi (http://openbgi.sourceforge.net/)

LIB = -Llib -lopenbgi -lgdi32 
# -lcomdlg32 -luuid -loleaut32 -lole32 # needed or not?

INCLUDE = -Ilib

all : bin/libgraph.o bin/main.o
	g++ -o bin/main bin/main.o bin/libgraph.o $(LIB)
	
bin/main.o: src/main.cpp
	g++ -c src/main.cpp -o bin/main.o $(INCLUDE)

bin/libgraph.o:
	g++ -c src/libgraph.cpp -o bin/libgraph.o $(INCLUDE)
	
run:
	bin/main

clean:
	rm -rf bin/main
	
cleanall:
	rm -rf bin/*
