#ifndef _PLAYERINTERFACE_T_H
#define _PLAYERINTERFACE_T_H


class heroInterface_t {
public: 
    float coordX;
    floatY coordY;
    size_t height;
    size_t width;
    bool clickable;
    border_t border;
};



class bar_t: public heroInterface_t {
public: 
    color color;
    float maxSize;
    float curVal;
};



class border_t {
public: 
    size_t borderSize;
    color borderColor;
    heroInterface_t 1;
};


class textField_t: public heroInterface_t {
public: 
    size_t fontSize;
    color color;
    string content;
};


class window_t: public heroInterface_t {
};
#endif //_PLAYERINTERFACE_T_H