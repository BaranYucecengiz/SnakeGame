#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <vector>

class Game {
private:
	static const constexpr char* def_window_name = "Unnamed Window";
	static const constexpr unsigned int def_WINDOW_HEIGHT = 500;
	static const constexpr unsigned int def_WINDOW_WIDTH = 500;
	static const constexpr int def_block_size = 10;
protected:
	unsigned int WINDOW_HEIGHT;
	unsigned int WINDOW_WIDTH;
	int block_size;
	std::string window_name;

public:
	// variables
	sf::RenderWindow window; // I can' t declare as a protected member because I want to get window object inside the main. Assignment or copy or move operator deleted

	// Ctor - DeCtor
	Game(unsigned int WINDOW_HEIGHT = def_WINDOW_HEIGHT,
		unsigned int WINDOW_WIDTH = def_WINDOW_WIDTH,
		int block_size = def_block_size,
		std::string window_name = def_window_name);
	virtual ~Game();
	// Methods

	void create_board();
	void create_game();


	//Getters - Setters


};

