#include "Spiderman.h"

Spiderman::Spiderman()
{
}

Spiderman::Spiderman(sf::Texture& imgPath, int wWidth, int wHeight) {
	_Sprite.setTexture(imgPath);
	_Sprite.setPosition(sf::Vector2f(wWidth / 2.0, wHeight / 2.0));
	_Sprite.setOrigin(imgPath.getSize().x / 2.0, imgPath.getSize().y / 2.0);
	_Sprite.setScale(0.14, 0.14);
	
}

Spiderman::~Spiderman()
{
}

void Spiderman::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw(_Sprite, states);
}

char Spiderman::getType() {
	return 's';
}