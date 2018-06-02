#pragma once
#include "Body.h"
class Hulk :public Body{
private:

public:
	Hulk();
	Hulk(sf::Texture& imgPath, int wWidth, int wHeight);
	~Hulk();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	char getType();
};

