#pragma once

// ****************
// *** Includes ***
// ****************
#include <SFML/Graphics.hpp>



class Critter
{
	//*************************
	//******* BEHAVIOUR *******
	//*************************

public:

	// Constructor
	Critter();

	//Render Critter to the target
	void Draw(sf::RenderTarget& _target);


	// *** END BEHAVIOUR ***

	//********************
	//******* DATA *******
	//********************






private:

	sf::Sprite m_sprite;
	sf::Texture m_texture;


}; // end critter class



