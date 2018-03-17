/***************************************************************************************************/
/*                                                        Hamman re-edition                                                          */
/*                                                              Entity Class	                                                               */
/*                                                            天师苍邪科技                                                                */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once
// Header files
#include "Defination.h"

/***************************************************************************************************/
// Class : Entity
/// Store all data of a entity and control the behavior of a entity
class Entity
{   
public:
	// Constructors
	Entity(void) = default;
	Entity(const string & _resPath, const sf::Vector2f & _scale);
public:
	// Setting the postion of the entity
	FuncStat SetPostion(const sf::Vector2f _pos);
	// To get the reference of the sf::texture
	inline sf::Texture & GetTexture(void) { return this->texture; }
	// To get the reference of the sf::sprite
	inline sf::Sprite & GetSprite(void) { return this->sprite; }
private:
	sf::Texture texture;
	sf::Sprite sprite;
};

/***************************************************************************************************/
// Class : Character
/// Subclass of the Entity
/// Control the behavior of the main character rendered in the main window
class Character : public Entity
{
public:
	// Constucters
	Character() = default;
	Character(const string & _resPath, sf::Vector2f  & _scale) : Entity(_resPath, _scale) {};
public:
	// To implement the floating animation of the main chatacter
	FuncStat FloatAnimation(const unsigned int & _mode);
	// Float Mode 1 : Using Acceleration and Velocity to contral the animation
	FuncStat FloatMode1(void);
	// Float Mode 2 : Frame-perfect!
	FuncStat FloatMode2(void);
private:
	// Floating Acceleration
	int floatAccr = -FLOAT_ACCR_MAX;
	// Floating Velocity
	int floatVelocity = FLOAT_VELOCITY_MAX;
	// Floating Direction Flag
	bool floatDirFlag = true;
};
