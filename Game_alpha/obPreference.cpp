#include "obPreference.h"

obPreference::obPreference() {

	spriteCoordX = 0;
	spriteCoordY = 0;
	height = DEFAULT_HEIGHT;
	width = DEFAULT_WIDTH;
	texture = std::make_shared<sf::Texture>();
	texture->loadFromFile("img/default.png");
	sprite.setTexture(*texture);
	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY,width,height));
}

obPreference::obPreference(std::string _fileTexturePath)
{

	spriteCoordX = 0;
	spriteCoordY = 0;
	height = DEFAULT_HEIGHT;
	width = DEFAULT_WIDTH;

	texture = std::make_shared<sf::Texture>();
	texture->loadFromFile(_fileTexturePath);

	sprite.setTexture(*texture);

	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, width, height));
}

obPreference::obPreference(std::string _fileTexturePath, int _coordX, int _coordY, int _width, int _height){

	spriteCoordX = _coordX;
	spriteCoordY = _coordY;
	height = _height;
	width = _width;

	texture = std::make_shared<sf::Texture>();
	texture->loadFromFile(_fileTexturePath);
	sprite.setTexture(*texture);
	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, width, height));
}

obPreference::obPreference(std::shared_ptr<sf::Texture> &_texture, int _coordX, int _coordY, int _width, int _height) {

	spriteCoordX = _coordX;
	spriteCoordY = _coordY;
	height = _height;
	width = _width;

	texture = _texture;

	sprite.setTexture(*texture);
	sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, width, height));
}

obPreference::~obPreference()
{
	
}


void obPreference::setOriginToCenter() {
	sprite.setOrigin(static_cast<float>(width) / 2, static_cast<float>(height) / 2);
}

//GET
	std::shared_ptr<sf::Texture> &obPreference::getTextureSharedPtr(){
		return texture;
	}

	sf::Texture obPreference::getTexture() const{
		return *texture;
	}

	sf::Sprite &obPreference::getSprite() {
		return sprite;
	}

	int obPreference::getCoordX() const {
		return spriteCoordX;
	}
	int obPreference::getCoordY() const {
		return spriteCoordY;
	}
	int obPreference::getHeight() const {
		return height;
	}
	int obPreference::getWidth() const {
		return width;
	}

	//SET
	void obPreference::setTexturePtr(std::shared_ptr<sf::Texture> &newTexture) {
		texture = newTexture;
		sprite.setTexture(*texture);
	}

	void obPreference::setTexturePos(int coordX, int coordY) {
		spriteCoordX = coordX;
		spriteCoordY = coordY;
		sprite.setTextureRect(sf::IntRect(coordX,coordY,width,height));
	}
	void obPreference::setSize( int newWidth,int newHeight) {
		width = newWidth;
		height = newHeight;
		sprite.setTextureRect(sf::IntRect(spriteCoordX, spriteCoordY, width, height));
	}

	void obPreference::setSpritePos(float coordX, float coordY) {
		sprite.setPosition(coordX, coordY);
	}

	void obPreference::setRotation(float _rotation) {
		sprite.setRotation(_rotation);
	}

	//FOR CHECK COLLISION
	sf::FloatRect obPreference::getRect()const {
		sf::FloatRect rect(static_cast<float>(spriteCoordX), static_cast<float>(spriteCoordY), static_cast<float>(width), static_cast<float>(height));
		return rect;
	}