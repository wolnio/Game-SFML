#pragma once

#include"Body.h"

class Ironman :public Body {
public:
	Ironman();
	Ironman(sf::Texture& imgPath, int wWidth, int wHeight);
	~Ironman();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	char getType();
private:
	//char _type = 'i';
};
