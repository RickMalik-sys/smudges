#ifndef cursorH
#define cursorH
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
//------------------------------------------------------------------------------
class CaretControl
{

public :
//-----------------------------------------------------------------[move around]
	std::string MoveHome()
	{
		return "\033[0;0H";
	}
	std::string MoveTo(int line, int column)
	{
		return "\033[" + std::to_string(line) + ";" + std::to_string(column) + "f";
	}
	std::string MoveUp(int lines)
	{
		return "\033[" + std::to_string(lines) + "A";
	}
	std::string MoveDown(int lines)
	{
		return "\033[" + std::to_string(lines) + "B";
	}
	std::string MoveRight(int columns)
	{
		return "\033[" + std::to_string(columns) + "C";
	}
	std::string MoveLeft(int columns)
	{
		return "\033[" + std::to_string(columns) + "D";
	}
	std::string MoveToNextLine(int linesdown)
	{
		return "\033[" + std::to_string(linesdown) + "E";
	}
	std::string MoveToPrevLine(int linesup)
	{
		return "\033[" + std::to_string(linesup) + "F";
	}
	std::string MoveToColumn(int column)
	{
		return "\033[" + std::to_string(column) + "G";
	}
//-----------------------------------------------------------------------[erase]
	std::string EraseToScreenEnd()
	{
		return "\033[0J";
	}
	std::string EraseToScreenBegin()
	{
		return "\033[1J";
	}
	std::string EraseEntireScreen()
	{
		return "\033[2J";
	}
	std::string EraseToEndOfLine()// from current pos
	{
		return "\033[0K";
	}
	std::string EraseToBeginOfLine()// from current pos
	{
		return "\033[1K";
	}
	std::string EraseEntireLine(bool returntostartofline)
	{
		std::string eel;
		if(returntostartofline)
		{
			eel = "\033[2K \r";//true: after erase, caret moves to row 0
		}
		else
		{
			eel = "\033[2K";//false: after erase, caret stays where it was
		}
		return  eel;
	}
//------------------------------------------------------------------[visibility]
	std::string ShowCaret()
	{
		return "\033[?25h";
	}
	std::string HideCaret()
	{
		return "\033[?25l";
	}
	std::string SaveScreen()
	{
		return "\033[?47h";
	}
	std::string RestoreScreen()
	{
		return "\033[?47l";
	}
	std::string EnableBuffer()
	{
		return "\033[?1049h";
	}
	std::string DisableBuffer()
	{
		return "\033[?1049l";
	}
//------------------------------------------------------------[caret position X]

	//	USE EXAMPLE:
	//		CaretControl TheCaret;
	//		int xCurrent = TheCaret.GetPositionX(&x, &y);
	//		int yCurrent = TheCaret.GetPositionY(&x, &y);
	//		std::cout << "x:" << xCurrent -1 << " | y:" << yCurrent -1 << "  \n";
	//		std::string s = "x:" + to_string(xCurrent -1) + "|y:" + to_string(yCurrent -1);
	//		statusbar.SetText(3, s, COLOR_PAIR(0));// snipped from an ncurses project
	//	sample result		 x:12|y:25

	int GetPositionX(int *x, int *y)
	{
		char buf[30]={0};
		int ret, i, pow;
		char ch;
		*y = 0; *x = 0;
		struct termios term, restore;
		tcgetattr(0, &term);
		tcgetattr(0, &restore);
		term.c_lflag &= ~(ICANON|ECHO);
		tcsetattr(0, TCSANOW, &term);
		write(1, "\033[6n", 4);
		for( i = 0, ch = 0; ch != 'R'; i++ )
		{
			ret = read(0, &ch, 1);
			if ( !ret )
			{
				tcsetattr(0, TCSANOW, &restore);
				fprintf(stderr, "getpos: error reading response!\n");
				return 1;
			}
			buf[i] = ch;
		}
		if (i < 2)
		{
			tcsetattr(0, TCSANOW, &restore);
			return(1);
		}
		for( i -= 2, pow = 1; buf[i] != ';'; i--, pow *= 10)
			*x = *x + ( buf[i] - '0' ) * pow;
		for( i--   , pow = 1; buf[i] != '['; i--, pow *= 10)
			*y = *y + ( buf[i] - '0' ) * pow;
		tcsetattr(0, TCSANOW, &restore);
		return *x;
	}
//------------------------------------------------------------[caret position Y]
	int GetPositionY(int *x, int *y)
	{
		char buf[30]={0};
		int ret, i, pow;
		char ch;
		*y = 0; *x = 0;
		struct termios term, restore;
		tcgetattr(0, &term);
		tcgetattr(0, &restore);
		term.c_lflag &= ~(ICANON|ECHO);
		tcsetattr(0, TCSANOW, &term);
		write(1, "\033[6n", 4);
		for( i = 0, ch = 0; ch != 'R'; i++ )
		{
			ret = read(0, &ch, 1);
			if ( !ret )
			{
				tcsetattr(0, TCSANOW, &restore);
				fprintf(stderr, "getpos: error reading response!\n");
				return 1;
			}
			buf[i] = ch;
		}
		if (i < 2)
		{
			tcsetattr(0, TCSANOW, &restore);
			return(1);
		}
		for( i -= 2, pow = 1; buf[i] != ';'; i--, pow *= 10)
			*x = *x + ( buf[i] - '0' ) * pow;
		for( i--   , pow = 1; buf[i] != '['; i--, pow *= 10)
			*y = *y + ( buf[i] - '0' ) * pow;
		tcsetattr(0, TCSANOW, &restore);
		return *y;
	}
//------------------------------------------------------------------------[More]


//------------------------------------------------------[Constructor/Destructor]
	CaretControl(){}
	~CaretControl(){}
};// end of class
#endif
//EOF
