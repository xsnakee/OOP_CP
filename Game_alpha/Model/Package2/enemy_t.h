/**
 * Project Untitled
 */


#ifndef _ENEMY_T_H
#define _ENEMY_T_H

#include "NPC_t.h"


class enemy_t: public NPC_t {
public: 
    vector<size_t> dropList;
    list<skill> skills;
};

#endif //_ENEMY_T_H