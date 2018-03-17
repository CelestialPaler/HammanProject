/***************************************************************************************************/
/*                                                        Hamman re-edition                                                          */
/*																 Defination                                                                  */
/*                                                            天师苍邪科技                                                                */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                          */
/***************************************************************************************************/
#pragma once
/***************************************************************************************************/
//  HeaderFiles
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\System.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <Windows.h>
#include <Dwmapi.h>
/***************************************************************************************************/
// Pragma
#pragma comment (lib, "Dwmapi.lib")
/***************************************************************************************************/
// Namespace
using namespace std;
/***************************************************************************************************/
// Debug mode
const bool Debug_Mode = false;
/***************************************************************************************************/
// Window size
#define MAIN_WINDOW_WIDTH 400
#define MAIN_WINDOW_HEIGHT 600
/***************************************************************************************************/
// Res path
const string HAMMAN_G_FULL = "res\\Charactor\\hamman_g_full.png";
const string DIALOGUE_FULL = "res\\Image\\dia.png";
const string FONT_CH_FANG = "res\\Font\\ch_fang.ttf";
/***************************************************************************************************/
// Floating index
#define FLOAT_VELOCITY_MAX 5
#define FLOAT_ACCR_MAX 1
/***************************************************************************************************/
enum FuncStat
{
	OK = 0,
	ERROROR = 1,
	OVERFLOWED = 2
};