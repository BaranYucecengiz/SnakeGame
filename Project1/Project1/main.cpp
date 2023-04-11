#include "SFML/Graphics.hpp"
#include "Game.h"
#include "Player.h"
#include "Food.h"
#include <iostream>
#include <vector>
#include<windows.h> 
#include<time.h> 
// create variables for game
static unsigned int WINDOW_HEIGHT = 500;
static unsigned int WINDOW_WIDTH = 500;
static int block_size = 10;

int main(){
    srand(time(0));
    // create the game
    Game game(WINDOW_HEIGHT, WINDOW_WIDTH, block_size, "Snake");
    game.create_game();
    game.window.setFramerateLimit(20);
    // Create food
    Food food(sf::Color::Red, WINDOW_HEIGHT, WINDOW_WIDTH, block_size);
    // create Player
    Player *player = new Player(sf::Color::Magenta, WINDOW_HEIGHT, WINDOW_WIDTH, block_size);
    Player *player2 = new Player(sf::Color::Blue, WINDOW_HEIGHT, WINDOW_WIDTH, block_size);
    
    while (game.window.isOpen())
    {
        sf::Event event;
        while (game.window.pollEvent(event)){
            if (event.KeyPressed == sf::Event::KeyPressed) {
                // set the direction of the snake
                player->set_direction(event, 'a', 'd', 'w', 's');
                player2->set_direction(event, '4', '6', '8', '5');
            }
        }
        player->move();
        player2->move();
        // set head position of snake if food is eaten, else update snake
        if (player->get_head_position() == food.get_food().getPosition()) {
            player->create_parts(sf::RectangleShape{ sf::Vector2f{static_cast<float>(block_size), static_cast<float>(block_size)} }, food.get_food().getPosition());
            food.set_food_position();
        }
        else {
            player->update_snake();
        }
        if (player2->get_head_position() == food.get_food().getPosition()) {
            player2->create_parts(sf::RectangleShape{ sf::Vector2f{static_cast<float>(block_size), static_cast<float>(block_size)} }, food.get_food().getPosition());
            food.set_food_position();
        }
        else {
            player2->update_snake();
        }
        // Game Rules
        if (player->isHitSnake() || player->isHitWall() || player2->isHitSnake() || player2->isHitWall()) {
            delete player;
            delete player2;
            return 1;
        }
        // clear the window
        game.window.clear();
        // create background
        game.create_board();
        // draw snakes and food
        for (const auto& s : player->get_snake()){
            game.window.draw(s);
        }
        for (const auto& s : player2->get_snake()) {
            game.window.draw(s);
        }
        game.window.draw(food.get_food());
        // end the current frame
        game.window.display();
    }
    return 0;
}