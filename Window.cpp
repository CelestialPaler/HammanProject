/***************************************************************************************************/
/*                                                      Hamman re-edition                                                            */
/*                                                              Windows                                                                    */
/*                                                           天师苍邪科技                                                                 */
/*                                                   www.tianshicangxie.com                                                        */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                           */
/***************************************************************************************************/
// Header files
#include "Window.h"

// Initializing the window and start the main loop
void ct::Window::Run(void)
{
	// Create a new window 
	sf::RenderWindow window(sf::VideoMode(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT), title);

	// Initializing the new window
	if (WindowInit(window))
		cerr << "ERROR : Can`t initializing the window!" << endl;
	// Initializing all the entities and other stuff
	if (EntityInit())
		cerr << "ERROR : Can`t initializing entities!" << endl;

	// Main loop 
	while (window.isOpen())
	{
		// Update all the entities
		Update();
		// Clear the window
		Clear(window);
		// Render all the sprites and texts on the window
		Draw(window);
		Display(window);
	}
}

// Hook of the events
void ct::Window::EventHook(void)
{
	// Used for grabbing and repostioning a transparent window
	static sf::Vector2i grabOffset;
	static bool grabFlag = false;
	sf::Event event;

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
}

// Initializing the renderwindow
FuncStat ct::Window::WindowInit(sf::RenderWindow & _window)
{
	// Set framerate limit
	_window.setFramerateLimit(60);

	// Get the handle of the window and configure its properties
	HWND hwnd = _window.getSystemHandle();
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
	// WS_EX_TOOLWINDOW

	// Set window to transparent and boardless
	if (!Debug_Mode)
	{
		MARGINS margins;
		margins.cxLeftWidth = -1;
		SetWindowLong(hwnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
		DwmExtendFrameIntoClientArea(hwnd, &margins);
	}

	return OK;
}

// Initializing all the entities and other stuff
FuncStat ct::Window::EntityInit(void)
{
	static ct::Button ButtonDebug(ICON_VISUAL_STUDIO, sf::Vector2f(0.2, 0.2));
	ButtonDebug.SetPostion(sf::Vector2f(MAIN_WINDOW_WIDTH / 2, MAIN_WINDOW_HEIGHT / 2));
	buttonList.insert(pair<sf::String, ct::Button *>("VS", &ButtonDebug));

	return OK;
}

// To handle all the events
FuncStat ct::Window::HandleEvent(sf::RenderWindow & _window)
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
	}
	return OK;
}

// Updating all the entities
/// Implementing anmimations, etc.
FuncStat ct::Window::Update(void)
{

	return OK;
}

// Clear the window
FuncStat ct::Window::Clear(sf::RenderWindow & _window)
{
	_window.clear(sf::Color::Transparent);
	return OK;
}

// Render all the stuf on the screen
FuncStat ct::Window::Draw(sf::RenderWindow & _window)
{
	// _window.draw(buttonList["VS"]->GetSprite());
	return OK;
}

// Rereash the screen with the buff we updated and drawn
FuncStat ct::Window::Display(sf::RenderWindow &  _window)
{
	_window.display();
	return OK;
}