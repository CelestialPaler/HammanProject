/***************************************************************************************************/
/*                                                        Hamman re-edition                                                          */
/*                                                               Utils Class	                                                               */
/*                                                            天师苍邪科技                                                                */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#include "Utils.h"

/***************************************************************************************************/
// Class : Shortcut
/// Subclass of the Entity
/// 

Shortcut::Shortcut(const string & _name, const string & _lnkPath)
{
	this->shortcutName = _name;
	this->shortcutPath = _lnkPath;
}

FuncStat Shortcut::Open(void)
{
	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
	SHChangeNotify(SHCNE_DELETE, SHCNF_PATH, _pgmptr, NULL);

	size_t size = shortcutPath.length();
	wchar_t *buffer = new wchar_t[size + 1];
	MultiByteToWideChar(CP_ACP, 0, shortcutPath.c_str(), size, buffer, size * sizeof(wchar_t));
	buffer[size] = 0;
	ShellExecute(NULL, TEXT("open"), buffer, NULL, NULL, SW_SHOWNORMAL);
	delete buffer;

	return OK;
}
