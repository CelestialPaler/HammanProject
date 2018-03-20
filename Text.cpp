/***************************************************************************************************/
/*                                                        Hamman re-edition                                                          */
/*																 Text class                                                                   */
/*                                                            天师苍邪科技                                                                */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#include "Text.h"
/***************************************************************************************************/
// Class : text
/// Store all texts

// Constructor
Text::Text(const string & _resPath, const string & _text, const unsigned & _size)
{
	if (!this->font.loadFromFile(_resPath))
		std::cerr << "ERROR : Resource not found!" << _resPath << std::endl;
	else
	{
		this->text.setFont(this->font);
		this->text.setString(_text);
		this->text.setCharacterSize(_size);
		this->text.setOrigin(this->text.getGlobalBounds().width / 2, this->text.getGlobalBounds().height / 2);
	}
}

// Set the content of text
FuncStat Text::SetText(const string & _text)
{
	this->text.setString(_text);
	return OK ;
}

// Set the color of text
FuncStat Text::SetColor(const sf::Color & _color)
{
	this->text.setColor(_color);
	return OK;
}

// Set the postion of text
FuncStat Text::SetPosition(const sf::Vector2f & _vec)
{
	this->text.setPosition(_vec);
	return FuncStat();
}
