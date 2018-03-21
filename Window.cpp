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
	sf::RenderWindow window(sf::VideoMode(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT), title, sf::Style::None);

	// Initializing the new window
	if (WindowInit(window))
		cerr << "ERROR : Can`t initializing the window!" << endl;
	// Initializing all the entities and other stuff
	if (EntityInit())
		cerr << "ERROR : Can`t initializing entities!" << endl;

	// Update the region for the first time
	regionUpdateFlag = true;

	// Main loop 
	while (window.isOpen())
	{
		// Handle all the events
		HandleEvent(window);
		// Update all the entities
		Update(window);
		// Clear the window
		Clear(window);
		// Render all the sprites and texts on the window
		Draw(window);
		// Display the window
		Display(window);
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

	// Set window to transparent
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

	static ct::Character hammanG(HAMMAN_G_FULL, sf::Vector2f(0.5, 0.5));
	hammanG.SetPostion(sf::Vector2f(MAIN_WINDOW_WIDTH / 2, MAIN_WINDOW_HEIGHT / 2));
	characterList.insert(pair<sf::String, ct::Character *>("HammanG", &hammanG));

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
FuncStat ct::Window::Update(sf::RenderWindow & _window)
{
	characterList["HammanG"]->FloatAnimation(ct::Character::Mode2);
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
	_window.draw(buttonList["VS"]->GetSprite());
	_window.draw(characterList["HammanG"]->GetSprite());
	return OK;
}

// Rereash the screen with the buff we updated and drawn
FuncStat ct::Window::Display(sf::RenderWindow &  _window)
{
	_window.display();
	if (regionUpdateFlag)
	{
		static int count = 0;
		if (count < 2)
		{
			RegionUpdate(_window);
			count++;
		}
		else
		{
			regionUpdateFlag = false;
			count = 0;
		}
	}
	return OK;
}

// Update the custom shape of the main window
FuncStat ct::Window::RegionUpdate(sf::RenderWindow & _window)
{
	// Create an empty region 
	HRGN wndRgn = CreateRectRgn(0, 0, 0, 0);
	HWND hwnd = _window.getSystemHandle();
	sf::Image img = _window.capture();

	if (Custom_Shaped_Window)
	{
		for (size_t y = 0; y < img.getSize().y; y++)
		{
			int xIndex = 0;
			while (xIndex < img.getSize().x)
			{
				HRGN tempRgn;
				int  xLeft = 0, xRight = 0;
				while ((xIndex < img.getSize().x) && (img.getPixel(xIndex, y) == sf::Color::Transparent))
					xIndex++;
				xLeft = xIndex;

				while ((xIndex < img.getSize().x) && (img.getPixel(xIndex, y) != sf::Color::Transparent))
					xIndex++;
				xRight = xIndex;

				if (xLeft != xRight)
					tempRgn = CreateRectRgn(xLeft, y, xRight, y + 20);
				else
					tempRgn = CreateRectRgn(0, 0, 0, 0);
				CombineRgn(wndRgn, wndRgn, tempRgn, RGN_OR);
				DeleteObject(tempRgn);
			}
		}
		SetWindowRgn(hwnd, wndRgn, TRUE);
		if (wndRgn != NULL)DeleteObject(wndRgn);
	}
	return OK;
}
