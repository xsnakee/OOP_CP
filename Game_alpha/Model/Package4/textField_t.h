/**
 * Project Untitled
 */


#ifndef _TEXTFIELD_T_H
#define _TEXTFIELD_T_H

#include "heroInterface_t.h"


class textField_t: public heroInterface_t {
public: 
    size_t fontSize;
    color color;
    string content;
};

#endif //_TEXTFIELD_T_H