#ifndef _GAME_T_H
#define _GAME_T_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include "char_t.hpp"
#include "physPref_t.hpp"
#include "playerInterface_t.hpp"

//*
class tile_t {
public: 
    //ground_t *tileOb;
};


class game_t {

public: 
    //std::list<physOb_t> obList;
	std::list<character_t> charList;
	//std::list<playerInterface_t> interfaceOb;
//    map_t map;

	game_t();
	~game_t();


};


class map_t {
public: 
    size_t height;
    size_t width;
    size_t **gameField;
	//std::vector<ground_t> tile;
    float bordersSize;
    tile_t *tiles;
};

//*/
#endif //_GAME_T_H