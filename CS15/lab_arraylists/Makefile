# Makefile
# Matt Russell
# COMP 15 lab 1


CXX      = clang++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic -Wshadow -g

unit_tests: unit_tests.o ArrayList.o
	${CXX} -o unit_tests unit_tests.o ArrayList.o

ArrayList.o: ArrayList.cpp ArrayList.h
	${CXX} ${CXXFLAGS} -c ArrayList.cpp

unit_tests.o: unit_tests.cpp ArrayList.h
	${CXX} ${CXXFLAGS} -c unit_tests.cpp

# --- clean destroys all the .o files and executable file
clean:
	@rm -rf *.o *~ core* unit_test
