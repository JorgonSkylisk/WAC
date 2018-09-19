
// ****************
// *** Includes ***
// ****************
// Project includes
#include "Critter.h"




Critter::Critter()
//initialisation list
	: m_sprite()
	, m_texture()
	, m_alive(true)
	, m_deathSound()
	, m_deathBuffer()
{
	// Setup Sprite
	m_texture.loadFromFile("graphics/gorilla.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(rand() % sf::VideoMode::getDesktopMode().width
		, rand() % sf::VideoMode::getDesktopMode().height);
	//Setting death sound
	m_deathBuffer.loadFromFile("audio/buttonclick.ogg");
	m_deathSound.setBuffer(m_deathBuffer);
}

void Critter::Draw(sf::RenderTarget& _target)
{
	//only draw if alive = true
	if (m_alive)
	{
		_target.draw(m_sprite);

	}
}

void Critter::Input(sf::Event _gameEvent)
{
	if (m_alive)
	{
		// Check if event is a click
		if (_gameEvent.type == sf::Event::MouseButtonPressed)
		{
			//Did click occur on critter?
			if (m_sprite.getGlobalBounds().contains(_gameEvent.mouseButton.x, _gameEvent.mouseButton.y))
			{
				//Click Confirmed
				m_alive = false;
				//play sound
				m_deathSound.play();
			}
		}
	}
}
