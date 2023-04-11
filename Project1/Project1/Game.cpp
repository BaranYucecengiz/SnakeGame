#include "Game.h"

Game::Game(unsigned int WINDOW_HEIGHT, unsigned int WINDOW_WIDTH, int block_size, std::string window_name)
	: WINDOW_HEIGHT{ WINDOW_HEIGHT }, WINDOW_WIDTH{ WINDOW_WIDTH }, block_size{ block_size }, window_name{ window_name } {
    std::cout << "Game Ctor" << std::endl;
}

Game::~Game(){
    std::cout << "Game Dector" << std::endl;
}

void Game::create_board(){
    for (int x = 0; x < this->WINDOW_HEIGHT / this->block_size; x++) {
        for (int y = 0; y < this->WINDOW_WIDTH / this->block_size; y++) {
            sf::RectangleShape block(sf::Vector2f(this->block_size, this->block_size));
            block.setPosition(x * this->block_size, y * this->block_size);
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
    this->window.create(sf::VideoMode(this->WINDOW_HEIGHT, this->WINDOW_WIDTH), window_name);
}
