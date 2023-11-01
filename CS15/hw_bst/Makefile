
# Makefile for Binary Search Tree Assignment

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11 

bst: main.o BinarySearchTree.o
	${CXX} -o $@ $^

%.o: %.cpp $(shell echo *.h)
	${CXX} ${CXXFLAGS} -c $<

unit_tests: unit_tests.o BinarySearchTree.o
	${CXX} -o $@ $^

unit_tests.o: unit_tests.cpp BinarySearchTree.h
	${CXX} ${CXXFLAGS} -c $<

clean:
	rm -rf bst unit_tests *.o *.dSYM

