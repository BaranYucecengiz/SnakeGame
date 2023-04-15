#include "Player.h"

Player::Player(sf::Color snake_color, unsigned int WINDOW_HEIGHT, unsigned int WINDOW_WIDTH, int block_size)
	:Game(WINDOW_HEIGHT, WINDOW_WIDTH, block_size), snake_color{ snake_color }, head_position{ head_position }{
	this->snake_speed = block_size;
	this->snake_direction = 4;
	this->counter = 0;
	create_parts(sf::RectangleShape{ sf::Vector2f{static_cast<float>(block_size), static_cast<float>(block_size)} },
		sf::Vector2f{ rand() % static_cast<int>(WINDOW_HEIGHT / block_size) * this->snake_speed ,
						rand() % static_cast<int>(WINDOW_WIDTH / block_size) * this->snake_speed });
	std::cout << "Player Ctor" << std::endl;
}

Player::~Player() {
	this->dead();
	std::cout << "Player Dector" << std::endl;
}
void Player::set_direction(const sf::Event& event, char left, char right, char forward, char back) {
	if (event.type == sf::Event::TextEntered) {
		if (static_cast<char>(event.text.unicode) == left && this->snake_direction != 1) {
			this->snake_direction = 0;
		}
		else if (static_cast<char>(event.text.unicode) == right && this->snake_direction != 0) {
			this->snake_direction = 1;;
		}
		else if (static_cast<char>(event.text.unicode) == forward && this->snake_direction != 3) {
			this->snake_direction = 2;
		}
		else if (static_cast<char>(event.text.unicode) == back && this->snake_direction != 2) {
			this->snake_direction = 3;
		}
	}
}

void Player::move() {
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

void Player::dead() {
	this->snake.clear();
}

void Player::create_parts(sf::RectangleShape&& shape, const sf::Vector2f& pos) {
	if (counter > 0)
		this->snake.at(counter - 1).setFillColor(this->snake_color);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(pos);
	this->snake.push_back(shape);
	this->head_position = pos;
	this->counter++;
}

void Player::update_snake() {
	int snake_size = counter - 1;
	for (int i = 1; i <= snake_size; i++) {
		this->snake.at(i - 1).setPosition(this->snake.at(i).getPosition());
	}
	this->snake.at(snake_size).setPosition(this->head_position);
}

bool Player::isHitWall() {
	if (this->head_position.y >= WINDOW_WIDTH || this->head_position.y < 0
		|| this->head_position.x >= WINDOW_HEIGHT || this->head_position.x < 0) {
		return true;
	}
	return false;
}

bool Player::isHitSnake(const std::vector<Player*> players) {
	for (int i = 0; i < counter - 1; i++) {
		for (auto& p : players) {
			if (this->snake.at(i).getPosition() == p->get_head_position()) {
				return true;
			}
		}

	}
	return false;
}
