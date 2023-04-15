#include "SFML/Graphics.hpp"
#include "Game.h"
#include "Player.h"
#include "Food.h"
#include <iostream>
#include <vector>
#include<windows.h> 
#include<time.h> 
// create variables for game
static unsigned int WINDOW_HEIGHT = 1200;
static unsigned int WINDOW_WIDTH = 800;
static int block_size = 40;

int main() {
    std::vector<Player*> players;
    srand(time(0));
    // create the game
    Game game(WINDOW_HEIGHT, WINDOW_WIDTH, block_size, "Snake");
    game.create_game();
    game.window.setFramerateLimit(10);
    // Create food
    Food food(sf::Color::Red, WINDOW_HEIGHT, WINDOW_WIDTH, block_size);

    // create Players
    players.push_back(new Player(sf::Color::Magenta, WINDOW_HEIGHT, WINDOW_WIDTH, block_size));
    players.push_back(new Player(sf::Color::Blue, WINDOW_HEIGHT, WINDOW_WIDTH, block_size));
    while (game.window.isOpen())
    {
        sf::Event event;
        while (game.window.pollEvent(event)) {
            if (event.KeyPressed == sf::Event::KeyPressed) {
                // set the direction of the snake
                players.at(0)->set_direction(event, 'a', 'd', 'w', 's');
                players.at(1)->set_direction(event, '4', '6', '8', '5');
            }
        }
        // set snake's head pos
        for (auto p : players) {
            p->move();
        }
        // create snake parts if food is eaten, else update snake
        for (auto p : players) {
            if (p->get_head_position() == food.get_food().getPosition()) {
                p->create_parts(sf::RectangleShape{ sf::Vector2f{static_cast<float>(block_size), static_cast<float>(block_size)} }, food.get_food().getPosition());
                food.set_food_position();
            }
            else {
                p->update_snake();
            }
        }
        // Game Rules
        for (auto p : players) {
            if (p->isHitSnake(players) || p->isHitWall()) {
                delete players.at(0);
                delete players.at(1);
                return 1;
            }
        }
        // clear the window
        game.window.clear();
        // create background
        game.create_board();
        // draw snakes
        for (auto p : players) {
            for (const auto& s : p->get_snake()) {
                game.window.draw(s);
            }
        }
        // draw food
        game.window.draw(food.get_food());
        // end the current frame
        game.window.display();
    }
    return 0;
}