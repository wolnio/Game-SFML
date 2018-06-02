#include"Body.h"

Body::Body(){

}

Body::Body(sf::Texture& imgPath, int wWidth, int wHeight) {
	_Sprite.setTexture(imgPath);
	_Sprite.setPosition(sf::Vector2f(wWidth / 2.0, wHeight / 2.0));
	_Sprite.setOrigin(imgPath.getSize().x / 2.0, imgPath.getSize().y / 2.0);
	_Sprite.setScale(0.025,0.025);
	//_direction = direct;
	//_Sprite.setColor(sf::Color( 255, 0, 0, 10));
	
}

Body::~Body() {

}

void Body::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw(_Sprite, states);
}

void Body::drawBody(sf::RenderWindow& window) {
	window.draw(_Sprite);
}

void Body::setDirection(int direct) {
	_direction = direct;
}

int Body::getDirection() {
	return _direction;
}

void Body::moveUp(double speed,float time, float multi) {
	_Sprite.move(sf::Vector2f(0, -speed*time*multi));
}

void Body::moveDown(double speed, float time, float multi) {
	_Sprite.move(sf::Vector2f(0, speed*time*multi));
}

void Body::moveLeft(double speed, float time, float multi) {
	_Sprite.move(sf::Vector2f(-speed*time*multi, 0));
}

void Body::moveRight(double speed, float time, float multi) {
	_Sprite.move(sf::Vector2f(speed*time*multi, 0));
}

void Body::setPosX(float x, float y) {
	_Sprite.setPosition(x, y);
}

float Body::getPosX() {
	return _Sprite.getPosition().x;
}

float Body::getPosY() {
	return _Sprite.getPosition().y;
}

void Body::makeTransparent() {
	_Sprite.setColor(sf::Color(0, 0, 0, 0));
}

