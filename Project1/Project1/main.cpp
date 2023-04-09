#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Game.h"
#include<windows.h> 
#include<time.h> 
int main(){

    // create the game
    Game game(500, 500, 10, "Snake");
    game.create_game();
    sf::RectangleShape food(sf::RectangleShape{ sf::Vector2f{10, 10}});
    game.window.setFramerateLimit(25);
    
    food.setFillColor(sf::Color::Red);
    food.setPosition(sf::Vector2f{60, 70});
    // create Player
    Player *player = new Player(sf::Color::Magenta, sf::Vector2f(10, 10));
    bool flag = true;

 
    // run the program as long as the window is open
    while (game.window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        
        while (game.window.pollEvent(event)){
            if (event.KeyPressed == sf::Event::KeyPressed) {
                // set the direction the snake
                player->set_direction(event);
                
            }
        }
       
        player->move();
        
        if (player->get_head_position() == food.getPosition()) {
            srand(time(0));
            player->create_parts(sf::RectangleShape{ sf::Vector2f{10, 10} }, food.getPosition());
            food.setPosition(sf::Vector2f(rand() % 20 * 10, rand() % 20 * 10));

        }
        else {
            player->update_snake();
        }
        /*if (player->get_head_position() == food.getPosition()) {
            srand(time(0));
            food.setPosition(sf::Vector2f(rand() % 20 * 10, rand() % 20 * 10));
            player->create_parts(sf::RectangleShape{ sf::Vector2f{10, 10} }, food.getPosition());

        } - > Teleport */ 

        // set head position of snake and uptade all snake
        
        player->isHitSnake();
        player->isHitWall();
            
        // clear the window
        game.window.clear();
        // draw everything here...

        game.create_board();

        for (auto& s : player->get_snake()){
            game.window.draw(s);
        }
        game.window.draw(food);

        // end the current frame
        game.window.display();
            
    }

    return 0;
}