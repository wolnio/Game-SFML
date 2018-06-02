#pragma once

#include<SFML/Graphics.hpp>
#include"Collider.h"

class Body:public sf::Drawable,sf::Transformable {
public:
	Body();
	Body(sf::Texture& imgPath,int wWidth, int wHeight);
	~Body();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	virtual char getType() = 0;
	void drawBody(sf::RenderWindow& window);
	void setDirection(int direct);
	int getDirection();
	void moveUp(double speed, float time, float multi);
	void moveDown(double speed, float time, float multi);
	void moveLeft(double speed, float time, float multi);
	void moveRight(double speed, float time, float multi);
	void setPosX(float x, float y);
	void setPosY();
	float getPosX();
	float getPosY();
	void makeTransparent();
	Collider GetCollider() { return Collider(_Sprite); }
protected:
	sf::Sprite _Sprite;
	sf::Texture _Texture;
	enum _Direction { UP, DOWN, LEFT, RIGHT };
	int _direction = UP;
	float posX, posY;
};
