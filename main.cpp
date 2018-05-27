#include <SFML/Graphics.hpp>
#include<vector>
#include"Body.h"
#include<iostream>
#include"Ironman.h"

int main()
{
	int w_width = 1000, w_height = 700;
	float x = w_width / 2.0, y = w_height / 2.0;
	double speed = 1.5;

	sf::RenderWindow window(sf::VideoMode(w_width, w_height), "Snake practise");

	sf::RectangleShape map;
	map.setSize(sf::Vector2f(700, 500));
	map.setOrigin(map.getSize().x / 2.0, map.getSize().y / 2.0);
	map.setPosition(w_width / 2.0, w_height / 2.0);
	map.setFillColor(sf::Color::White);

	enum Direction { UP, DOWN, RIGHT, LEFT };

	int direct = UP;


	sf::Texture pTexture;
	pTexture.setSmooth(false);
	if (!pTexture.loadFromFile("image/cp_shield.png"))
		std::cerr << "Error texture!" << std::endl;

	sf::Texture ironTexture;
	if (!ironTexture.loadFromFile("image/ironman.png"))
		std::cerr << "Error ironman!" << std::endl;
	
	std::vector<Body> snake;
	Body head(pTexture, w_width, w_height);
	snake.push_back(head);

	Ironman glowa(ironTexture, w_width, w_height);
	

	for (int i = 1; i < 300; i++) {

		if (i <= 32) {
			Ironman newIron(ironTexture, w_width, w_height);

			snake.push_back(newIron);
		}
		else {
			Body newPart(pTexture, w_width, w_height);

			snake.push_back(newPart);
		}
	}

	for (int i = 1; i < snake.size(); i++) {
		if (i % 27 != 0) {
			snake[i].makeTransparent();
		}
	}

	sf::View view;
	view.setCenter(sf::Vector2f(0,0));
	view.setSize(w_width, w_height);
	

	while (window.isOpen())
	{
		sf::Vector2f lastPosition(snake[0].getPosX(),snake[0].getPosY());

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//textures
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snake[0].getDirection() != DOWN) {
			snake[0].setDirection(UP);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && snake[0].getDirection() != UP) {
			snake[0].setDirection(DOWN);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && snake[0].getDirection() != LEFT) {
			snake[0].setDirection(RIGHT);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && snake[0].getDirection() != RIGHT) {
			snake[0].setDirection(LEFT);
		}

		if (snake[0].getDirection() == UP) {
			snake[0].moveUp(speed);
		}
		else if (snake[0].getDirection() == DOWN) {
			snake[0].moveDown(speed);
		}
		else if (snake[0].getDirection() == LEFT) {
			snake[0].moveLeft(speed);
		}
		else if (snake[0].getDirection() == RIGHT) {
			snake[0].moveRight(speed);
		}

		view.setCenter(snake[0].getPosX(), snake[0].getPosY());
		

		//movement
		sf::Vector2f newPosition(lastPosition);

		for (int i = 1; i < snake.size(); i++) {
			sf::Vector2f lastPosition(snake[i].getPosX(), snake[i].getPosY());
			//lastPosition = snake[i].getPosition();
			snake[i].setPosX(newPosition.x,newPosition.y);
			newPosition = lastPosition;
			
		}
				
		window.clear();

		window.setView(view);
		
		window.draw(map);
		window.draw(glowa);

		for (auto itr : snake)
			window.draw(itr);
			//itr.drawBody(window);

		window.display();
	}

	return 0;
}