#pragma once
#include "Body.h"
class Spiderman :public Body{
private:

public:
	Spiderman();
	Spiderman(sf::Texture& imgPath, int wWidth, int wHeight);
	~Spiderman();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	char getType();
};

