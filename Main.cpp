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
	// ****************************
	// ******** GAME SETUP ********
	// ****************************
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

	// create font
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");

	//create score tracker
	int Score = 0;
	sf::Text ScoreText;
	ScoreText.setFont(gameFont);
	ScoreText.setString("Score: " + std::to_string(Score));
	ScoreText.setCharacterSize(16);
	ScoreText.setFillColor(sf::Color::White);
	ScoreText.setPosition(300, 300);



	// *****************
	// *** END SETUP ***
	// *****************


	// *************************
	// ******* game loop *******
	// *************************
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

	// ************************
	// ******** UPDATE ********
	// ************************
		sf::Time frameTime = gameClock.restart();

		Score += Gorilla.GetPendingScore();
		Gorilla.ClearPendingScore();
		ScoreText.setString("Score: " + std::to_string(Score));


	// *** END UPDATE ***
		
	// *****************
	// ****** DRAW *****
	// *****************

		// clear the screen
		gamewindow.clear();


		// draw everything
		Gorilla.Draw(gamewindow);
		gamewindow.draw(ScoreText);



		// display to screen
		gamewindow.display();

	// *** END DRAW ***

	}// End WHILE
	
	 
	 
	// *****************
	// * END GAME LOOP *
	// *****************

	return 0;
}