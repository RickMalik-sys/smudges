/****************   color.h   ****************\
Used to insert colored text into a string block

Copyright (c) 2026 - R.Malik
\*********************************************/
#ifndef colorH
#define colorH

#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

//--------------------
#define clBlack 0
#define clMaroon 1
#define clGreen 2
#define clOlive 3
#define clNavy 4
#define clViolet 5
#define clBlue 6
#define clSilver 7
#define clGray 8
#define clRed 9
#define clLime 10
#define clYellow 11
#define clMagenta 12
#define clCyan 13
#define clWhite 14
//--------------------
#define atDefault 15
#define atBold 16
#define atFaint 17
#define atItalic 18
#define atUnderline 19
#define atBlink 20
#define atInverse 21
#define atHidden 22
#define atStrike 23

//	Example use:
//	myString = GetColoredText(atDefault, clBlue, clWhite, "a sample string");
//  cout << GetColoredText(atBold, clBlack, clOlive, myString) << " Black BG, Bold Olive FG \n";
// uses ANSI escape-seq codes for terminals that support color

std::string GetColoredText(int AT, int BG, int FG, std::string TEXT)
	{
	std::string  _AT, _FG, _BG, RETURN_STRING;
	std::string  RESET_STRING = "\e[0m";
	switch(FG)//forground
		{
		case 0:{_FG = "\e[30m";	break;}
		case 1:{_FG = "\e[31m";	break;}
		case 2:{_FG = "\e[32m";	break;}
		case 3:{_FG = "\e[33m";	break;}
		case 4:{_FG = "\e[34m";	break;}
		case 5:{_FG = "\e[35m";	break;}
		case 6:{_FG = "\e[36m";	break;}
		case 7:{_FG = "\e[37m";	break;}
		case 8:{_FG = "\e[90m";	break;}
		case 9:{_FG = "\e[91m";	break;}
		case 10:{_FG = "\e[92m"; break;}
		case 11:{_FG = "\e[93m"; break;}
		case 12:{_FG = "\e[95m"; break;}
		case 13:{_FG = "\e[96m"; break;}
		case 14:{_FG = "\e[97m"; break;}
		}
		switch (BG)//background
		{
		case 0:{_BG = "\e[40m";break;}
		case 1:{_BG = "\e[41m";break;}
		case 2:{_BG = "\e[42m";break;}
		case 3:{_BG = "\e[43m";break;}
		case 4:{_BG = "\e[44m";break;}
		case 5:{_BG = "\e[45m";break;}
		case 6:{_BG = "\e[46m";break;}
		case 7:{_BG = "\e[47m";break;}
		case 8:{_BG = "\e[100m";break;}
		case 9:{_BG = "\e[101m";break;}
		case 10:{_BG = "\e[102m";break;}
		case 11:{_BG = "\e[103m";break;}
		case 12:{_BG = "\e[105m";break;}
		case 13:{_BG = "\e[106m";break;}
		case 14:{_BG = "\e[107m";break;}
		}
		switch (AT)//attributes
		{
		case 15:{_AT = "\e[0m";	break;}//reset
		case 16:{_AT = "\e[1m";	break;}//bold
		case 17:{_AT = "\e[2m";	break;}//dim
		case 18:{_AT = "\e[3m";	break;}//italic
		case 19:{_AT = "\e[4m";	break;}//underline
		case 20:{_AT = "\e[5m";	break;}//blink
		case 21:{_AT = "\e[7m";	break;}//inverse
		case 22:{_AT = "\e[8m";	break;}//hidden
		case 23:{_AT = "\e[9m";	break;}//strike
		}
	RETURN_STRING = _AT +_BG + _FG + TEXT + RESET_STRING;
	return RETURN_STRING;
	}
#endif
