#include "Collider.h"



Collider::Collider(sf::Sprite &body) :
	body(body)
{
}


Collider::~Collider()
{
}

bool Collider::checkCollision(Collider &other) {
	sf::Vector2f otherPos = other.GetPosition();
	sf::Vector2f otherHalfSize = other.GetHalfSize();
	sf::Vector2f thisPos = GetPosition();
	sf::Vector2f thisHalfSize = GetHalfSize();

	float deltaX = otherPos.x - thisPos.x;
	float deltaY = otherPos.y - thisPos.y;
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	if (intersectX < 0.0f && intersectY < 0.0f) {
		return true;
	}

	return false;
}

sf::Vector2f Collider::GetPosition() {
	return body.getPosition();
}

sf::Vector2f Collider::GetHalfSize() {
	sf::FloatRect bounds = body.getGlobalBounds();
	sf::Vector2f size(bounds.width/2.0, bounds.height/2.0);
	return size;

}

void Collider::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	//target.draw(_Sprite, states);
}