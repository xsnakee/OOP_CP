/**
 * Project Untitled
 */


#ifndef _PLAYER_T_H
#define _PLAYER_T_H

#include "character_t.h"


class player_t: public character_t {
public: 
    skill_t curSkill;
    element[] elPoints;
};

#endif //_PLAYER_T_H