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
			groundTilesList.push_back(new ground_t(j*tiles::size,i*tiles::size,tileFileName,((tileId % tileAmountX)*tiles::size),(tileId % tileAmountX)*tiles::size));
			
		
		}
	}

	
}