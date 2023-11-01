/*
 * maze.h
 *
 * Comp 15 Recursion Lab
 * Originally created by Chris Gregg (Feb 2014) based on maze creater at
 *                         http://azerdark.wordpress.com/2009/03/29/588/
 * Edited and updated by:
 *        Eliza Schreibman and Mark A. Sheldon (Feb 2017)
 *        Tonya Sinha and Matias Korman (Feb 2019)
 *        Elizabeth Hom (Sept 2020)
 *        Matt Russell (June 2023)
 *
 * Interface of Maze class that includes relevant functions such as generating,
 * solving, and printing a maze
 */

#ifndef __MAZE_H__
#define __MAZE_H__

#include <vector>
#include <string>
#include <stack>
#include "Position.h"
#include "MazeDefs.h"

// used during maze creation
typedef std::pair<DIR, Position> dir_pos_pair;

class Maze {
public:
    Maze(int size);
    Maze(const char *fpath);
    
    void solve(); 
    int solve_and_count();
    int path_length() const;

    void print() const;

private:
    std::vector<std::vector<char>> maze;
    int size;

    // functions to index into the maze based on a position
    const char &at(const Position &p) const;
    char &at(const Position &p);

    // TODO:  recursive helper functions you will write
    bool solve(const Position &p);
    int  solve_and_count (const Position &p);
    int  num_dots_by_rows(int row) const;
    int  num_dots_in_row (int row, int col) const;  

    // maze building code -- feel free to ignore
    void generate(const Position &c, std::stack<Position>& btrack, int to_v);
    std::vector<dir_pos_pair>get_valid_spots(const Position &c) const;
    bool is_closed(const Position &p) const;


};

#endif