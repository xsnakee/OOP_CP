#include "map_t.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctype.h>

map_t::map_t()
{
}

map_t::map_t(std::string _mapFileName, int _sizeX, int _sizeY,std::string _tileFileName) {
	sizeX = _sizeX* tiles::size;
	sizeY = _sizeY * tiles::size;
	tileAmountX = _sizeX;
	tileAmountY = _sizeY;
	mapFileName = _mapFileName;
	tileFileName = _tileFileName;
	tile_texture = new sf::Texture;

	tile_texture->loadFromFile(tileFileName);
}

map_t::~map_t()
{
	delete tile_texture;
}


void map_t::fillTheMap() {
	using namespace std;

	ifstream MAP_FILE(mapFileName, ios::in);
	if (!MAP_FILE) {
		cout << "OPEN FILE ERROR" << endl;
		return;
	}
	int tileId;

	for (size_t i = 0; i < tileAmountY; ++i) {
		for (size_t j = 0; j < tileAmountX; ++j) {

			MAP_FILE >> tileId;
			MAP_FILE.get();
			int coordX = j * tiles::size;
			int coordY = i * tiles::size;

			int spritePosY = ((tileId / tiles::TEXTURE_TILE_AMOUNT_X)*tiles::size);
			int spritePosX = ((tileId % tiles::TEXTURE_TILE_AMOUNT_X)*tiles::size);

			groundTilesList.push_back(new ground_t(tile_texture,coordX, coordY,spritePosX,spritePosY, tileId));
			
			if (tileId > 200) {
				obTextureList.push_back(groundTilesList.back());
			}
		
		}
	}

	
}