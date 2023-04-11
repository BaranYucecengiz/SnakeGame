#pragma once
#include "SFML/Graphics.hpp"
#include "Game.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
class Food: public Game{
private:
protected:
	sf::RectangleShape food;
	sf::Color food_color;
public:
	// Ctors - DeCtor
	Food(sf::Color food_color,unsigned int WINDOW_HEIGHT, unsigned int WINDOW_WIDTH, int block_size);
	~Food();
	//Methods
	void set_food_position();
	// Getters - Setters
	sf::RectangleShape get_food() const{
		return this->food;
	}
	
};

