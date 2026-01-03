/*
╔══════════╦══════════╤══════════╗	┏━━┳━━━━━━━━━━━━━━━━━━┓
║          ║          │          ║	┃  ┃                  ┃
╟──────────╫──────────┼──────────╢	┃  ┃                  ┃
╠══════════╩══════════╪══════════╣	┃  ┃                  ┃
║                     │          ║	┃  ┃                  ┃
║  ┌──────────┬────┐  │          ║	┃  ┃                  ┃
║  │          │    │  │          ║	┃  ┃                  ┃
║  ├──────────┤    │  │          ║	┃  ┃                  ┃
║  └──────────┴────┘  │          ║	┃  ┃                  ┃
║                     │          ║	┣━━┻━━━━━━━━━━━━━━━━━━┃
║                     │          ║	┃                     ┃
╚═════════════════════╧══════════╝	┗━━━━━━━━━━━━━━━━━━━━━┛
*/

#ifndef bordersH
#define bordersH

#include  <termios.h>
#include  <fcntl.h>
#include  <errno.h>
#include  <ctype.h>
#include  <cstring>
#include  <stdio.h>
#include  <strings.h>
#include  <iostream>
#include  <stdlib.h>
#include  <vector>
#include  <algorithm>
#include  <time.h>
#include  <random>
#include  <chrono>
#include  <string.h>
#include  <unistd.h>
using namespace std;

