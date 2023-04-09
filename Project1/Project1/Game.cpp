#include "Game.h"

Game::Game(unsigned int BLOCK_HEIGHT, unsigned int BLOCK_WIDTH, int snake_size, std::string window_name)
	: BLOCK_HEIGHT{ BLOCK_HEIGHT }, BLOCK_WIDTH{ BLOCK_WIDTH }, snake_size{ snake_size }, window_name{ window_name } {
    std::cout << "Game Ctor" << std::endl;
}

Game::~Game(){
    std::cout << "Game Dector" << std::endl;
}



void Game::create_board(){
    for (int x = 0; x < this->BLOCK_HEIGHT/ this->snake_size; x++) {
        for (int y = 0; y < this->BLOCK_WIDTH / this->snake_size; y++) {
            sf::RectangleShape block(sf::Vector2f(this->snake_size, this->snake_size));
            block.setPosition(x * this->snake_size, y * this->snake_size);
            if ((x + y) % 2 == 0) {
                block.setFillColor(sf::Color(32, 32, 32));
            }
            else {
                block.setFillColor(sf::Color(48, 48, 48));
            }
            this->window.draw(block);
        }
    }
}

void Game::create_game(){
    this->window.create(sf::VideoMode(this->BLOCK_HEIGHT, this->BLOCK_WIDTH), window_name);
}
