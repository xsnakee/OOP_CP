#pragma once

#include <SFML\Graphics.hpp>
#include "obPreference.h"
#include "additional.h"

class physOb_t
{
protected:
	obPreference spritePref;

	float posX;
	float posY;
	float dX;
	float dY;
	bool destroyble;
	bool alive;
	int hitsToDestroy;
	bool collision;

	int fraction;
	animation::direction direction;

	std::vector<int> dropList;

	float frame;


	virtual void animation();
	virtual void updateFrame();
	virtual bool checkTimer(sf::Clock *clock, sf::Int32 startTime, sf::Int32 _time);
public:

	physOb_t();
	physOb_t(float _posX, float _posY);	
	physOb_t(float _posX, float _posY, std::string fileName, int _coordX, int _coordY, int _width, int _height);
	physOb_t(float _posX, float _posY, std::shared_ptr<sf::Texture>_texture,  int _coordX, int _coordY, int _width, int _height);

	virtual ~physOb_t();
	
	virtual bool kill();
	virtual void update(float _speed);
	bool checkCollision(physOb_t &Object, float _borderError = 0.f);
	virtual bool collisionHandler(physOb_t &Object, float _speed, float _borderError = 2.f);

	virtual bool checkAlive();
	virtual float takeDamage(float _dmg, bool _dmgType, elements::element _elem);
	virtual float takeHeal(float _heal);

	//GET
	sf::FloatRect getCollisionRect() const {
		float correctionError = animation::HEROES_SPRITE_COLLISION_CORRECTION_BORDER;
		return sf::FloatRect(posX + correctionError, posY + correctionError, getWidth()- correctionError,getHeight() - correctionError);
	}

	physOb_t *getPtr() {
		return this;
	}

	float getFrame() const {
		return frame;
	}
	obPreference &getSpritePref() {
		return spritePref;
	}
	void setSpriteSize(int _x, int _y){
		spritePref.setSize(_x, _y);
	}
	void setRotation(float _val) {
		spritePref.setRotation(_val);
	}
	sf::Sprite &getSprite() {
		return spritePref.getSprite();
	}
	int getWidth() const {
		return spritePref.getWidth();
	}
	int getHeight()const {
		return spritePref.getHeight();
	}
	int getFraction() const {
		return fraction;
	}

	float getdX() const {
		return dX;
	}

	float getdY() const {
		return dY;
	}

	float getPosX() const {
		return posX;
	}

	float getPosY() const {
		return posY;
	}

	bool getDestroyble() const {
		return destroyble;
	}

	bool getAlive() const {
		return alive;
	}

	bool getCollision() const {
		return collision;
	}

	int gethitsToDestroy() const {
		return hitsToDestroy;
	}

	virtual sf::Int32 getStartTime() const {
		return 0;
	}
	virtual sf::Int32 getTimeCd()const {
		return std::numeric_limits<sf::Int32>::max();
	}

	sf::Vector2f getPos() const {	
		return sf::Vector2f (posX, posY);
	}

	sf::Vector2f getPosOfCenter() const {
		return sf::Vector2f(posX + getWidth()/2, posY + getHeight() / 2);
	}
	sf::FloatRect getFloatRect() const {
		return sf::FloatRect(posX, posY, static_cast<float>(getWidth()), static_cast<float>(getHeight()));
	}

	//SET
	float setPosX(float _x){
		posX = _x;
		return posX;
	}

	float setPosY(float _y){
		posY = _y;
		return posY;
	}
	int setFraction(int _fract) {
		fraction = _fract;
		return fraction;
	}
	bool setDestroyble(bool _d){
		destroyble = _d;
		return destroyble;
	}

	bool setAlive(bool _live){
		alive = _live;
		return alive;
	}

	bool setCollision(bool _collision){
		collision = _collision;
		return collision;
	}

	int sethitsToDestroy(int _hitsToDestroy){
		hitsToDestroy = _hitsToDestroy;
		return hitsToDestroy;
	}

	void setTexturePtr(std::shared_ptr<sf::Texture> &newTexture) {
		spritePref.setTexturePtr(newTexture);
	}


	float setdX(float _x) {
		dX = _x;
		return dX;
	}

	float setdY(float _y) {
		dY = _y;
		return dY;
	}
};

