/**
 * Project Untitled
 */


#ifndef _PHYSOB_T_H
#define _PHYSOB_T_H

#include "physPref_t.h"
#include "physPref_t.h"


class physOb_t: public physPref_t, public physPref_t {
public: 
    bool destroyble;
    size_t Dest points;
    bool collision;
};

#endif //_PHYSOB_T_H