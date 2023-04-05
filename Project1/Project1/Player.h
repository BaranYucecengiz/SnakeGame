#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <vector>
class Player
{
private:
	static const constexpr char *def_name = "Unnamed";
	static const constexpr int def_snake_width = 5;
	static const constexpr int def_snake_height = 5;
	static const constexpr double def_snake_speed = 10;
	static const constexpr double def_snake_direction = 4;
	static const constexpr int def_counter = 0;
protected:
	std::string user_name;
	int snake_width;
	int snake_height;
	double snake_speed;
	double snake_direction;
	int counter;

	sf::Color snake_color;
	std::vector<sf::RectangleShape> snake;
	sf::Vector2f head_position;
public:
	//Ctors
	Player(	sf::Color snake_color,
			sf::Vector2f head_position,

		std::string user_name = def_name,
		int snake_width = def_snake_width,
		int snake_height = def_snake_height,
		double snake_speed = def_snake_speed,
		double snake_direction = def_snake_direction,
		int counter = def_counter);
	~Player();

	//Methods
	void set_direction(const sf::Event &event);
	void move();
	void create_parts(sf::RectangleShape shape,const sf::Vector2f pos);
	void update_snake();
	void dead();
	
	//Getters - Setter
	std::vector<sf::RectangleShape> get_snake() {
		return this->snake;
	}
	sf::Color get_snake_color() {
		return snake_color;
	}
	sf::Vector2f get_head_position() {
		return this->head_position;
	}
};

