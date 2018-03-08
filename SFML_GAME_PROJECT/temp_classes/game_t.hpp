#ifndef _GAME_T_H
#define _GAME_T_H

class tile_t {
public: 
    *ground_t tileOb;
    map_t 1;
};


class game_t {
public: 
    list<physOb_t> obList;
    list<character_t> charList;
    list<heroInterface_t> interfaceOb;
    map_t map;
    map_t 1;
};


class map_t {
public: 
    size_t height;
    size_t width;
    void gameField[][];
    Vector<ground_t> tile;
    float bordersSize;
    tile_t 1..*;
};

#endif //_GAME_T_H