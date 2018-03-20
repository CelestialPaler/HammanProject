/***************************************************************************************************/
/*                                                        Hamman re-edition                                                          */
/*                                                               Utils Class	                                                               */
/*                                                            天师苍邪科技                                                                */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once
#include "Defination.h"

/***************************************************************************************************/
// Class : Shortcut
/// Subclass of the Entity
/// 
class Shortcut
{
public:
	Shortcut() = default;
	Shortcut(const string & _name, const string & _lnkPath);
public:
	FuncStat Open(void);

private:
	string shortcutName;
	string shortcutPath;
};