class Borders
{
private:

public:

/*
//REFERENCE---------------------------------------------------
//SINGLE------------------------------------------------------
│    SINGLE_VERTICAL
┬    SINGLE_DOWN_HORIZONTAL
─    SINGLE_HORIZONTAL
┴    SINGLE_UP_HORIZONTAL
└    SINGLE_UP_RIGHT
┘    SINGLE_UP_LEFT
┌    SINGLE_DOWN_RIGHT
┐    SINGLE_DOWN_LEFT
--------------------------------------------------------------
├    SINGLE_VERTICAL_RIGHT

┤    SINGLE_VERTICAL_LEFT

┼    SINGLE_VERTICAL_HORIZONTAL
//------------------------------------------------------------
//DOUBLE------------------------------------------------------
║    DOUBLE_VERTICAL
╦    DOUBLE_DOWN_HORIZONTAL
═    DOUBLE_HORIZONTAL
╩    DOUBLE_UP_HORIZONTAL
╚    DOUBLE_UP_RIGHT
╝    DOUBLE_UP_LEFT
╔    DOUBLE_DOWN_RIGHT
╗    DOUBLE_DOWN_LEFT
//--------------------------------------------------------------
╠    DOUBLE_VERTICAL_RIGHT

╣    DOUBLE_VERTICAL_LEFT

╬    DOUBLE_VERTICAL_HORIZONTAL
//------------------------------------------------------------------
//HEAVY-------------------------------------------------------------
┃	HEAVY VERTICAL	
┳	HEAVY DOWN AND HORIZONTAL
━	HEAVY HORIZONTAL
┻	HEAVY UP AND HORIZONTAL
┗	HEAVY UP AND RIGHT
┛	HEAVY UP AND LEFT
┏	HEAVY DOWN AND RIGHT
┓	HEAVY DOWN AND LEFT
//------------------------------------------------------------------
┣	HEAVY_VERTICAL_RIGHT

┫	HEAVY_VERTICAL_LEFT

╋	HEAVY_VERTICAL_HORIZONTAL
//------------------------------------------------------------------
//MIXED DOUBLE AND SINGLE-------------------------------------------
╙    UP_DOUBLE_RIGHT_SINGLE
╨    UP_DOUBLE_HORIZONTAL_SINGLE
╜    UP_DOUBLE_LEFT_SINGLE
╓    DOWN_DOUBLE_RIGHT_SINGLE
╥    DOWN_DOUBLE_HORIZONTAL_SINGLE
╖    DOWN_DOUBLE_LEFT_SINGLE
--------------------------------------------------------------------
╟    VERTICAL_DOUBLE_RIGHT_SINGLE

╢    VERTICAL_DOUBLE_LEFT_SINGLE

╫    VERTICAL_DOUBLE_HORIZONTAL_SINGLE
--------------------------------------------------------------------
╞    VERTICAL_SINGLE_RIGHT_DOUBLE

╡    VERTICAL_SINGLE_LEFT_DOUBLE

╪    VERTICAL_SINGLE_HORIZONTAL_DOUBLE
------------------------------------------------------------------
╘    UP_SINGLE_RIGHT_DOUBLE
╧    UP_SINGLE_HORIZONTAL_DOUBLE
╛    UP_SINGLE_LEFT_DOUBLE
╒    DOWN_SINGLE_RIGHT_DOUBLE
╤    DOWN_SINGLE_HORIZONTAL_DOUBLE
╕    DOWN_SINGLE_LEFT_DOUBLE
--------------------------------------------------------------------
*/
//VARIABLES------------------------------------------------
//SINGLE---------------------------------------------------
string SINGLE_VERTICAL = "\342\224\202";
string SINGLE_DOWN_HORIZONTAL = "\342\224\254";
string SINGLE_HORIZONTAL = "\342\224\200";
string SINGLE_UP_HORIZONTAL = "\342\224\264";
string SINGLE_UP_RIGHT = "\342\224\22";
string SINGLE_UP_LEFT = "\342\224\230";
string SINGLE_DOWN_RIGHT = "\342\224\214";
string SINGLE_DOWN_LEFT = "\342\224\220";
//---------------------------------------------------------
string SINGLE_VERTICAL_RIGHT = " \342\224\234";
string SINGLE_VERTICAL_LEFT = "\342\224\244";
string SINGLE_VERTICAL_HORIZONTAL = "\342\224\274";
//DOUBLE---------------------------------------------------
string DOUBLE_VERTICAL = "\342\225\221";
string DOUBLE_DOWN_HORIZONTAL = "\342\225\246";
string DOUBLE_HORIZONTAL = "\342\225\220";
string DOUBLE_UP_HORIZONTAL = "\342\225\251";
string DOUBLE_UP_RIGHT = "\342\225\232";
string DOUBLE_UP_LEFT = "\342\225\235";
string DOUBLE_DOWN_RIGHT = "\342\225\224";
string DOUBLE_DOWN_LEFT = "\342\225\227";
//-------------------------------
string DOUBLE_VERTICAL_RIGHT = "\342\225\240";
string DOUBLE_VERTICAL_LEFT = "\342\225\243";
string DOUBLE_VERTICAL_HORIZONTAL = "\342\225\254";
//MIXED DOUBLE AND SINGLE-----------------------------------
string UP_DOUBLE_RIGHT_SINGLE = "\342\225\231";
string UP_DOUBLE_HORIZONTAL_SINGLE = "\342\225\250";
string UP_DOUBLE_LEFT_SINGLE = "\342\225\234";
string DOWN_DOUBLE_RIGHT_SINGLE = "\342\225\223";
string DOWN_DOUBLE_HORIZONTAL_SINGLE = "\342\225\245";
string DOWN_DOUBLE_LEFT_SINGLE = "\342\225\226";
//-------------------------------------
string VERTICAL_DOUBLE_RIGHT_SINGLE = "\342\225\237";
string VERTICAL_DOUBLE_LEFT_SINGLE = "\342\225\242";
string VERTICAL_DOUBLE_HORIZONTAL_SINGLE = "\342\225\253";
//-----------------------------------
string UP_SINGLE_RIGHT_DOUBLE = "\342\225\230";
string UP_SINGLE_HORIZONTAL_DOUBLE = "\342\225\247";
string UP_SINGLE_LEFT_DOUBLE = "\342\225\233";
string DOWN_SINGLE_RIGHT_DOUBLE = "\342\225\222";
string DOWN_SINGLE_HORIZONTAL_DOUBLE = "\342\225\244";
string DOWN_SINGLE_LEFT_DOUBLE = "\342\225\225";
//-------------------------------------
string VERTICAL_SINGLE_RIGHT_DOUBLE = "\342\225\236";
string VERTICAL_SINGLE_LEFT_DOUBLE = "\342\225\241";
string VERTICAL_SINGLE_HORIZONTAL_DOUBLE = "\342\225\252";
//HEAVY--------------------------------------------------
string	HEAVY_VERTICAL = "\342\224\203";
string	HEAVY_DOWN_HORIZONTAL = "\342\224\263";
string	HEAVY_HORIZONTAL = "\342\224\201";
string	HEAVY_UP_HORIZONTAL = "\342\224\273";
string	HEAVY_UP_RIGHT = "\342\224\227";
string	HEAVY_UP_LEFT = "\342\224\233";
string	HEAVY_DOWN_RIGHT = "\342\224\217";
string	HEAVY_DOWN_LEFT = "\342\224\223";
//--------------------------------------------------------
string	HEAVY_VERTICAL_RIGHT = "\342\224\243";
string	HEAVY_VERTICAL_LEFT = "\342\224\253";
string	HEAVY_VERTICAL_HORIZONTAL = "\342\225\213";
int SCREEN_TOP_LEFT, SCREEN_TOP_RIGHT, SCREEN_WIDTH;
int SCREEN_BOTTOM_LEFT, SCREEN_BOTTOM_RIGHT, SCREEN_HEIGHT;
int posX, posY;
//FUNCTIONS-----------------------------------------------
Borders(){};
~Borders(){};

};
#endif
