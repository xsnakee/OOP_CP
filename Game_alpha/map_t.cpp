#include "map_t.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctype.h>

map_t::map_t()
{
}

map_t::map_t(std::string _levelName) {

	levelName = _levelName;
	//LOAD MAP BG
	mapObjectsFile = MAP_PATH + levelName + MAP_OBJ_FILE_NAME;
	/*
	mapBgTextureFile = IMG_MAP_PATH + levelName + MAP_BG_FILE_NAME;
	mapBgTexture = new sf::Texture;
	mapBgTexture->loadFromFile(mapBgTextureFile);
	mapBgSprite.setTexture(*mapBgTexture);
	mapBgSprite.setPosition(.0f, .0f);
	//*/
	mapBgTilesFile = MAP_PATH + levelName + MAP_BG_TILES_FILE_NAME;
	mapOutTilesFile = MAP_PATH + levelName + MAP_OUT_TILES_FILE_NAME;;


	//LOAD MAP OBJECTS
	tileFileName = TILE_FILE_PATH;
	tile_texture = new sf::Texture;
	tile_texture->loadFromFile(tileFileName);

	//CALC MAP SIZEs
	tileAmountX = 272;// mapBgTexture->getSize().x / tiles::size;
	tileAmountY = 143;// mapBgTexture->getSize().y / tiles::size;

	sizeX = tileAmountX * tiles::size;//mapBgTexture->getSize().x;
	sizeY = tileAmountY*tiles::size;// mapBgTexture->getSize().y;
}

map_t::~map_t()
{
	delete tile_texture;
	//delete mapBgTexture; 
}


void map_t::fillTheMapObj() {
	using namespace std;

	ifstream MAP_FILE(mapObjectsFile, ios::in);
	if (!MAP_FILE) {
		cout << "OPEN FILE ERROR" << endl;
		return;
	}
	int tileId;

	for (int i = 0; i < tileAmountY; ++i) {
		for (int j = 0; j < tileAmountX; ++j) {

			MAP_FILE >> tileId;
			MAP_FILE.get();
			int coordX = j * tiles::size;
			int coordY = i * tiles::size;

			int spritePosY = ((tileId / tiles::TEXTURE_TILE_AMOUNT_X)*tiles::size);
			int spritePosX = ((tileId % tiles::TEXTURE_TILE_AMOUNT_X)*tiles::size);
			
			//*/
			if (tileId != (-1)) {
				mapObList.push_back(new physOb_t(coordX, coordY, tile_texture, spritePosX, spritePosY, tiles::size, tiles::size));
			}
			
		
		}
	}

	
}


void map_t::fillTheMapTiles() {
	using namespace std;

	ifstream MAP_BG_FILE(mapBgTilesFile, ios::in);
	if (!MAP_BG_FILE) {
		cout << "OPEN FILE1 ERROR" << endl;
		return;
	}

	ifstream MAP_OUT_FILE(mapOutTilesFile, ios::in);
	if (!MAP_OUT_FILE) {
		cout << "OPEN FILE2 ERROR" << endl;
		return;
	}
	int tileId;

	for (int i = 0; i < tileAmountY; ++i) {
		for (int j = 0; j < tileAmountX; ++j) {

			MAP_BG_FILE >> tileId;
			MAP_BG_FILE.get();
			int coordX = j * tiles::size;
			int coordY = i * tiles::size;

			int spritePosY = ((tileId / tiles::TEXTURE_TILE_AMOUNT_X)*tiles::size);
			int spritePosX = ((tileId % tiles::TEXTURE_TILE_AMOUNT_X)*tiles::size);

			//*//IF needed layers view should return this fragment
			if (tileId != -1) {
				groundTilesList.push_back(new ground_t(tile_texture, coordX, coordY, spritePosX, spritePosY, tileId));
			}
			//*/


		}
	}
	for (int i = 0; i < tileAmountY; ++i) {
		for (int j = 0; j < tileAmountX; ++j) {

			MAP_OUT_FILE >> tileId;
			MAP_OUT_FILE.get();
			int coordX = j * tiles::size;
			int coordY = i * tiles::size;

			int spritePosY = ((tileId / tiles::TEXTURE_TILE_AMOUNT_X)*tiles::size);
			int spritePosX = ((tileId % tiles::TEXTURE_TILE_AMOUNT_X)*tiles::size);

			//*//IF needed layers view should return this fragment
			if (tileId != -1) {
				groundTilesList.push_back(new ground_t(tile_texture, coordX, coordY, spritePosX, spritePosY, tileId));
			}
			//*/


		}
	}
}