/***************************************************************************************************/
/*                                                      Hamman re-edition                                                            */
/*                                                                 Utility                                                                       */
/*                                                           天师苍邪科技                                                                 */
/*                                                   www.tianshicangxie.com                                                        */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                           */
/***************************************************************************************************/
#pragma once
// Header files
#include "Defination.h"

/***************************************************************************************************/
// NameSpace : Celestial Tech
namespace ct
{
	/***************************************************************************************************/
	// Class : Shortcut
	/// Subclass of the Entity
	/// Shortcut to run other programs
	class Shortcut
	{
	public:
		Shortcut() = default;
		Shortcut(const sf::String & _name, const sf::String & _lnkPath);
	public:
		FuncStat Open(void);

	private:
		sf::String shortcutName;
		sf::String shortcutPath;
	};
}
