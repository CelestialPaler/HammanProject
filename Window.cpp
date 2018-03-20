/***************************************************************************************************/
/*                                                        Hamman re-edition                                                          */
/*                                                           Windoiw Class	                                                               */
/*                                                            天师苍邪科技                                                                */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#include "Window.h"
/***************************************************************************************************/
// Class : Window
/// Main rendering logic 
/// Store all the entities and other stuff , i.e. sound effect, text, etc.

// Constructor
Window::Window()
{
	// Create a new window 
	sf::RenderWindow window(sf::VideoMode(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT), title);
	// Set framerate limit
	window.setFramerateLimit(60);
	// Get the handle of the window and set it top-most
	HWND hwnd = window.getSystemHandle();
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, 
		WS_EX_TOOLWINDOW | SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);

	// Set window to transparent
	if (!Debug_Mode)
	{
		MARGINS margins;
		margins.cxLeftWidth = -1;
		SetWindowLong(hwnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
		DwmExtendFrameIntoClientArea(hwnd, &margins);
	}

	// Initializing all the entities
	EntityInit();

	// Main loop of the windows 
	while (window.isOpen())
	{
		// Handle all the events
		HandleEvent(window);
		// Update all the entities
		Update();
		// Clear the window
		Clear(window);
		// Render all the sprites and texts on the window
		Draw(window);
		Display(window);
	}
}

// Initializing all the entities and other stuff
FuncStat Window::EntityInit(void)
{
	// Character Loading
	/// Hamman G
	static Character hammanG(HAMMAN_G_FULL, sf::Vector2f(0.5, 0.5));
	hammanG.SetPostion(sf::Vector2f(MAIN_WINDOW_WIDTH / 2, MAIN_WINDOW_HEIGHT / 2));
	characterList.insert(pair<string, Character *>("HammanG", &hammanG));
	/// Hamman D
	static Character hammanD(HAMMAN_D_FULL, sf::Vector2f(0.5, 0.5));
	hammanD.SetPostion(sf::Vector2f(MAIN_WINDOW_WIDTH / 2, MAIN_WINDOW_HEIGHT / 2));
	characterList.insert(pair<string, Character *>("HammanD", &hammanD));

	// Entity Loading
	/// DialogueWindow
	static Entity dialogueWindow(DIALOGUE_BOX_FULL, sf::Vector2f(0.33, 0.25));
	dialogueWindow.SetPostion(sf::Vector2f(MAIN_WINDOW_WIDTH / 2, MAIN_WINDOW_HEIGHT / 2 + 100));
	dialogueWindow.GetSprite().setColor(sf::Color(255, 255, 255, 255 * 0.8));
	entityList.insert(pair<string, Entity *>("Dialogue", &dialogueWindow));

	// Button Loading
	/// Visual Studio
	static Button visualStudioLink(ICON_VISUAL_STUDIO, sf::Vector2f(0.2, 0.2));
	visualStudioLink.SetPostion(sf::Vector2f(MAIN_WINDOW_WIDTH / 6, MAIN_WINDOW_HEIGHT / 6));
	buttonList.insert(pair<string, Button *>("VisualStudioLink", &visualStudioLink));

	// Text Loading
	/// Dialogue No.1
	static Text dialogueText(FONT_CH_FANG, "Hentai!", 30);
	dialogueText.GetText().setString(L"            变态!\n为什么一直盯着哈曼看!");
	dialogueText.SetColor(sf::Color(50, 50, 50));
	dialogueText.SetPosition(sf::Vector2f(MAIN_WINDOW_WIDTH / 2 - 100, MAIN_WINDOW_HEIGHT / 2 + 70));
	textList.insert(pair<string, Text *>("MainDialogue", &dialogueText));

	return OK;
}


// To handle all the events
FuncStat Window::HandleEvent(sf::RenderWindow &_window)
{
	// Used for grabbing and repostioning a transparent window
	static sf::Vector2i grabOffset;
	static bool grabFlag = false;

	sf::Event event;
	while (_window.pollEvent(event))
	{
		// Window close event
		if (event.type == sf::Event::Closed)
			_window.close();

		// Grabbing and repostioning a transparent window
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					grabOffset = _window.getPosition() - sf::Mouse::getPosition();
					grabFlag = true;
				}
			}
			else if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
					grabFlag = false;
			}
			else if (event.type == sf::Event::MouseMoved)
			{
				if (grabFlag)
					_window.setPosition(sf::Mouse::getPosition() + grabOffset);
			}
		}

		// Handle the character change
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					if (mainCharacter == "HammanG")
					{
						mainCharacter = "HammanD";
					}
					else 
					{
						mainCharacter = "HammanG";
					}			
				}
			}
		}

		// Handle the menu
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
			{
				buttonFlag = !buttonFlag;
			}
		}
	}
	return OK;
}
// Updating all the entities
/// Implementing anmimations, etc.
FuncStat Window::Update(void)
{
	characterList[mainCharacter]->FloatAnimation(2);
	buttonList["VisualStudioLink"]->FloatAnimation();
	return OK;
}

// Clear the window
FuncStat Window::Clear(sf::RenderWindow &_window)
{
	_window.clear(sf::Color::Transparent);
	return OK;
}

// Render all the stuf on the screen
FuncStat Window::Draw(sf::RenderWindow &_window)
{
	_window.draw(characterList[mainCharacter]->GetSprite());
	if (dialogueFlag)
	{
		_window.draw(entityList["Dialogue"]->GetSprite());
		_window.draw(textList["MainDialogue"]->GetText());
	}
	if (buttonFlag)
	{
		_window.draw(buttonList["VisualStudioLink"]->GetSprite());
	}
	return OK;
}

	// Rereash the screen with the buff we updated and drawn
FuncStat Window::Display(sf::RenderWindow & _window)
{
	_window.display();
	return OK;
}
