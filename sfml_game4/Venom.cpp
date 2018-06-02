#include "Venom.h"



Venom::Venom()
{
}

Venom::Venom(sf::Texture& imgPath, int wWidth, int wHeight) {
	_Sprite.setTexture(imgPath);
	_Sprite.setPosition(sf::Vector2f(wWidth / 2.0, wHeight / 2.0));
	_Sprite.setOrigin(imgPath.getSize().x / 2.0, imgPath.getSize().y / 2.0);
	_Sprite.setScale(0.06, 0.06);
}


Venom::~Venom()
{
}

void Venom::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw(_Sprite, states);
}

char Venom::getType() {
	return 'v';
}
