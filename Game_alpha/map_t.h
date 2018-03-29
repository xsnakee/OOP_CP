#pragma once

#include <SFML/Graphics.hpp>
#include "ground_t.h"
#include "additional.h"
#include <list>

class map_t
{
private:

	int sizeX;
	int sizeY;
	int tileAmountX;
	int tileAmountY;
	std::string mapFileName;
	std::string tileFileName;

public:
	std::list<ground_t*> groundTilesList;

	map_t();
	map_t(std::string mapFileName, int _sizeX, int _sizeY, std::string _tileFileName);
	~map_t();
	
public:
	void fillTheMap();
	void drawMap();

public:
	//GET

	sf::Vector2i getSize() const {
		sf::Vector2i temp(sizeX, sizeY);
		return temp;
	}

	sf::Vector2i getTileAmount() const {
		sf::Vector2i temp(tileAmountX,tileAmountY);
		return temp;
	}

};

