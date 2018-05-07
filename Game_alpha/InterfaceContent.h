#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class InterfaceContent
{
	
public:
	InterfaceContent();
	virtual ~InterfaceContent();
	virtual void draw(sf::RenderWindow *window) = 0;
	virtual void setPref() = 0;
};




class InterfaceSpriteOb_t {
	std::unique_ptr<sf::Texture> texture;
	std::unique_ptr<sf::Sprite> sprite;

	InterfaceSpriteOb_t(sf::Texture *_texture);
	~InterfaceSpriteOb_t();

	//GET
	sf::Sprite getSprite() const {
		return *sprite.get();
	}


	//SET
	void setTexture(sf::Texture *newTexture) {
		texture = std::move(std::unique_ptr<sf::Texture>(newTexture));
		sprite->setTexture(*texture.get());
	}

};