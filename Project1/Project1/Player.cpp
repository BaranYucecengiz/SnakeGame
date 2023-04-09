#include "Player.h"

Player::Player(	sf::Color snake_color,
				sf::Vector2f head_position,
				std::string user_name, 
				float snake_speed,
				double snake_direction, 
				int counter)
	:snake_color{ snake_color },
	head_position{ head_position },
	user_name{ user_name },
	snake_speed{ snake_speed },
	snake_direction{ snake_direction },
	counter{counter}{
	std::cout << "Player Ctor" << std::endl;
	srand(time(0));
	create_parts(	sf::RectangleShape{ sf::Vector2f{this->snake_speed, this->snake_speed}},
					sf::Vector2f{	rand() % (BLOCK_HEIGHT / static_cast<int>(this->snake_speed)) * this->snake_speed ,
									rand() % (BLOCK_WIDTH/ static_cast<int>(this->snake_speed)) * this->snake_speed });
}

Player::~Player() {
	this->dead();
	std::cout << "Player Dector" << std::endl;
}

void Player::set_direction(const sf::Event &event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::A && this->snake_direction != 1) {
			this->snake_direction = 0;
		}
		else if (event.key.code == sf::Keyboard::D && this->snake_direction != 0) {
			this->snake_direction = 1;;
		}
		else if (event.key.code == sf::Keyboard::W && this->snake_direction != 3) {
			this->snake_direction = 2;
		}
		else if (event.key.code == sf::Keyboard::S && this->snake_direction != 2) {
			this->snake_direction = 3;
		}
	}
}

void Player::move(){
	if (this->snake_direction == 0) {
		this->head_position.x -= this->snake_speed;
	}
	else if (this->snake_direction == 1) {
		this->head_position.x += this->snake_speed;
	}
	else if (this->snake_direction == 2) {
		this->head_position.y -= this->snake_speed;
	}
	else if (this->snake_direction == 3) {
		this->head_position.y += this->snake_speed;
	}
}

void Player::dead(){
	this->snake.clear();
}

void Player::create_parts(sf::RectangleShape &&shape, const sf::Vector2f &pos){
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(pos);
	this->snake.push_back(shape);
	this->head_position = pos;
	this->counter++;
	for (int i = 0; i < counter - 1; i++) {
		this->snake.at(i).setFillColor(this->snake_color);
	}

}

void Player::update_snake(){
	int snake_size =counter - 1;
	for (int i = 1; i <= snake_size; i++){
		this->snake.at(i - 1).setPosition(this->snake.at(i).getPosition());
	}
	this->snake.at(snake_size).setPosition(this->head_position);
}

bool Player::rules(sf::Vector2f snake_head_position, const std::vector<sf::RectangleShape>& snake) {
	if (snake_head_position.x > this->BLOCK_WIDTH || snake_head_position.x < 0
		|| snake_head_position.y > this->BLOCK_HEIGHT || snake_head_position.y < 0) {

		std::cout << "Nere lan pust!" << std::endl;
		return true;
	}

	for (int i = 0; i < snake.size() - 1; i++) {
		if (snake[i].getPosition() == snake_head_position) {
			std::cout << "Kendine carpti mal" << std::endl;
			return true;
		}
	}
	return false;
}

bool Player::isHitWall(){
	if (this->head_position.x > this->BLOCK_WIDTH || this->head_position.x < 0
		|| this->head_position.y > this->BLOCK_HEIGHT || this->head_position.y < 0) {
		std::cout << "Nere lan pust!" << std::endl;
		return true;
	}
	return false;
}

bool Player::isHitSnake(){
	for (int i = 0; i < counter - 1; i++) {
		if (this->snake.at(i).getPosition() == this->head_position) {
			std::cout << "Kendine carpti mal" << std::endl;
			return true;
		}
	}
	return false;
}
