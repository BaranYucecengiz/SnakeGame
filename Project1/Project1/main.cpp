#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include<windows.h> 
#include<time.h> 
int main(){

    // create the window
    sf::RenderWindow window(sf::VideoMode(500, 500), "My window");
    sf::RectangleShape food(sf::RectangleShape{ sf::Vector2f{10, 10} });
    food.setFillColor(sf::Color::Magenta);
    food.setPosition(sf::Vector2f{60, 70});
    // create Player
    Player player(sf::Color::Magenta, sf::Vector2f(10, 10));
    player.create_parts(sf::RectangleShape{ sf::Vector2f{10, 10} }, sf::Vector2f{100, 100});
    bool flag = true;

 
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        
        while (window.pollEvent(event)){
            if (event.KeyPressed == sf::Event::KeyPressed) {
                // set the direction the snake
                player.set_direction(event);
            }
        }
        // set head position of snake and uptade all snake
        
        
        player.move();
        if (player.get_head_position() == food.getPosition()) {
            srand(time(0));
            player.create_parts(sf::RectangleShape{ sf::Vector2f{10, 10} }, food.getPosition());
            food.setPosition(sf::Vector2f( rand() % 40 * 10, rand() % 40 * 10 ));
        }
        player.update_snake();

        // clear the window with white color
        window.clear(sf::Color::White);
        // draw everything here...

        for (int x = 0; x < 50; x++) {
            for (int y = 0; y < 50; y++) {
                sf::RectangleShape block(sf::Vector2f(10, 10));
                block.setPosition(x * 10, y * 10);
                if ((x + y) % 2 == 0) {
                    block.setFillColor(sf::Color(32, 32, 32));
                }
                else {
                    block.setFillColor(sf::Color(48, 48, 48));
                }
                window.draw(block);
            }
        }

        for (auto& s : player.get_snake()){
            window.draw(s);
        }
        window.draw(food);

        // end the current frame
        window.display();
        Sleep(50);
            
    }

    return 0;
}