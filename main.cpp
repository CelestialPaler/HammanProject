/***************************************************************************************************/
/*                                                      Hamman re-edition                                                            */
/*                                                                 Main                                                                       */
/*                                                           天师苍邪科技                                                                 */
/*                                                   www.tianshicangxie.com                                                        */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                           */
/***************************************************************************************************/
#include "Defination.h"
#include "Window.h"
#include "Entity.h"
#include "Link.h"

int main()
{
	ct::Window mainWindow;
	sf::Thread mainLoop(&ct::Window::Run, &mainWindow);
	mainLoop.launch();

	return 0;
}