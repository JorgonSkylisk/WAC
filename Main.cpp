// ****************
// *** Includes ***
// ****************
// **** LIBRARIES ****
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cstdlib>
#include <ctime>
// Project Include
#include "Critter.h"

int main()
{
	//****************************
	//******** GAME SETUP ********
	//****************************
	// Declare variable for display window
	sf::RenderWindow gamewindow;
	gamewindow.create(sf::VideoMode::getDesktopMode(), "Button Masher",
	sf::Style::Titlebar | sf::Style::Close);
	

	// seed RNG
	srand(time(NULL));



	// TIMER
	sf::Time timeLimit = sf::seconds(10.0f);
	sf::Time timeRemaining = timeLimit;
	sf::Clock gameClock;

	//create instance of Critter Class

	Critter Gorilla;

	// *****************
	// *** END SETUP ***
	// *****************


	//*************************
	//******* game loop *******
	//*************************
	while (gamewindow.isOpen())

	{
		// *****************
		// ***** INPUT *****
		// *****************


		sf::Event event;
		while (gamewindow.pollEvent(event))
		{
			//process input on critters
			Gorilla.Input(event);


			if (event.type == sf::Event::Closed)
				gamewindow.close();
		} // End IF

		// *** End INPUT ***

	//************************
	//******** UPDATE ********
	//************************
		sf::Time frameTime = gameClock.restart();

	// *** END UPDATE ***
		
	// *****************
	// ****** DRAW *****
	// *****************

		gamewindow.clear();
		Gorilla.Draw(gamewindow);
		gamewindow.display();

	// *** END DRAW ***

	}// End WHILE
	
	 
	 
	// *****************
	// * END GAME LOOP *
	// *****************

	return 0;
}