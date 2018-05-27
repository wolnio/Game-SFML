#pragma once

#include<SFML/Graphics.hpp>

class Body:public sf::Drawable,sf::Transformable {
public:
	Body();
	Body(sf::Texture& imgPath,int wWidth, int wHeight);
	~Body();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	void drawBody(sf::RenderWindow& window);
	void setDirection(int direct);
	int getDirection();
	void moveUp(double speed);
	void moveDown(double speed);
	void moveLeft(double speed);
	void moveRight(double speed);
	void setPosX(float x, float y);
	void setPosY();
	float getPosX();
	float getPosY();
	void makeTransparent();
private:
	sf::Sprite _Sprite;
	sf::Texture _Texture;
	enum _Direction { UP, DOWN, LEFT, RIGHT };
	int _direction = UP;
	float posX, posY;
};
