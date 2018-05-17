#include "physOb_t.h"

bool equal(float &a, float &b) {

	return (abs(a - b) < std::numeric_limits<float>::epsilon()) ? true : false;
}

bool inInterval(float &x, float a, float b) {
	return (x > a && x < b) ? true : false;
}
physOb_t::physOb_t()
{
	dX = 0.f;
	dY = 0.f;
	posX = 0;
	posY = 0;
	destroyble = false;
	alive = true;
	hitsToDestroy = 1;
	collision = true;
	spritePref.setSpritePos(posX, posY);

	fraction = -1;
}

physOb_t::physOb_t(float _posX, float _posY) {
	dX = 0.f;
	dY = 0.f;
	posX = _posX;
	posY = _posY;
	destroyble = false;
	alive = true;
	hitsToDestroy = 1;
	collision = true;
	spritePref.setSpritePos(posX, posY);
	fraction = -1;
}

physOb_t::physOb_t(float _posX, float _posY, std::string fileName, int _coordX, int _coordY, int _width, int _height) :spritePref(fileName, _coordX, _coordY, _width, _height) {
	dX = 0.f;
	dY = 0.f;
	destroyble = false;
	alive = true;
	hitsToDestroy = 1;
	collision = true;
	fraction = -1;

	posX = _posX;
	posY = _posY;

	spritePref.setSpritePos(posX, posY);

}

physOb_t::physOb_t(float _posX, float _posY, std::shared_ptr<sf::Texture>_texture, int _coordX, int _coordY, int _width, int _height) : spritePref(_texture, _coordX, _coordY, _width, _height) {

	dX = 0.f;
	dY = 0.f;
	destroyble = false;
	alive = true;
	hitsToDestroy = 1;
	collision = true;
	fraction = -1;

	posX = _posX;
	posY = _posY;

	spritePref.setSpritePos(posX, posY);
}


physOb_t::~physOb_t()
{
}

bool physOb_t::kill() {
	alive = false;
	return alive;
}

void physOb_t::update(float _speed) {

	if (alive) {


		if ((dX > 0) && (abs(dY) < FLT_EPSILON)) {
			direction = animation::RIGHT;
		}
		else if ((dX < 0) && (abs(dY) < FLT_EPSILON)) {

			direction = animation::LEFT;
		}
		else if ((dY > 0) && (abs(dX) < FLT_EPSILON)) {

			direction = animation::BOTTOM;
		}
		else if ((dY < 0) && (abs(dX) < FLT_EPSILON)) {
			direction = animation::TOP;
		}


		posX += dX * _speed;
		posY += dY * _speed;

		dX = 0.f;
		dY = 0.f;

		spritePref.setSpritePos(posX, posY);
		updateFrame();
		animation();
	}

}

bool physOb_t::checkCollision(physOb_t &Object) {
	if (getFloatRect().intersects(Object.getCollisionRect())) {
		return true;
	}
	return false;
}

bool physOb_t::collisionHandler(physOb_t &Object, float _speed, float _borderError) {
	
	if (collision && Object.collision) {
		float zero = std::numeric_limits<float>::epsilon();
		float speedX = abs(dX) * _speed;
		float speedY = abs(dY) * _speed;
		
		if (direction == animation::RIGHT) {
			posX = Object.getPosX() - getWidth() - _borderError;
		} else if (direction == animation::LEFT) {
			posX = Object.getPosX() + Object.getWidth() + _borderError;
		} else if (direction == animation::BOTTOM) {
			posY = Object.getPosY() - getHeight() - _borderError;
		} else if (direction == animation::TOP) {
			posY = Object.getPosY() + Object.getHeight() + _borderError;
		}
		dX = 0;
		dY = 0;
		return true;
	}
	return false;
}



bool physOb_t::checkTimer(sf::Clock *clock, sf::Int32 startTime, sf::Int32 _time) {

	sf::Int32 curTime = clock->getElapsedTime().asMilliseconds();

	return (abs(curTime - startTime) > _time) ? false : true;
}

