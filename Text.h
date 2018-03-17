/***************************************************************************************************/
/*                                                        Hamman re-edition                                                          */
/*																 Text class                                                                   */
/*                                                            天师苍邪科技                                                                */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once
// Header files
#include "Defination.h" 

/***************************************************************************************************/
// Class : text
/// Store all texts
class Text
{
public:
	// Constructor
	Text(void) = default;
	Text(const string & _resPath, const string & _text, const unsigned & _size);
public:
	// Setting string to show on screen 
	FuncStat SetText(const string & _text);
	FuncStat SetColor(const sf::Color & _color);
	FuncStat SetPosition(const sf::Vector2f & _vec);
public:
	inline sf::Text & GetText(void) { return this->text; }
private:
	sf::Font font;
	sf::Text text;
};
