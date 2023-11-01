###
### Makefile for Comp 15 Maze Solver Lab
CXX      = clang++
CXXFLAGS = -g -Wall -Wextra -std=c++17
LDFLAGS = -g

##
## Uncomment the following line to get more variation in 
## automatically generated mazes.
## Do a "make clean; make" after changing this to get the effect.
## Comment it out before submitting, though!
##
# RANDOMFLAG = -DRANDOM

mazeSolver: main.o Maze.o
	${CXX} ${LDFLAGS} -o mazeSolver main.o Maze.o

# Because of our general "how to make a .o file" rule below, 
# we can just list the dependencies here.
# Notice what depends on what.
main.o:   main.cpp Maze.h Position.h

Maze.o:   Maze.cpp Maze.h Position.h

# The following rule is very general:
# it means "if you need a .o file (%.o) and you have a .cpp file 
# with the same base name (%.cpp), then you make the .o file by
# compiling with that .cpp file with the flags defined above."  
# $@ means "the target you're trying to make"
# $< means "the first prerequisite"
%.o:  %.cpp
	${CXX} ${CXXFLAGS} ${RANDOMFLAG} -c -o $@ $<

clean:
	rm -f mazeSolver *.o
