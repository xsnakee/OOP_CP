#include "map_t.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctype.h>

map_t::map_t()
{
}

map_t::map_t(std::string _mapFileName, int _sizeX, int _sizeY,std::string _tileFileName) {
	sizeX = _sizeX;
	sizeY = _sizeY;
	tileAmountX = _sizeX / tiles::size;
	tileAmountY = _sizeY / tiles::size;
	mapFileName = _mapFileName;
	tileFileName = _tileFileName;
	std::unique_ptr<sf::Texture> _tile_texture(new sf::Texture);

	tile_texture = _tile_texture.get();
	tile_texture->loadFromFile(tileFileName);
}

map_t::~map_t()
{
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
			groundTilesList.push_back(new ground_t(tile_texture, j*tiles::size,i*tiles::size,((tileId % tileAmountX)*tiles::size),(tileId % tileAmountX)*tiles::size));
			
		
		}
	}

	
}