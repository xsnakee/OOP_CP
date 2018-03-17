/**
 * Project Untitled
 */


#ifndef _STATICOB_T_H
#define _STATICOB_T_H

#include "physOb_t.h"


class staticOb_t: public physOb_t {
public: 
    Vector<size_t> dropList;
};

#endif //_STATICOB_T_H