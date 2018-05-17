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
	bool checkCollision(physOb_t &Object);
	virtual bool collisionHandler(physOb_t &Object, float _speed, float _borderError = -15.f);
	virtual bool checkAlive();
	virtual float takeDamage(float _dmg, bool _dmgType, elements::element _elem);
	virtual float takeHeal(float _heal);

	//GET
	sf::FloatRect getCollisionRect() const;
	physOb_t *getPtr();
	float getFrame() const;
	obPreference &getSpritePref();
	void setSpriteSize(int _x, int _y);
	void setRotation(float _val);
	sf::Sprite &getSprite();
	int getWidth() const;
	int getHeight()const;
	int getFraction() const;
	float getdX() const;
	float getdY() const;
	float getPosX() const;
	float getPosY() const;
	bool getDestroyble() const;
	bool getAlive() const;
	bool getCollision() const;
	int gethitsToDestroy() const;
	virtual sf::Int32 getStartTime() const;
	virtual sf::Int32 getTimeCd()const;
	sf::Vector2f getPos() const;
	sf::Vector2f getPosOfCenter() const;
	sf::FloatRect getFloatRect() const;

	//SET
	float setPosX(float _x);
	float setPosY(float _y);
	int setFraction(int _fract);
	bool setDestroyble(bool _d);
	bool setAlive(bool _live);
	bool setCollision(bool _collision);
	int sethitsToDestroy(int _hitsToDestroy);
	void setTexturePtr(std::shared_ptr<sf::Texture> &newTexture);
	float setdX(float _x);
	float setdY(float _y);
};

