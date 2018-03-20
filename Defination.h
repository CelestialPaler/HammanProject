/***************************************************************************************************/
/*                                                      Hamman re-edition                                                            */
/*                                                              Defination                                                                  */
/*                                                           天师苍邪科技                                                                 */
/*                                                   www.tianshicangxie.com                                                        */
/*                                      Copyright © 2015-2018 Celestial Tech Inc.                                           */
/***************************************************************************************************/
#pragma once
/***************************************************************************************************/
// System HeaderFiles
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <Windows.h>
#include <Dwmapi.h>
#include <shlobj.h>
#include <shellapi.h>
/***************************************************************************************************/
// SFML HeaderFiles
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\System.hpp>

/***************************************************************************************************/
// Pragma
#pragma comment (lib, "Dwmapi.lib")
/***************************************************************************************************/
// Namespace
using namespace std;
/***************************************************************************************************/
// Debug mode
const bool Debug_Mode = true;
/***************************************************************************************************/
// Window size
#define MAIN_WINDOW_WIDTH 400
#define MAIN_WINDOW_HEIGHT 600
/***************************************************************************************************/
// Res path
// Character
const string HAMMAN_G_FULL = "res\\Charactor\\hamman_g_full.png";
const string HAMMAN_D_FULL = "res\\Charactor\\hamman_d_full.png";
// Image
const string DIALOGUE_BOX_FULL = "res\\Image\\dia.png";
const string ICON_VISUAL_STUDIO = "res\\Image\\vs.png";
const string ICON_QQ = "res\\Image\\qq.png";
// Font
const string FONT_CH_FANG = "res\\Font\\ch_fang.ttf";
// Link
const string LINK_VISUAL_STUDIO = "res\\Link\\VisualStudio.exe";
const string LINK_QQ = "res\\Link\\QQ.exe";
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