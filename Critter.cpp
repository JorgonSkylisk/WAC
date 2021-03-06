
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
	, m_pendingScore(0)
	, m_scoreValue(1)
{
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
				// Add to pending score
				m_pendingScore += m_scoreValue;
			}
		}
	}
}


int Critter::GetPendingScore()
{
	return m_pendingScore;
}

void Critter::ClearPendingScore()
{
	m_pendingScore = 0;
}

void Critter::Setup(std::string _textureFile, int _pointValue)
{
	// Setup Sprite
	m_texture.loadFromFile(_textureFile);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(rand() % sf::VideoMode::getDesktopMode().width
		, rand() % sf::VideoMode::getDesktopMode().height);

	m_scoreValue = _pointValue;
}

