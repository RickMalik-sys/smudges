/****************   color.hpp   ****************\
Used to insert colored text into a string block
\*********************************************/
#ifndef colorH
#define colorH
#include <iostream>
#include <stdio.h>
#include <cstring>

namespace Colors
{

	enum Color : int
	{
		Black	= 30,
		Maroon	= 31,
		Green	= 32,
		Olive	= 33,
		Navy	= 34,
		Purple	= 35,
		Teal	= 36,
		Silver	= 37,
		Gray	= 90,
		Red		= 91,
		Lime	= 92,
		Yellow	= 93,
		Blue	= 94,
		Magenta	= 95,
		Cyan	= 96,
		White	= 97
	};

	enum Attribute : int
	{
		Default		= 0,
		Bold		= 1,
		Faint		= 2,
		Italic		= 3,
		Underline	= 4,
		Blink		= 5,
		Inverse		= 7,
		Hidden		= 8,
		Strike		= 9
	};

	inline std::string SetColoredText(Attribute AT, Color FG, Color BG, const std::string& TEXT)
	{
		return "\033[" + std::to_string(static_cast<int>(AT)) + "m"
		+ "\033[" + std::to_string(static_cast<int>(FG)) + "m"
		+ "\033[" + std::to_string(static_cast<int>(BG) + 10) + "m"
		+ TEXT + "\033[0m";
	}
	inline std::string Reset()
	{
		return "\033[0m";
	}
	inline std::string SetCustomColoredText(Attribute AT, int fred , int fgreen, int fblue, int bred, int bgreen, int bblue, std::string TEXT)
	{
		std::string  _AT, _FG, _BG, RETURN_STRING;
		std::string  RESET_STRING = "\033[0m";
		_AT = "\033[" + std::to_string(static_cast<int>(AT)) + "m";
		_FG = "\033[38;2;" + std::to_string(fred) + ";" + std::to_string(fgreen) + ";" + std::to_string(fblue) + ";";
		_BG = "48;2;" + std::to_string(bred) + ";" + std::to_string(bgreen) + ";" + std::to_string(bblue) + "";

		RETURN_STRING = _AT + _FG + _BG + "m" + TEXT + RESET_STRING;
		return RETURN_STRING;
		//example mystring = SetCustomColoredText(atDefault, 255, 0, 0, 0, 0, 0, "test string");
	}

};
#endif
//EOF
