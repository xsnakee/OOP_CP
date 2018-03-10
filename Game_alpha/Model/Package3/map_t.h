/**
 * Project Untitled
 */


#ifndef _MAP_T_H
#define _MAP_T_H

#include "tile_t.h"


class map_t {
public: 
    size_t height;
    size_t width;
    void gameField;
    Vector<ground_t> tile;
    float bordersSize;
    tile_t 1..*;
};

#endif //_MAP_T_H