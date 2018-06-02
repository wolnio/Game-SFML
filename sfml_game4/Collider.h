#pragma once
#include<SFML/Graphics.hpp>

class Collider: public sf::Drawable
{
public:
	Collider(sf::Sprite &body);
	~Collider();
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;

	bool checkCollision(Collider &other);
	sf::Vector2f GetPosition();
	sf::Vector2f GetHalfSize();
private:
	sf::Sprite &body;
};

