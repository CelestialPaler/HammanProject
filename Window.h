/***************************************************************************************************/
/*                                                        Hamman re-edition                                                          */
/*                                                           Windoiw Class	                                                               */
/*                                                            天师苍邪科技                                                                */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once
// Header files
#include "defination.h"
#include "Entity.h"
#include "Text.h"

/***************************************************************************************************/
// Class : Window
/// Main rendering logic 
/// Store all the entities and other stuff , i.e. sound effect, text, etc.
class Window
{
public:
	// Constructer
	Window();

private:
	// Initializing all the entities and other stuff
	FuncStat EntityInit(void);
	// To handle all the events
	FuncStat HandleEvent(sf::RenderWindow &_window);
	// Updating all the entities
	/// Implementing anmimations, etc.
	FuncStat Update(void);

private:
	// Clear the window
	FuncStat Clear(sf::RenderWindow &_window);
	// Render all the stuf on the screen
	FuncStat Draw(sf::RenderWindow &_window);
	// Rereash the screen with the buff we updated and drawn
	FuncStat Display(sf::RenderWindow &_window);

private:
	// The title of the main window
	string title = "Hamman forever!";
	// Store all the entities 
	map<string, Entity *> entityList;
	// Store all the texts
	map<string, Text *> textList;
	// Store the main character
	Character * mainCharacter;
	// Flag of showing the dialogue box or not
	bool dialogueFlag = false;
};
