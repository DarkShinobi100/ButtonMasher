//included loibraries
#include <SFML/Graphics.hpp>



//entry point for the game
int main()
{
	//variables
	sf::RenderWindow gameWindow; //Makes a variable called gameWindow of the type renderwindow
	gameWindow.create(sf::VideoMode::getDesktopMode(),"Button Masher",
		sf::Style::Titlebar | sf::Style::Close);


	//game loop
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



	}


	//exit point for the game
	return 0;
}