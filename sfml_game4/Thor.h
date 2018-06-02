#pragma once
#include "Body.h"
class Thor :public Body{
private:

public:
	Thor();
	Thor(sf::Texture& imgPath, int wWidth, int wHeight);
	~Thor();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	char getType();
};

