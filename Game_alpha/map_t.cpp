#include "map_t.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctype.h>

map_t::map_t()
{
}
//GET

std::string map_t::getLvlName() const {
	return levelName;
}


map_t::map_t(std::string _levelName) {

	levelName = _levelName;
	//LOAD MAP BG
	mapObjectsFile = MAP_PATH + levelName + MAP_OBJ_FILE_NAME;
	mapBgTilesFile = MAP_PATH + levelName + MAP_BG_TILES_FILE_NAME;
	mapOutTilesFile = MAP_PATH + levelName + MAP_OUT_TILES_FILE_NAME;;


	//LOAD MAP OBJECTS
	tileFileName = TILE_FILE_PATH;
	tile_texture = std::make_shared<sf::Texture>();
	tile_texture->loadFromFile(tileFileName);

	//CALC MAP SIZEs
	tileAmountX = 272;
	tileAmountY = 143;

	size.x = tileAmountX * tiles::size;
	size.y = tileAmountY*tiles::size;
	size_t bossesAmount = 5;
	bossesSpawnCoords = std::vector<sf::Vector2f>(bossesAmount);
}

map_t::~map_t()
{
}


bool map_t::fillTheMapObj() {
	using namespace std;

	ifstream MAP_FILE(mapObjectsFile, ios::in);
	if (!MAP_FILE) {
		cout << "OPEN FILE ERROR" << endl;
		return false;
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
				mapObList.push_back(std::unique_ptr<physOb_t>(new physOb_t(static_cast<float>(coordX), static_cast<float>(coordY), tile_texture, spritePosX, spritePosY, tiles::size, tiles::size)));
			}
			
		
		}
	}
	return true;
	
}


bool map_t::fillTheMapTiles() {
	using namespace std;

	ifstream MAP_BG_FILE(mapBgTilesFile, ios::in);
	if (!MAP_BG_FILE) {
		cout << "OPEN FILE1 ERROR" << endl;
		return false;
	}

	ifstream MAP_OUT_FILE(mapOutTilesFile, ios::in);
	if (!MAP_OUT_FILE) {
		cout << "OPEN FILE2 ERROR" << endl;
		return false;
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
				groundTilesList.push_back(std::unique_ptr<ground_t>(new ground_t(tile_texture, static_cast<float>(coordX), static_cast<float>(coordY), spritePosX, spritePosY, tileId)));
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
			switch (tileId) {
			case 1281: {
				sf::Vector2f temp(static_cast<float>(coordX), static_cast<float>(coordY));
				mainHeroSpawnCoords = temp;
				break;
			}
			case 1282: {
				sf::Vector2f temp(static_cast<float>(coordX), static_cast<float>(coordY));
				bossesSpawnCoords[0] = temp; // TREANT SPAWN
				break;
			}
			case 1283: {
				sf::Vector2f temp(static_cast<float>(coordX), static_cast<float>(coordY));
				bossesSpawnCoords[1] = temp; //RED DRAGON SPAWN
				break;
			}case 1284: {
				sf::Vector2f temp(static_cast<float>(coordX), static_cast<float>(coordY));
				bossesSpawnCoords[2] = temp; //BLACK DRAGON SPAWN
				break;
			}case 1285: {
				sf::Vector2f temp(static_cast<float>(coordX), static_cast<float>(coordY));
				bossesSpawnCoords[3] = temp; //ENH SPAWN
				break;
			}case 1286: {
				sf::Vector2f temp(static_cast<float>(coordX), static_cast<float>(coordY));
				bossesSpawnCoords[4] = temp; //DARK QUEEN SPAWN
				break;
			}
			default: {
				if (tileId != -1) {
					groundTilesList.push_back(std::unique_ptr<ground_t>(new ground_t(tile_texture, static_cast<float>(coordX), static_cast<float>(coordY), spritePosX, spritePosY, tileId)));
				}
			}
			}

			
			//*/


		}
	}

	return true;
}


//GET

	sf::Vector2i map_t::getSize() const {
		return size;
	}
	sf::Vector2f map_t::getFloatSize() const {
		return sf::Vector2f(static_cast<float>(size.x), static_cast<float>(size.y));
	}

	sf::Vector2i map_t::getTileAmount() const {
		sf::Vector2i temp(tileAmountX,tileAmountY);
		return temp;
	}
	