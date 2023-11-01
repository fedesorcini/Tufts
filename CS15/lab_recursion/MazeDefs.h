#ifndef __MAZEDEFS_H__
#define __MAZEDEFS_H__

static const char WALL = 'X', 
                  EMPTY = ' ', 
                  START = 'S',
                  FINISH = 'F',
                  PATH = '.',
                  REJECT = 'b';

static const int NOT_FOUND = -1;

enum DIR { 
    NORTH, 
    SOUTH, 
    EAST, 
    WEST
};

#endif