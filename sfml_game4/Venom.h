#pragma once
#include "Body.h"
class Venom :public Body{
public:
	Venom();
	Venom(sf::Texture& imgPath, int wWidth, int wHeight);
	~Venom();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	char getType();
};

