#pragma once
#include "SFML/Graphics.hpp"
#include "Game.h"
#include <string>
#include <vector>
#include <iostream>
#include<windows.h>
class Player : public Game
{
private:
	static const constexpr char* def_name = "Unnamed";
protected:
	std::string user_name;
	float snake_speed;
	double snake_direction;
	int counter;

	sf::Color snake_color;
	std::vector<sf::RectangleShape> snake;
	sf::Vector2f head_position;
public:
	//Ctors
	Player(sf::Color snake_color, unsigned int WINDOW_HEIGHT, unsigned int WINDOW_WIDTH, int block_size);
	~Player();

	//Methods
	void set_direction(const sf::Event& event, char left, char right, char forward, char back);
	void move();
	void create_parts(sf::RectangleShape&& shape, const sf::Vector2f& pos);
	void update_snake();
	void dead();
	bool isHitWall();
	bool isHitSnake(const std::vector<Player*> players);
	//Getters - Setter
	std::vector<sf::RectangleShape> get_snake() const {
		return this->snake;
	}
	sf::Color get_snake_color() const {
		return snake_color;
	}
	sf::Vector2f get_head_position() const {
		return this->head_position;
	}
	void set_snake_speed(int snake_speed) {
		this->snake_speed = snake_speed;
	}
};

