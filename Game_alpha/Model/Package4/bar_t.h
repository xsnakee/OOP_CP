/**
 * Project Untitled
 */


#ifndef _BAR_T_H
#define _BAR_T_H

#include "heroInterface_t.h"


class bar_t: public heroInterface_t {
public: 
    color color;
    float maxSize;
    float curVal;
};

#endif //_BAR_T_H