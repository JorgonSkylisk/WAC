
// ****************
// *** Includes ***
// ****************
// Project includes
#include "Critter.h"




Critter::Critter()
//initialisation list
	: m_sprite()
	, m_texture()
{
	// Setup Sprite
	m_texture.loadFromFile("graphics/gorilla.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(300, 300);
	// seed RNG
	srand(time(NULL));


}

void Critter::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprite);
}

