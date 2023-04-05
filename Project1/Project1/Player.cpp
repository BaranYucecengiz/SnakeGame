#include "Player.h"
#include <iostream>

Player::Player(	sf::Color snake_color,
				sf::Vector2f head_position,
				std::string user_name, 
				int snake_width, 
				int snake_height, 
				double snake_speed, 
				double snake_direction, 
				int counter)
	:snake_color{ snake_color },
	head_position{ head_position },
	user_name{ user_name },
	snake_width{ snake_width },
	snake_height{ snake_height },
	snake_speed{ snake_speed },
	snake_direction{ snake_direction },
	counter{counter}{
	std::cout << "Player Ctor" << std::endl;
}


Player::~Player() {
	std::cout << "Player Dector" << std::endl;
}

void Player::set_direction(const sf::Event &event) {
	if (event.type == sf::Event::KeyPressed) {

		if (event.key.code == sf::Keyboard::A && this->snake_direction != 1) {
			this->snake_direction = 0;
		}
		else if (event.key.code == sf::Keyboard::D && this->snake_direction != 0) {
			this->snake_direction = 1;;
		}
		else if (event.key.code == sf::Keyboard::W && this->snake_direction != 3) {
			this->snake_direction = 2;
		}
		else if (event.key.code == sf::Keyboard::S && this->snake_direction != 2) {
			this->snake_direction = 3;
		}
		
	}
	}

void Player::move(){
	if (this->snake_direction == 0) {
		this->head_position.x -= this->snake_speed;
	}
	else if (this->snake_direction == 1) {
		this->head_position.x += this->snake_speed;
	}
	else if (this->snake_direction == 2) {
		this->head_position.y -= this->snake_speed;
	}
	else if (this->snake_direction == 3) {
		this->head_position.y += this->snake_speed;
	}
	
}

void Player::dead(){
	this->snake.clear();
}

void Player::create_parts(sf::RectangleShape shape, const sf::Vector2f pos){
	shape.setFillColor(this->snake_color);
	shape.setPosition(pos);
	this->snake.push_back(shape);
	this->head_position = pos;
	this->counter++;
}

void Player::update_snake(){
	int snake_size =counter - 1;
	for (int i = 1; i <= snake_size; i++){
		this->snake.at(i - 1).setPosition(this->snake.at(i).getPosition());
	}
	this->snake.at(snake_size).setPosition(this->head_position);
	
}

