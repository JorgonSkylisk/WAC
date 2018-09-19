#pragma once

// ****************
// *** Includes ***
// ****************
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>



class Critter
{
	// *************************
	// ******* BEHAVIOUR *******
	// *************************

public:

	// Constructor
	Critter();

	//Render Critter to the target
	void Draw(sf::RenderTarget& _target);

	// Process input on critter
	void Input(sf::Event _gameEvent);

	// Getter for pending score
	int GetPendingScore();

	// Clear pending score
	void ClearPendingScore();

	//set critter type
	void Setup(std::string _textureFile, int _pointValue);


	// *** END BEHAVIOUR ***

	// ********************
	// ******* DATA *******
	// ********************






private:

	sf::Sprite m_sprite;
	sf::Texture m_texture;
	bool m_alive;
	sf::Sound m_deathSound;
	sf::SoundBuffer m_deathBuffer;
	int m_pendingScore;
	int m_scoreValue;

}; // end critter class



