#ifndef _PHYS_OB_H
#define _PHYS_OB_H

#include <SFML/Graphics.hpp>
#include <vector>

/*
class physPref_t {
protected: 
    float coordX;
    float CoordY;
    sf::Texture Texture;
    size_t height;
    size_t width;
    
    void Operation1();
};

//GROUND TILES

class ground_t: public physPref_t {
protected: 
    effect_t effects;
};

class Sand_t: public ground_t {
};

class Water_t: public ground_t {
};

class Grace_t: public ground_t {
};


//PHYSIC OBJECTS
class physOb_t: public physPref_t {
protected: 
    bool destroyble;
	float HP;
    bool collision;
};


class staticOb_t: public physOb_t {
private: 
    std::vector<size_t> dropList;
};


class dynamicOb_t: public physOb_t {
private: 
    sf::Clock timer;
    float dX;
    float dY;
    float range;
    bool AOE;
    
    void trajectory();
};

//BONUS DROP
class bonus_t: public staticOb_t {
public: 
    size_t id;
    effect_t effect;
};

	
class skillOrb_t: public dynamicOb_t {
public: 
    bool AOE;
};

//*/

#endif //_PHYS_OB