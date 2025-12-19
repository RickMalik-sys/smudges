
#ifndef cfontzH
#define cfontzH
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include  <termios.h>
#include  <fcntl.h>
#include  <errno.h>
#include  <ctype.h>
//============================================================================
typedef unsigned char ubyte;
typedef signed char sbyte;
typedef unsigned short word;
typedef unsigned long dword;
typedef union
  {
  ubyte
    as_bytes[2];
  word
    as_word;
  } WORD_UNION;
//============================================================================
//============================================================================
int Serial_Init(char *devname, int baud_rate);
void Uninit_Serial();
void SendByte(unsigned char datum);
void Sync_Read_Buffer(void);
dword BytesAvail(void);
ubyte GetByte(void);
dword PeekBytesAvail(void);
void Sync_Peek_Pointer(void);
void AcceptPeekedData(void);
ubyte PeekByte(void);
void SendData(unsigned char *data,int length);
void SendString(char *data);
std::string exec(const char* cmd);
void timer_handler(int signum) ;
//============================================================================
std::string s3, s2, s1, s0;
    char c, r;
int cleardisplay;
bool QuietMode;
#endif