bool physOb_t::checkAlive() {
	if (alive) {
		alive = (hitsToDestroy > 0) ? true : false;
	}
	return alive;
}

float physOb_t::takeDamage(float _dmg, bool _dmgType, elements::element _elem) {
	if (alive) {
		
			--hitsToDestroy;
		
	}
	return _dmg;
}

float physOb_t::takeHeal(float _heal) {
	if (alive) {
		++hitsToDestroy;
	}
	return _heal;
}


void physOb_t::updateFrame() {

	frame += animation::frameSpeed;
	if (frame > animation::frameRate) {
		frame -= animation::frameRate;
	}
}
void physOb_t::animation() {

}


//GET
sf::FloatRect physOb_t::getCollisionRect() const {
		float correctionError = animation::HEROES_SPRITE_COLLISION_CORRECTION_BORDER;
		return sf::FloatRect(posX + correctionError, posY + correctionError, getWidth()- correctionError,getHeight() - correctionError);
	}

	physOb_t *physOb_t::getPtr() {
		return this;
	}

	float physOb_t::getFrame() const {
		return frame;
	}
	obPreference &physOb_t::getSpritePref() {
		return spritePref;
	}
	sf::Sprite &physOb_t::getSprite() {
		return spritePref.getSprite();
	}
	int physOb_t::getWidth() const {
		return spritePref.getWidth();
	}
	int physOb_t::getHeight()const {
		return spritePref.getHeight();
	}
	int physOb_t::getFraction() const {
		return fraction;
	}

	float physOb_t::getdX() const {
		return dX;
	}

	float physOb_t::getdY() const {
		return dY;
	}

	float physOb_t::getPosX() const {
		return posX;
	}

	float physOb_t::getPosY() const {
		return posY;
	}

	bool physOb_t::getDestroyble() const {
		return destroyble;
	}

	bool physOb_t::getAlive() const {
		return alive;
	}

	bool physOb_t::getCollision() const {
		return collision;
	}

	int physOb_t::gethitsToDestroy() const {
		return hitsToDestroy;
	}

	sf::Int32 physOb_t::getStartTime() const {
		return 0;
	}
	sf::Int32 physOb_t::getTimeCd()const {
		return std::numeric_limits<sf::Int32>::max();
	}

	sf::Vector2f physOb_t::getPos() const {	
		return sf::Vector2f (posX, posY);
	}

	sf::Vector2f physOb_t::getPosOfCenter() const {
		return sf::Vector2f(posX + getWidth()/2, posY + getHeight() / 2);
	}
	sf::FloatRect physOb_t::getFloatRect() const {
		return sf::FloatRect(posX, posY, static_cast<float>(getWidth()), static_cast<float>(getHeight()));
	}

	//SET


	void physOb_t::setSpriteSize(int _x, int _y){
		spritePref.setSize(_x, _y);
	}
	void physOb_t::setRotation(float _val) {
		spritePref.setRotation(_val);
	}
	float physOb_t::setPosX(float _x){
		posX = _x;
		return posX;
	}

	float physOb_t::setPosY(float _y){
		posY = _y;
		return posY;
	}
	int physOb_t::setFraction(int _fract) {
		fraction = _fract;
		return fraction;
	}
	bool physOb_t::setDestroyble(bool _d){
		destroyble = _d;
		return destroyble;
	}

	bool physOb_t::setAlive(bool _live){
		alive = _live;
		return alive;
	}

	bool physOb_t::setCollision(bool _collision){
		collision = _collision;
		return collision;
	}

	int physOb_t::sethitsToDestroy(int _hitsToDestroy){
		hitsToDestroy = _hitsToDestroy;
		return hitsToDestroy;
	}

	void physOb_t::setTexturePtr(std::shared_ptr<sf::Texture> &newTexture) {
		spritePref.setTexturePtr(newTexture);
	}


	float physOb_t::setdX(float _x) {
		dX = _x;
		return dX;
	}

	float physOb_t::setdY(float _y) {
		dY = _y;
		return dY;
	}