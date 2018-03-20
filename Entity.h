/***************************************************************************************************/
/*                                                        Hamman re-edition                                                          */
/*																	Entity 	                                                                  */
/*                                                            天师苍邪科技                                                                */
/*                                                   www.tianshicangxie.com                                                        */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
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
	// Class : Entity
	/// The parent class of all kinds of various stuffs in the window, especially which has textures and sprites.
	class Entity
	{
	public:
		// Constructors
		Entity(void) = default;
		Entity(const sf::String & _resPath, const sf::Vector2f & _scale);
	public:
		// Setting the postion of the entity
		FuncStat SetPostion(const sf::Vector2f & _pos);
		// To get the reference of the sf::texture
		inline sf::Texture & GetTexture(void) { return this->texture; }
		// To get the reference of the sf::sprite
		inline sf::Sprite & GetSprite(void) { return this->sprite; }
	protected:
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
		// Constuctors
		Character(void) = default;
		Character(const sf::String & _resPath, sf::Vector2f  & _scale) : Entity(_resPath, _scale) {}
	public:
		// Defines the mode which Animation takes
		enum AnimationMode { Mode1, Mode2, Mode3 };
		// To implement the floating animation of the main chatacter
		FuncStat FloatAnimation(const AnimationMode & _mode);
		// Float Mode 1 : Using Acceleration and Velocity to control the animation
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

	/***************************************************************************************************/
	// Class : Button
	/// Subclass of the Entity
	/// Clickablie button used for menu and other controling stuff
	class Button : public Entity
	{
	public:
		Button() = default;
		Button(const sf::String & _resPath, sf::Vector2f  & _scale) : Entity(_resPath, _scale) {}
	public:
		// To implement the floating animation of the button
		FuncStat FloatAnimation(void);
	private:
		// Floating Direction Flag
		bool floatDirFlag = true;
		bool isClicked = false;
	};
}