/**
 * Project Untitled
 */


#ifndef _DYNAMICOB_T_H
#define _DYNAMICOB_T_H

#include "physOb_t.h"


class dynamicOb_t: public physOb_t {
public: 
    clock timer;
    float dX;
    float dY;
    float range;
    
    void trajectory();
};

#endif //_DYNAMICOB_T_H