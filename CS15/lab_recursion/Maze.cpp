/*
 * maze.cpp
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
 * Implementation of a maze class that creates directed, acyclic, perfect
 * mazes, and recursive functions for solving them.
 *
 * TODO: Student must complete the implementation of solve() and determine
 *       the length of the completion paths.
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <random>
#include <stack>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include "MazeDefs.h"
#include "Maze.h"

/* really_random == true makes random number generator in Constructor use the
 *     current time for more random mazes. really_random == false seeds the
 *     random number generator with 0 so maze sequence is repeatable for
 *     debugging purposes.
 */
#ifdef RANDOM
static const bool really_random = true;
#else
static const bool really_random = false;
#endif

using namespace std;

/*       
 *    Maze Constructor
 *    Purpose: Create the maze
 * Parameters: string of a file path that contains a maze
 */
Maze::Maze(const char *fpath) { 
    ifstream maze_file(fpath);
    std::string strLine;
    size = 0;
    while (getline(maze_file, strLine)) {
        std::vector<char> line;
        for (char c : strLine) {
            line.push_back(c);
        }
        maze.push_back(line);
        size++;
    }
    maze_file.close();
}

/*       
 *       Name: at
 *    Purpose: Index the maze by using a Position object.
 * Parameters: Position object
 *    Returns: Returns char at row, col of the Position within the maze
 *       Note: First variant will work with const member functions. 
 */
char &Maze::at(const Position &p) {
    return maze[p.row][p.col];
}

const char &Maze::at(const Position &p) const {
    return maze[p.row][p.col];
}


/*       
 *       Name: solve
 *    Purpose: function that solves the maze
 *      Notes: Need to reset start position to START because private solve()
 *             sets it to '.'
 */
void Maze::solve()
{
    solve(Position(1, 1));
    maze[1][1] = START;
}

/* 
 *       Name: solve
 *    Purpose: Recursive helper function which solves the maze
 * Parameters: Position object
 *    Returns: True if maze can be solved, false if no solution  
 */
bool Maze::solve(const Position &p)
{
    if (maze[p.row][p.col] == FINISH)
    {
        return true;
    }
    if (maze[p.row][p.col] == WALL || maze[p.row][p.col] == PATH || maze[p.row][p.col] == REJECT)
    {
        return false;
    }
    else
    {
        maze[p.row][p.col] = PATH;
            if (solve(p.north()))
                return true;
            if (solve(p.east()))
                return true;
            if (solve(p.south()))
                return true;
            if (solve(p.west()))
                return true;
            maze[p.row][p.col] = REJECT;
            return false;
    }
}

/* path_length
 *    Purpose: Determines length of path from start to finish
 * Parameters: none
 *    Returns: path length
 */
int Maze::path_length() const 
{
    return num_dots_by_rows(1) + 1;
};

/* 
 *       Name: num_dots_by_rows
 *    Purpose: Determines number of dots in the maze starting at a given row
 *             by recursing on row index
 * Parameters: Row to start counting dots
 *    Returns: Number of dots in maze path
 */
int Maze::num_dots_by_rows(int row) const
{
    if (row == size)
        return 0;
    else 
        return num_dots_in_row(row, 0) + num_dots_by_rows(row + 1);
}

/* 
 *       Name: num_dots_in_row
 *    Purpose: Determines number of dots in a given row starting at a given
 *             column by recursing on column index
 * Parameters: Row/col position
 *    Returns: Number of dots in a given row starting at given column
 */
int Maze::num_dots_in_row(int row, int col) const
{
    if (col == size)
        return 0;
    else if (maze[row][col] == PATH)
        return 1 + num_dots_in_row(row, col + 1);
    else
        return num_dots_in_row(row, col + 1);
}

/* 
 *       Name: solve_and_count
 *    Purpose: Assumes the maze is not solved and recursively solves the maze
 *             AND counts final path length.
 * Parameters: none
 *    Returns: Length of final path, i.e. the number of '.'s + 1
 */
int Maze::solve_and_count()
{
    int distance;

    // distance = solve_and_count(1, 1);
    distance = solve_and_count(Position(1, 1));

    maze[1][1] = START;
    return distance;
};

/* 
 *       Name: solve_and_count
 *    Purpose: Solves the maze and returns path starting at given position
 * Parameters: Position object
 *    Returns: Length of path starting at the given position
 *
 *       Note: Complete this function or the one using row/col index above
 */
