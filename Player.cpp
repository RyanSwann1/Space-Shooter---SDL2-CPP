#include "Player.h"
#include "TextureManager.h"
#include "InputManager.h"
#include "Game.h"
#include "LaserHandler.h"
#include "AsteroidManagement.h"
#include "EnemyManager.h"
#include "Laser.h"
#include "CollisionHandler.h"
#include "Timer.h"
#include <iostream>

const std::string Player::m_ID = "Player";

Player::Player()
{
	m_sizeHeight = 60;
	m_sizeWidth = 60;
	m_startXPos = Game::instance()->getPlayingFieldWidth() / 2 - (m_sizeWidth / 2);
	m_startYPos = 550;
	m_movementSpeed = 6;
	m_laserMovementSpeed = 4;
	
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_position.setX(m_startXPos);
	m_position.setY(m_startYPos);
	m_nextFire = 0;
	m_fireLaser = true;
}

Player::~Player()
{
}

void Player::draw()
{
	TextureManager::instance()->draw(m_position.getX(), m_position.getY(), m_sizeWidth, m_sizeHeight, m_ID);
}

void Player::update()
{	
	fireLaser();

	handleInput();

	m_velocity = handleMovement();
	
	m_position += m_velocity;
	handleCollisions();

	//std::cout << "Enemy Size: " << EnemyManager::instance()->getEnemies().size() << "\n";
	//std::cout << "Asteroid Size: " << AsteroidManagement::instance()->getAsteroids().size() << "\n";
	//std::cout << "PLayer Laser Size: " << LaserHandler::instance()->getPlayerLasers().size() << "\n";
	//std::cout << "Enemy Laser Size: " << LaserHandler::instance()->getEnemyLasers().size() << "\n\n\n";
}


Vector2D Player::handleMovement()
{
	Vector2D newVelocity;
	newVelocity.setX(0);
	newVelocity.setY(0);

	//Move up
	if (InputManager::instance()->isKeyDown(SDL_SCANCODE_W) && m_position.getY() >= 0) {
		newVelocity.setY(-m_movementSpeed);
	}
	//Move right
	else if (InputManager::instance()->isKeyDown(SDL_SCANCODE_D) && !CollisionHandler::gameBoundsWidth(this)) {
		newVelocity.setX(m_movementSpeed);
	}
	//Move down
	else if (InputManager::instance()->isKeyDown(SDL_SCANCODE_S) && !CollisionHandler::gameBoundsHeight(this)) {
		newVelocity.setY(m_movementSpeed);
	}
	//Move left
	else if (InputManager::instance()->isKeyDown(SDL_SCANCODE_A) && m_position.getX() >= 0) {
		newVelocity.setX(-m_movementSpeed);
	}

	return newVelocity;
}

void Player::handleInput()
{
	if (m_fireLaser)
	{
		if (InputManager::instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
			LaserHandler::instance()->addLaser((*this), "PlayerLaser");
			m_fireLaser = false;
		}	
	}
}

//Determine whether player can fire laser
void Player::fireLaser()
{
	if (Timer::instance()->compareToTimePassed(m_nextFire))
	{
		m_nextFire += m_timeBetweenFire;
		m_fireLaser = true; //Firelaser
	}
}

void Player::reset()
{
	m_position.setX(m_startXPos);
	m_position.setY(m_startYPos);
}

void Player::handleCollisions()
{
	gameObjectCollision(AsteroidManagement::instance()->getAsteroids());
	gameObjectCollision(EnemyManager::instance()->getEnemies());
	gameObjectCollision(LaserHandler::instance()->getEnemyLasers());
	
}

void Player::gameObjectCollision(std::vector<std::unique_ptr<SDLGameObject>>& gameObjects)
{
	std::vector<std::unique_ptr<SDLGameObject>>::const_iterator iter;

	for (iter = gameObjects.cbegin(); iter != gameObjects.cend();)
	{
		if (CollisionHandler::gameObjectCollision(this, iter->get()))
		{
			iter = gameObjects.erase(iter);
			reset(); //Reset player
		}
		else {
			iter++;
		}
	}
//Javawag: means one of the following :
//Javawag: *the gameObject passed thru is nullptr
//	Javawag : or , *the Player itself here is nullptr
//	Javawag : or , *Game::instance() returns a nullptr
//	Javawag : all seem unlikely : D
//	Javawag : OH!
//	Javawag : or the gameObject you passed ISNT nullptr, but is something you deleted but left in a vector

}

