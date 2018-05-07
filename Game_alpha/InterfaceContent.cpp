#include "InterfaceContent.h"



InterfaceContent::InterfaceContent()
{
}


InterfaceContent::~InterfaceContent()
{
}

//SPRITE OB
InterfaceSpriteOb_t::InterfaceSpriteOb_t(sf::Texture *_texture) {
	setTexture(_texture);
}

InterfaceSpriteOb_t::~InterfaceSpriteOb_t() {

}
