/**
 * Project Untitled
 */


#ifndef _NPC_T_H
#define _NPC_T_H

#include "character_t.h"


class NPC_t: public character_t {
public: 
    bool alied;
    
    void trajectory();
};

#endif //_NPC_T_H