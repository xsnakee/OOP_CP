#pragma once

#include <SFML/Graphics.hpp>
#include "ground_t.h"
#include "additional.h"
#include <memory>
#include <list>

const std::string IMG_MAP_PATH = "img/maps/";
const std::string MAP_BG_FILE_NAME = "/bg.png";

const std::string MAP_PATH = "maps/";
const std::string MAP_OBJ_FILE_NAME = "/map.csv";

const std::string TILE_FILE_PATH = "img/objects/TilesTexture.png";

class map_t
{
private:

	int sizeX;
	int sizeY;
	int tileAmountX;
	int tileAmountY;
	std::string levelName;
	std::string mapObjectsFile;
	std::string mapBgTextureFile;

	std::string tileFileName;
	sf::Texture *tile_texture;
	sf::Texture *mapBgTexture;
	
	
public:
	sf::Sprite mapBgSprite;
	//std::list<ground_t*> groundTilesList;
	std::list<physOb_t*> mapObList;

	map_t();
	map_t(std::string _levelName);
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

