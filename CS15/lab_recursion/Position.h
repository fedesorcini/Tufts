/*
 * position.h
 *
 * Comp 15 Lab 4
 * Originally created by Chris Gregg (Feb 2014) based on maze creater at
 *                         http://azerdark.wordpress.com/2009/03/29/588/
 * Edited and updated by:
 *        Eliza Schreibman and Mark A. Sheldon (Feb 2017)
 *        Tonya Sinha and Matias Korman (Feb 2019)
 *        Elizabeth Hom (Sept 2020)
 *
 * Describes a Position object, which details a position in 2D: row/col
 * indices. Given a Position, can compute position to the north, south,
 * east, or west, and can test whether the psotion is within some given
 * bounds.
 */

#ifndef POSITION_H
#define POSITION_H

struct Position {
    int row, col;

    Position()
    {
        row = col = 0;
    }

    Position(int r, int c)
    {
        row = r;
        col = c;
    }

    Position north(int d = 1) const
    {
        return Position(row - d, col);
    }

    Position south(int d = 1) const
    {
        return Position(row + d, col);
    }

    Position east(int d = 1) const
    {
        return Position(row, col + d);
    }

    Position west(int d = 1) const
    {
        return Position(row, col - d);
    }

    bool inBounds(int rowLimit, int colLimit) const
    {
        return (0 < row) and (row < rowLimit)
                         and (0 < col)
                         and (col < colLimit);
    }
};

#endif
