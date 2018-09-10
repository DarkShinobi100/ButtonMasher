//included loibraries
#include <SFML/Graphics.hpp>



//entry point for the game
int main()
{
	//variables
	sf::RenderWindow gameWindow; //Makes a variable called gameWindow of the type renderwindow
	gameWindow.create(sf::VideoMode::getDesktopMode(),"Button Masher",
		sf::Style::Titlebar | sf::Style::Close);

	//----------------------------------------------
	//game setup
	//----------------------------------------------
	
	//create button sprite
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");

	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);


	//center sprite in the middle of the screen, you have to realign it as the anchor point is the top left
	buttonSprite.setPosition(gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2);


	//----------------------------------------------
	//game loop
	//----------------------------------------------
	//Runs every frame untile the game is closed
	while (gameWindow.isOpen()) // while continues to loop while the (condition) is true
	{
		//Check for input
		sf::Event gameEvent;

		while (gameWindow.pollEvent(gameEvent))
		{
			//Process events

			//check if event is closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				//close the window
				gameWindow.close();
			}
		}

		//TODO: update game state


		//TODO:Draw Graphics

		//clear the window to a single colour
		gameWindow.clear(sf::Color::Cyan);

		// Draw everything
		gameWindow.draw(buttonSprite);

		//Display the window contents on the screen
		gameWindow.display();


	}


	//exit point for the game
	return 0;
}