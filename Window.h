/***************************************************************************************************/
/*                                                      Hamman re-edition                                                            */
/*                                                              Windows                                                                    */
/*                                                           天师苍邪科技                                                                 */
/*                                                   www.tianshicangxie.com                                                        */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                           */
/***************************************************************************************************/
#pragma once
// Header files
#include "Defination.h"
#include "Entity.h"

/***************************************************************************************************/
// NameSpace : Celestial Tech
namespace ct
{
	/***************************************************************************************************/
	// Class : Window
	/// Main rendering logic 
	/// Store all the entities and other stuff, i.e. sound effect, text, etc.
	class Window
	{
	public:
		// Constructor
		/// Initializing the parameter
		Window(void) = default;
	public:
		// Initializing the window and start the main loop
		void Run(void);
		// Hook of the events
		void EventHook(void);

	private:
		// Initializing the renderwindow
		FuncStat WindowInit(sf::RenderWindow & _window);
		// Initializing all the entities and other stuff
		FuncStat EntityInit(void);
		// To handle all the events
		FuncStat HandleEvent(sf::RenderWindow & _window);
		// Updating all the entities
		/// Implementing anmimations, etc.
		FuncStat Update(void);

	private:
		// Clear the window
		FuncStat Clear(sf::RenderWindow & _window);
		// Render all the stuf on the screen
		FuncStat Draw(sf::RenderWindow & _window);
		// Rereash the screen with the buff we updated and drawn
		FuncStat Display(sf::RenderWindow & _window);

	private:
		// The title of the main window
		string title = "Hamman Forever!";
		// Store all the ct::Button in the main window
		map<sf::String, ct::Button *> buttonList;
	};
}