int Maze::solve_and_count(const Position &p)
{
    // if (maze[p.row][p.col] == FINISH)
    // {
    //     return true;
    // }
    // if (maze[p.row][p.col] == WALL || maze[p.row][p.col] == PATH || maze[p.row][p.col] == REJECT)
    // {
    //     return false;
    // }
    // else
    // {
    //     maze[p.row][p.col] = PATH;
    //         if (solve(p.north()))
    //             return true;
    //         if (solve(p.east()))
    //             return true;
    //         if (solve(p.south()))
    //             return true;
    //         if (solve(p.west()))
    //             return true;
    //         maze[p.row][p.col] = REJECT;
    //         return false;
    // }
}


/* 
 *       Name: print
 *    Purpose: prints the maze to std::cout 
 */
void Maze::print() const{
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            cout << maze[row][col]; 
        }
        cout << endl;
    }
}

/*
    code below related to maze generation -- feel free to ignore 
*/

/*       
 *    Maze Constructor
 *    Purpose: Create the maze
 * Parameters: size - both height / width will be 2 * size + 1
 *      Notes: START is position (1, 1)
 *             FINISH is position (size -2, size -2)
 */
Maze::Maze(int sz) : size(2 * sz + 1) {
    if (really_random)
        srand(time(NULL));
    else
        srand(0U);
        
    for (int i = 0; i < size; ++i) {
        vector<char> row;
        for (int j = 0; j < size; ++j) {
            row.push_back((i % 2 == 0) or (j % 2 == 0) ? WALL : EMPTY);
        }
        maze.push_back(row);
    }

    Position start(1, 1);
    
    stack<Position> backtrack; 
    backtrack.push(start);
    int to_visit = sz * sz - 1;
    
    generate(start, backtrack, to_visit);
    
    maze[1][1] = START;
    maze[size - 2][size - 2] = FINISH;
    print();
}


/* 
 *       Name: get_valid_spots
 *    Purpose: Determines possible valid positions
 * Parameters: current position
 *    Returns: shuffled list of valid pairs of <direction, position> objects
 */
std::vector<dir_pos_pair> Maze::get_valid_spots(const Position &curr) const {

    // valid spots are 2 away from current position
    Position north = curr.north(2);
    Position south = curr.south(2);
    Position east  = curr.east(2);
    Position west  = curr.west(2);

    std::vector<dir_pos_pair> valid_spots;
    if (is_closed(north)) valid_spots.push_back(dir_pos_pair(NORTH, north));
    if (is_closed(south)) valid_spots.push_back(dir_pos_pair(SOUTH, south));
    if (is_closed(east))  valid_spots.push_back(dir_pos_pair(EAST, east));
    if (is_closed(west))  valid_spots.push_back(dir_pos_pair(WEST, west));

    std::shuffle(valid_spots.begin(), valid_spots.end(), std::random_device());

    return valid_spots;
}

/* 
 *       Name: generate
 *    Purpose: Generates actual maze through using a backtracking search with
 *             some randomness to generate the maze.
 * Parameters: current position, stack of positions to backtrack, 
 *             and number of positios left to visit
 */
void Maze::generate(const Position &curr, std::stack<Position> &backtrack, 
                    int to_visit) {
    
    if (to_visit == 0) return;
    
    std::vector<dir_pos_pair> valid_spots = get_valid_spots(curr);

    Position next;
    if (valid_spots.empty()) {
        next = backtrack.top();
        backtrack.pop();
    } else {   
        DIR direction = valid_spots[0].first;
        
        // set the adjacent cell to empty
        if      (direction == NORTH) this->at(curr.north()) = EMPTY;
        else if (direction == SOUTH) this->at(curr.south()) = EMPTY;
        else if (direction == EAST)  this->at(curr.east())  = EMPTY;
        else                         this->at(curr.west())  = EMPTY;

        next = valid_spots[0].second;
        backtrack.push(next);
        to_visit--;
    }
    
    generate(next, backtrack, to_visit);
}

/* 
 *       Name: is_closed
 *    Purpose: Determines whether the maze is closed
 * Parameters: int -- (i,j) position indices
 *    Returns: true if maze is fully closed, otherwise false
 */ 
bool Maze::is_closed(const Position &p) const {
    return  (p.row > 0 and p.row < size - 1 and 
             p.col > 0 and p.col < size - 1 and 
             this->at(p.north()) == WALL and
             this->at(p.south()) == WALL and
             this->at(p.east()) == WALL and
             this->at(p.west()) == WALL);
}