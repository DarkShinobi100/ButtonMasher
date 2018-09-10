//included loibraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

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

	//create Music
	sf::Music gameMusic;
	gameMusic.openFromFile("audio/LacrimosaofDanaOpeningVer.ogg");
	gameMusic.play();//play music

	//Create font
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainfont.ttf");


	//create Title
	sf::Text titleText;
	titleText.setFont(gameFont);
	titleText.setString("Don't sue me Falcom");
	titleText.setCharacterSize(100);
	titleText.setFillColor(sf::Color::Black);
	titleText.setStyle(sf::Text::Bold | sf::Text::Italic);
	titleText.setPosition(gameWindow.getSize().x / 2
		- titleText.getLocalBounds().width / 2, 30);
	

	//setup Author Text
	sf::Text authorText;
	authorText.setFont(gameFont);
	authorText.setString("By: Edwyn");
	authorText.setCharacterSize(80);
	authorText.setFillColor(sf::Color::Black);

	authorText.setPosition(gameWindow.getSize().x / 2
		- titleText.getLocalBounds().width / 2, 105);


	//score 
	int score = 0; //set score to 0
	
    //setup score Text
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(50);
	scoreText.setFillColor(sf::Color::Black);

	scoreText.setPosition((gameWindow.getSize().x / 2)-85, 800);


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
		gameWindow.draw(titleText);
		gameWindow.draw(authorText);
		gameWindow.draw(scoreText);

		//Display the window contents on the screen
		gameWindow.display();


	}


	//exit point for the game
	return 0;
}