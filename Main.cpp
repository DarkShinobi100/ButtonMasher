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
	gameMusic.setLoop(true);

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

	//setup prompt Text
	sf::Text promptText;
	promptText.setFont(gameFont);
	promptText.setString("click the button start the game");
	promptText.setCharacterSize(60);
	promptText.setFillColor(sf::Color::White);

	promptText.setPosition(gameWindow.getSize().x / 2
		- titleText.getLocalBounds().width / 2, 165);



	//score 
	int score = 0; //set score to 0
	
    //setup score Text
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(50);
	scoreText.setFillColor(sf::Color::Black);

	scoreText.setPosition((gameWindow.getSize().x / 2)-85, 800);

	sf::Text timeText;
	timeText.setFont(gameFont);
	timeText.setString("Time remaining: " + std::to_string(score));
	timeText.setCharacterSize(50);
	timeText.setFillColor(sf::Color::Black);

	timeText.setPosition((gameWindow.getSize().x / 2) - timeText.getLocalBounds().width /2, 850);

	//Timer functionality
	sf::Time timeLimit = sf::seconds(10.0f);
	sf::Time timeRemaining = timeLimit;
	sf::Clock gameClock; //game clock


	//cooldown funciton
	sf::Time cooldownLimit = sf::seconds(2.0f); //cooldown time limit
	sf::Time cooldownRemaining = sf::seconds(0.0f); // cooldowon time remaning


	//Click sound effect
	sf::SoundBuffer clickBuffer;
	clickBuffer.loadFromFile("audio/buttonclick.ogg");
	sf::Sound clickSound;
	clickSound.setBuffer(clickBuffer);

	//gameover effect
	sf::SoundBuffer gameOverBuffer;
	gameOverBuffer.loadFromFile("audio/gameover.ogg");
	sf::Sound gameOverSound;
	gameOverSound.setBuffer(gameOverBuffer);

	//Game state
	bool playing = false;


	//----------------------------------------------
	//Game loop
	//----------------------------------------------
	//Runs every frame untile the game is closed
	while (gameWindow.isOpen()) // while continues to loop while the (condition) is true
	{
		//Check for input
		sf::Event gameEvent;

		while (gameWindow.pollEvent(gameEvent))
		{
			//Process events

			//check if event is a mouse button pressed
			if (gameEvent.type == sf::Event::MouseButtonPressed)
			{
				if (buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x,gameEvent.mouseButton.y))
				{
					//button clicked when playing, inrease score
					if (playing == true)
					{
						score = score + 1;
					}
					else if(cooldownRemaining.asSeconds() <= 0.0f) // when cooldown is over
					{
						//no, start playing
						playing = true;

						//reset game data
						score = 0;
						timeRemaining = timeLimit;
						

						promptText.setString("click the button as fast as you can!");
					}
					
					//play the click sound
					clickSound.play();
					
				}
			}


			//check if event is closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				//close the window
				gameWindow.close();
			}

		}

		//update game state
		
		//update time
		sf::Time frameTime = gameClock.restart();

		if (playing == true)
		{
			timeRemaining = timeRemaining - frameTime;

			if (timeRemaining.asSeconds() <= 0.0f)
			{
				gameOverSound.play();
				timeRemaining = sf::seconds(0.0f);
				playing = false;
				promptText.setString("your final score was: " + std::to_string(score) + "!\n Click the button to start a new game");
				cooldownRemaining = cooldownLimit; //set cooldown limit

			}
			
		}
		else  
		{
			cooldownRemaining = cooldownRemaining - frameTime; //decrease coldown tmer
		}

		//update text display
		timeText.setString("Time remaining: " + std::to_string((int)std::ceilf( timeRemaining.asSeconds())));
		scoreText.setString("Score: " + std::to_string(score));


		//Draw Graphics

		//clear the window to a single colour
		gameWindow.clear(sf::Color::Cyan);

		// Draw everything
		gameWindow.draw(buttonSprite);
		gameWindow.draw(titleText);
		gameWindow.draw(authorText);
		gameWindow.draw(scoreText);
		gameWindow.draw(timeText);
		gameWindow.draw(promptText);

		//Display the window contents on the screen
		gameWindow.display();


	}


	//exit point for the game
	return 0;
}