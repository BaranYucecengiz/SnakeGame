#include "Food.h"
Food::Food(sf::Color food_color, unsigned int WINDOW_HEIGHT, unsigned int WINDOW_WIDTH, int block_size)
	: Game(WINDOW_HEIGHT, WINDOW_WIDTH, block_size), food_color{ food_color } {
	this->food = sf::RectangleShape(sf::Vector2f{ static_cast<float>(block_size), static_cast<float>(block_size) });
	this->food.setPosition(rand() % (WINDOW_HEIGHT / block_size)* block_size, rand() % (WINDOW_WIDTH / block_size)* block_size);
	this->food.setFillColor(this->food_color);
	std::cout << "Food Ctor" << std::endl;
}

Food::~Food() {
	std::cout << "Food DeCtor" << std::endl;
}

void Food::set_food_position() {
	this->food.setPosition(rand() % (WINDOW_HEIGHT / block_size) * block_size, rand() % (WINDOW_WIDTH / block_size) * block_size);
}
