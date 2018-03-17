/**
 * Project Untitled
 */


#ifndef _CHARACTER_T_H
#define _CHARACTER_T_H

#include "characterStats_t.h"


class character_t {
public: 
    texture texture;
    float CoordX;
    float coordY;
    float dX;
    float dY;
    bool collision;
    float viewRange;
    unsigned char direction;
    *characterStats_t stats;
    bool alive;
    bool godMode;
    characterStats_t 1;
    
    void character_t();
protected: 
    
    void character_t();
};

#endif //_CHARACTER_T_H