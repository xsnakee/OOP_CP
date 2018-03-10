/**
 * Project Untitled
 */


#ifndef _GAME_T_H
#define _GAME_T_H

#include "map_t.h"


class game_t {
public: 
    list<physOb_t> obList;
    list<character_t> charList;
    list<heroInterface_t> interfaceOb;
    map_t map;
    map_t 1;
    
    void game_t();
protected: 
    
    void game_t();
};

#endif //_GAME_T_H