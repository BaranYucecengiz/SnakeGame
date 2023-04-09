#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>

class Game{
private:
	static const constexpr char *def_window_name = "SA";
	static const constexpr unsigned int def_BLOCK_HEIGHT = 500;
	static const constexpr unsigned int def_BLOCK_WIDTH= 500;
	static const constexpr int def_snake_size = 10;
protected:
	unsigned int BLOCK_HEIGHT;
	unsigned int BLOCK_WIDTH;
	int snake_size;
	std::string window_name;
	
public:
	// variables
	sf::RenderWindow window; // I can' t declare as a protected member because I want to get window object inside the main. Assignment or copy or move operator deleted

	// Ctor - DeCtor
	Game(	unsigned int BLOCK_HEIGHT = def_BLOCK_HEIGHT, 
			unsigned int BLOCK_WIDTH = def_BLOCK_WIDTH,
			int snake_size = def_snake_size,
			std::string window_name = def_window_name);
	virtual ~Game();
	// Methods
	
	void create_board();
	void create_game();
	

	//Getters - Setters
	

};

