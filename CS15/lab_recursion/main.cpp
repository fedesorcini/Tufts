/*
 * main.cpp
 *
 * Comp 15 Lab 4
 * Originally created by Chris Gregg (Feb 2014) based on maze creater at
 *                         http://azerdark.wordpress.com/2009/03/29/588/
 * Edited and updated by:
 *        Eliza Schreibman and Mark A. Sheldon (Feb 2017)
 *        Tonya Sinha and Matias Korman (Feb 2019)
 *        Elizabeth Hom (Sept 2020)
 *        Matt Russell (June 2023)
 *
 * Driver that creates a maze and solves it.
 */

#include <iostream>
#include <string>
#include "Maze.h"

void print_with_message(const Maze &m, const char *message) {
    std::cout << "\n--------\n" << message << "\n--------" << std::endl;
    m.print();
}

void JFFE(const char *fpath) {
    Maze m(fpath);
    print_with_message(m, "original");
    int plen = m.solve_and_count();    
    print_with_message(m, "solved");
    std::cout << "\npath length: " << plen << std::endl;  
}

void main_test(const char *fpath) {
    Maze m(fpath);
    print_with_message(m, "original");
    m.solve();
    print_with_message(m, "solved");
    std::cout << "\npath length: " << m.path_length() << std::endl;  
}

int main()
{
    main_test("small.maze");

    main_test("medium.maze");
    main_test("large.maze");

    // Uncomment and try these after having finished main tests. 
    // JFFE("small.maze");
    // JFFE("medium.maze");
    // JFFE("large.maze");

    return 0;
}
