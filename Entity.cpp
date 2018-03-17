/***************************************************************************************************/
/*                                                        Hamman re-edition                                                          */
/*                                                              Entity Class	                                                               */
/*                                                            天师苍邪科技                                                                */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#include "Entity.h"
/***************************************************************************************************/
// Entity class
/// Store all data of a entity and control the behavior of a entity

// Constructors
Entity::Entity(const string & _resPath, const sf::Vector2f & _scale)
{
	if (!this->texture.loadFromFile(_resPath))
		std::cerr << "ERROR : Resource not found!" << _resPath << std::endl;
	else
	{
		this->sprite.setTexture(this->texture);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2, this->sprite.getGlobalBounds().height / 2);
		this->sprite.setScale(_scale);
	}
}

// Setting the postion of the entity
FuncStat Entity::SetPostion(const sf::Vector2f _pos)
{
	this->sprite.setPosition(_pos);
	return OK;
}

/***************************************************************************************************/
// Class : Character
/// Subclass of the Entity
/// Control the behavior of the main character rendered in the main window

// To implement the floating animation of the main chatacter
FuncStat Character::FloatAnimation(const unsigned int & _mode)
{
	switch (_mode)
	{
	case 1:
		FloatMode1();
		break;
	case 2:
		FloatMode2();
		break;
	default:
		FloatMode1();
		break;
	}
	return OK;
}

// Float Mode 1 : Using Acceleration and Velocity to contral the animation
FuncStat Character::FloatMode1(void)
{
	static int floatPauseCounter = 0;
	static int floatPauseIndex = 3;
	if (floatPauseCounter == floatPauseIndex)
	{
		if (floatDirFlag)// up
		{
			if (floatVelocity == -FLOAT_VELOCITY_MAX)
			{
				floatDirFlag = false;
				floatAccr = FLOAT_ACCR_MAX;
			}
			else
				floatVelocity += floatAccr;
		}
		else// down 
		{
			if (floatVelocity == FLOAT_VELOCITY_MAX)
			{
				floatDirFlag = true;
				floatAccr = -FLOAT_ACCR_MAX;
			}
			else
				floatVelocity += floatAccr;
		}
		floatPauseCounter = 0;
		this->GetSprite().move(sf::Vector2f(0, floatVelocity));
	}
	else
		floatPauseCounter++;
	return OK;
}

// Float Mode 2 : Frame-perfect!
FuncStat Character::FloatMode2(void)
{
	static unsigned int count = 0;
	static unsigned int frameSkip[] = { 5,5,5,4,4,3,3,2,2,2,2,2,2,3,3,4,4,5,5,5 };
	static size_t frameSkipIndex = 0;
	if (floatDirFlag) // Up
	{
		if (count == frameSkip[frameSkipIndex])
		{
			this->GetSprite().move(sf::Vector2f(0, 1));
			count = 0;
			if (frameSkipIndex == 19)
			{
				frameSkipIndex = 0;
				floatDirFlag = false;
			}
			frameSkipIndex++;
		}
	}
	else // Down
	{
		if (count == frameSkip[frameSkipIndex])
		{
			this->GetSprite().move(sf::Vector2f(0, -1));
			count = 0;
			if (frameSkipIndex == 19)
			{
				frameSkipIndex = 0;
				floatDirFlag = true;
			}
			frameSkipIndex++;
		}
	}
	count++;
	return OK;
}
