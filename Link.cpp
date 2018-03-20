/***************************************************************************************************/
/*                                                      Hamman re-edition                                                            */
/*                                                                 Utility                                                                       */
/*                                                           天师苍邪科技                                                                 */
/*                                                   www.tianshicangxie.com                                                        */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                           */
/***************************************************************************************************/
#include "Link.h"

/***************************************************************************************************/
// Class : Shortcut
/// Subclass of the Entity
/// Shortcut to run other programs

ct::Shortcut::Shortcut(const sf::String & _name, const sf::String & _lnkPath)
{
	this->shortcutName = _name;
	this->shortcutPath = _lnkPath;
}

FuncStat ct::Shortcut::Open(void)
{
	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
	SHChangeNotify(SHCNE_DELETE, SHCNF_PATH, _pgmptr, NULL);

	string temp = shortcutPath;
	size_t size = temp.length();
	wchar_t *buffer = new wchar_t[size + 1];
	MultiByteToWideChar(CP_ACP, 0, temp.c_str(), size, buffer, size * sizeof(wchar_t));
	buffer[size] = 0;
	ShellExecute(NULL, TEXT("open"), buffer, NULL, NULL, SW_SHOWNORMAL);
	delete buffer;

	return OK;
}
