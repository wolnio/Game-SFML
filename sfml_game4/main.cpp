#include <SFML/Graphics.hpp>
#include<vector>
#include"Body.h"
#include<iostream>
#include"Ironman.h"
#include"Hulk.h"
#include"Thor.h"
#include"Spiderman.h"
#include<cstdlib>
#include<ctime>
#include"Venom.h"

int main()
{
	int w_width = 1200, w_height = 900;
	float x = w_width / 2.0, y = w_height / 2.0;
	double speed = 4;

	sf::RenderWindow window(sf::VideoMode(w_width, w_height), "Snake practise");

	//====== MAP=======
	sf::Texture mapTexture;
	if (!mapTexture.loadFromFile("image/grass.png"))
		std::cerr << "Error texture!" << std::endl;

	sf::RectangleShape map;
	map.setSize(sf::Vector2f(1200, 900));
	map.setOrigin(map.getSize().x / 2.0, map.getSize().y / 2.0);
	map.setPosition(w_width / 2.0, w_height / 2.0);
	map.setTexture(&mapTexture);
	map.setOutlineThickness(25);
	sf::Color borderColor(73, 39, 17);
	map.setOutlineColor(borderColor);

	enum Direction { UP, DOWN, RIGHT, LEFT };
	int direct = UP;
	//=====================

	//======== TEXTURES ========
	sf::Texture capTexture;
	if (!capTexture.loadFromFile("image/cp_shield.png"))
		std::cerr << "Error texture!" << std::endl;

	sf::Texture ironTexture;
	if (!ironTexture.loadFromFile("image/ironman.png"))
		std::cerr << "Error ironman!" << std::endl;

	sf::Texture hulkTexture;
	if (!hulkTexture.loadFromFile("image/hulk.png"))
		std::cerr << "Error hulk!" << std::endl;

	sf::Texture thorTexture;
	if (!thorTexture.loadFromFile("image/thor.png"))
		std::cerr << "Error thor!" << std::endl;

	sf::Texture spiderTexture;
	if (!spiderTexture.loadFromFile("image/spiderman.png"))
		std::cerr << "Error spider!" << std::endl;

	sf::Texture venomTexture;
	if (!venomTexture.loadFromFile("image/venom.png"))
		std::cerr << "Error venom!" << std::endl;
	//=========================

	std::vector<Body*> snake;

	snake.push_back(new Body (capTexture, w_width, w_height));

	std::vector<Body*> enemies;

	

	int rate = 12;

	for (int i = 1; i < rate*4; i++) {

		if (i <= rate) {
			snake.push_back(new Ironman (ironTexture, w_width, w_height));
		}
		else if (i > rate&&i <= rate * 2) {
			snake.push_back(new Hulk(hulkTexture, w_width, w_height));
		}
		else if (i > rate * 2 && i <= rate * 3) {
			snake.push_back(new Spiderman(spiderTexture, w_width, w_height));
		}
		else {

			snake.push_back(new Thor(thorTexture, w_width, w_height));
		}
	}

	sf::View view;
	view.setCenter(sf::Vector2f(0,0));
	view.setSize(w_width-200, w_height-200);

//========= FRAMERATE =========
	window.setFramerateLimit(50);

	sf::Clock clock;
	sf::Clock spawnClk;
	float dt;
	float multiplier = 63;

	sf::Time spawnTimer;
//=========================

	srand(time(NULL));

enemies.push_back(new Venom(venomTexture, 200, 200));

Ironman ironman(ironTexture, w_width, w_height);

while (window.isOpen())
{
	sf::Vector2f lastPosition(snake[0]->getPosX(), snake[0]->getPosY());

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

	//============== MOVEMENT =============
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snake[0]->getDirection() != DOWN) {
		snake[0]->setDirection(UP);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && snake[0]->getDirection() != UP) {
		snake[0]->setDirection(DOWN);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && snake[0]->getDirection() != LEFT) {
		snake[0]->setDirection(RIGHT);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && snake[0]->getDirection() != RIGHT) {
		snake[0]->setDirection(LEFT);
	}

	dt = clock.restart().asSeconds();
	spawnTimer = spawnClk.getElapsedTime();

	if (snake[0]->getDirection() == UP) {
		snake[0]->moveUp(speed, dt, multiplier);
	}
	else if (snake[0]->getDirection() == DOWN) {
		snake[0]->moveDown(speed, dt, multiplier);
	}
	else if (snake[0]->getDirection() == LEFT) {
		snake[0]->moveLeft(speed, dt, multiplier);
	}
	else if (snake[0]->getDirection() == RIGHT) {
		snake[0]->moveRight(speed, dt, multiplier);
	}


	view.setCenter(snake[0]->getPosX(), snake[0]->getPosY());


	//movement
	sf::Vector2f newPosition(lastPosition);

	for (int i = 1; i < snake.size(); i++) {
		sf::Vector2f lastPosition(snake[i]->getPosX(), snake[i]->getPosY());
		snake[i]->setPosX(newPosition.x, newPosition.y);
		newPosition = lastPosition;

	}
	//=============================

	for (int i = 1; i < snake.size(); i++) {
		if (i % 11 != 0) {
			snake[i]->makeTransparent();
		}
	}

	for (int i = 0; i < enemies.size(); i++) {
		if (snake[0]->GetCollider().checkCollision(enemies[i]->GetCollider())) {
			enemies.erase(enemies.begin() + i);
			for (int i = 1; i < 12; i++) {
				snake.push_back(new Ironman(ironTexture, w_width, w_height));
			}
		}
	}

	//=========== ENEMY SPAWN ==========
			//int posX = (rand() % 1160*2) + 20;
			//int posY = (rand() % 860*2) + 20;

			//if (spawnTimer.asSeconds() >= 5.0 && spawnTimer.asSeconds() <= 5.15) {
			//	//if (spawnTimer.asSeconds() == 3.1) {
			//	
			//	bool notIntersect = false;
			//	
			//	for (int i = 0; i < snake.size(); i++) {
			//		if ((posX >= snake[i]->getPosX() + 130 || posX <= snake[i]->getPosX() - 130)
			//			&& (posY >= snake[i]->getPosY() + 130 || posY <= snake[i]->getPosY() - 130)) {
			//			notIntersect = true;
			//			std::cout << "time!!" << std::endl;
			//		}
			//	}

			//	if (notIntersect) {
			//		enemies.push_back(new Venom(venomTexture, posX, posY));
			//		spawnClk.restart();
			//	}
			//}
	//===============================

	//========== CHECK RANGE ==========
	for (int i = 0; i < snake.size(); i++) {
		if (snake[i]->getType() == 'i') {
		//if(typeid(snake[i]).name()== typeid(ironman).name()){
			for (int j = 0; j < enemies.size(); j++){
					float ironRange = pow(pow(snake[i]->getPosX() - enemies[j]->getPosX(),2.0)+pow(snake[i]->getPosY() - enemies[j]->getPosY(), 2.0), 0.5);
					std::cout << ironRange << std::endl;
				}
				
			}
		}
// ================================
				
		window.clear();
		window.setView(view);
		window.draw(map);
		//window.draw(glowa);

		for (auto itr : enemies)
			window.draw(*itr);

		for (auto itr : snake)
			window.draw(*itr);

		window.display();
	}

	return 0;
}