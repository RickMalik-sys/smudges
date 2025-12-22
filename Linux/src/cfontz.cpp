//cfontz.cpp/h (c) 2025 RMSoftware--------------------------------------------
#include <iostream>
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include  <termios.h>
#include  <fcntl.h>
#include  <errno.h>
#include  <ctype.h>
#include "c634.h"
using namespace std;
//============================================================================
#define FALSE   0
#define TRUE    1




//============================================================================
// --help
void printHelpMessage() {
    cout << "Usage: cfontz [OPTIONS] || [PORT] [BAUD] [ADDITIONAL]\n\n";
    cout << "Required:\n";
    cout << "  PORT          path to port, ie, /dev/ttyS0-3\n";
    cout << "  BAUD          2400, 4800, 9600, 19200\n";
    cout << "Example: cfontz /dev/ttyS0 9600\n\n";
    cout << "Additional:\n";
    cout << "  quiet         Minimal output to stdout\n";
    cout << "  clear         Clears display, then exits\n";
    cout << "Example: cfontz /dev/ttyS0 9600 quiet -or- cfontz /dev/ttyS0 9600 clear\n\n";
    cout << "Options:\n";
    cout << "  -h  --help       Display this help message\n";
    cout << "  -v  --version    Display program version\n";
    cout << "Example: cfontz -h -or- cfontz --help || cfontz -v -or- cfontz --version\n\n";
    cout << "Use CTRL+C to Quit\n\n";
    cout << "Crystalfontz-SR634 Display Driver (RMSoftware-2025)\n";
    cout << "Feedback can be directed to fcinstaller@gmail.com, subj: cfontz.\n";
    // Add more options and descriptions as needed
}


int main(int argc, char* argv[]) {
    // Loop through the command-line arguments, starting from argv[1]
    // argv[0] is always the program name itself
	QuietMode = false;
    cleardisplay= false;
    for (int i = 1; i < argc; ++i)
	{
        std::string arg = argv[i];
        if (arg == "--help" || arg == "-h")
		{
	            printHelpMessage();
	            return 0; // Exit after displaying help
	        }

        else if (arg == "--version" || arg == "-v")
		{
	            std::cout << "cfontz Version 1.0" << std::endl;
        	    return 0; // Exit after displaying version
        	}
//        else
//		{
//	            std::cerr << "Unknown argument: " << arg << std::endl;
//	            std::cerr << "Use --help for usage information." << std::endl;
//	            return 1; // Indicate error
//	        }

//===========================================================================
// main logic

  //If only 0 or 1 parameter is entered, prompt for the missing parameter(s)
  if(argc < 3)
    {
      printf("\nMISSING A PARAMETER. Enter both PORT and BAUD.\n\n");
      return(0);
    }

  //Check for optional "clear" parameter and set flag if found
  

  if((argc > 3) && (!strcmp(argv[3],"clear"))){ 
    cleardisplay=1;}
  if((argc > 3) && (!strcmp(argv[3],"quiet"))){
    QuietMode = true;}
    if(QuietMode == false)
    {
    printf("Crystalfontz-SR634 Display Driver (RMSoftware-2025)\n");
        if(!cleardisplay)
        {
        printf("Use CTRL+C to Quit\n\n");
        }
    }

  if(cleardisplay == true)
{

  int
    baud;
  //default the baud to 19200
  if(!strcmp(argv[2],"1200"))
    baud=1200;
  else
    if(!strcmp(argv[2],"2400"))
      baud=2400;
    else
      if(!strcmp(argv[2],"4800"))
        baud=4800;
      else
        if(!strcmp(argv[2],"9600"))
          baud=9600;
        else
          baud=19200;

  if(Serial_Init(argv[1],baud))
    {
      printf("Could not open port \"%s\" at \"%d\" baud.\n",argv[1],baud);
      return(1);
    }
  else
    if(!QuietMode){
    printf("\"%s\" opened at \"%d\" baud.\n\n",argv[1],baud);
    }

  //First turn off "scroll" and "wrap"
  SendByte(20);
  SendByte(24);

  //Uninit_Serial();
  //Position to line 4, col 1
  SendByte(17);
  SendByte(0);
  SendByte(3);
  if(cleardisplay==1)
    {
   // string s3;
    s3 = "                    ";
        //12345678901234567890
      SendString(s3.data());
    }
  else
    {
    s3 = exec("uptime");
        //12345678901234567890
      SendString(s3.data());
    }

  //Position to line 3, col 1
  SendByte(17);
  SendByte(0);
  SendByte(2);
  if(cleardisplay==1)
    {
    s2 = "                    ";
        //12345678901234567890
      SendString(s2.data());
    }
  else
    {
    s2 = "User: " + exec("whoami");
        //12345678901234567890
      SendString(s2.data());
    }

  //Position to line 2, col 1
  SendByte(17);
  SendByte(0);
  SendByte(1);
  if(cleardisplay==1)
    {
    s1 = "                    ";
        //12345678901234567890
      SendString(s1.data());
    }
  else
    {
    s1 = "Date: " + exec("date") ;
        //12345678901234567890
      SendString(s1.data());
    }

  //Position to line 1, col 1
  SendByte(17);
  SendByte(0);
  SendByte(0);
  if(cleardisplay==1)
    {
    s0 = "                    ";
        //12345678901234567890
      SendString(s0.data());
    }
  else
    {
    //s0 = "This is line 0 *****";

    s0 = "Linux Mint 22.2 x64 ";

        //12345678901234567890
      SendString(s0.data());

    } 
printf("Display Cleared.\n");
  printf("Done.\n\n");
  Uninit_Serial();
  return 0;
 }

  int
    baud;
  //default the baud to 19200
  if(!strcmp(argv[2],"1200"))
    baud=1200;
  else
    if(!strcmp(argv[2],"2400"))
      baud=2400;
    else
      if(!strcmp(argv[2],"4800"))
        baud=4800;
      else
        if(!strcmp(argv[2],"9600"))
          baud=9600;
        else
          baud=19200;

  if(Serial_Init(argv[1],baud))
    {
      printf("Could not open port \"%s\" at \"%d\" baud.\n",argv[1],baud);
      return(1);
    }
  else
    
    if(!QuietMode)
        {
        printf("\"%s\" opened at \"%d\" baud.\n\n",argv[1],baud);
        }


  //First turn off "scroll" and "wrap"
  SendByte(20);
  SendByte(24);
 

		    struct sigaction sa;
		    struct itimerval timer;

 		   sa.sa_handler = timer_handler;
 		   sigemptyset(&sa.sa_mask);
 		   sa.sa_flags = 0;
 		   sigaction(SIGALRM, &sa, NULL);

  		  timer.it_value.tv_sec = 1; // First timer trigger after 60 seconds
  		  timer.it_value.tv_usec = 0;
   		 timer.it_interval.tv_sec = 1; // Subsequent triggers every 60 seconds
  		  timer.it_interval.tv_usec = 0;

   		 setitimer(ITIMER_REAL, &timer, NULL);
  		  while (1)
			{
			pause(); // Wait for the next signal
			}
//----------------------------
        //}
	}
//------------------------------    
return 0;
}
void timer_handler(int signum) {

  //Position to line 4, col 1
  SendByte(17);
  SendByte(0);
  SendByte(3);
  if(cleardisplay==1)
    {
   // string s3;
    s3 = "                    ";
        //12345678901234567890
      SendString(s3.data());
    }
  else
    {
    s3 = exec("uptime");
        //12345678901234567890
      SendString(s3.data());
    }

  //Position to line 3, col 1
  SendByte(17);
  SendByte(0);
  SendByte(2);
  if(cleardisplay==1)
    {
    s2 = "                    ";
        //12345678901234567890
      SendString(s2.data());
    }
  else
    {
    s2 = "User: " + exec("whoami");
        //12345678901234567890
      SendString(s2.data());
    }

  //Position to line 2, col 1
  SendByte(17);
  SendByte(0);
  SendByte(1);
  if(cleardisplay==1)
    {
    s1 = "                    ";
        //12345678901234567890
      SendString(s1.data());
    }
  else
    {
    s1 = "Date: " + exec("date +%D") ;
        //12345678901234567890
      SendString(s1.data());
    }

  //Position to line 1, col 1
  SendByte(17);
  SendByte(0);
  SendByte(0);
  if(cleardisplay==1)
    {
    s0 = "                    ";
        //12345678901234567890
      SendString(s0.data());
    }
  else
    {
    //s0 = "This is line 0 *****";

    s0 = "Linux Mint 22.2 x64 ";

        //12345678901234567890
      SendString(s0.data());
return;
    }
  if(cleardisplay==1){
  Uninit_Serial();
  return ;}

  
  }
//--------------------end of main()
string exec(const char* cmd)
    {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
    }
//--------------------end of exec()
//--------------------end of timer_handler()

//============================================================================
// com port handle
int handle;

// data buffering
#define RECEIVEBUFFERSIZE 4096
ubyte SerialReceiveBuffer[RECEIVEBUFFERSIZE];
dword ReceiveBufferHead;
dword ReceiveBufferTail;
dword ReceiveBufferTailPeek;

//------------------------------------------------------------------------------
int Serial_Init(char *devname, int baud_rate)
  {
  int
    brate;
  struct
    termios term;

  //open device
  handle = open(devname, O_RDWR | O_NOCTTY | O_NONBLOCK);

  if(handle <= 0)
    {
      	printf("Serial_Init:: Open() failed\n");
	return(1);
    }

  //get baud rate constant from numeric value
  switch (baud_rate)
  {
         case 9600://added
         brate=B9600;
         break;
    case 19200:
      brate=B19200;
      break;
    case 115200:
      brate=B115200;
      break;
    default:
      printf("Serial_Init:: Invalid baud rate: %d (must be 19200 or 115200)\n", baud_rate);
      return(2);
  }
  //get device struct
  if(tcgetattr(handle, &term) != 0)
    {
    printf("Serial_Init:: tcgetattr() failed\n");
    return(3);
    }

  //input modes
  term.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|INPCK|ISTRIP|INLCR|IGNCR|ICRNL
                  |IXON|IXOFF);
  term.c_iflag |= IGNPAR;

  //output modes
  term.c_oflag &= ~(OPOST|ONLCR|OCRNL|ONOCR|ONLRET|OFILL
                  |OFDEL|NLDLY|CRDLY|TABDLY|BSDLY|VTDLY|FFDLY);

  //control modes
  term.c_cflag &= ~(CSIZE|PARENB|PARODD|HUPCL|CRTSCTS);
  term.c_cflag |= CREAD|CS8|CSTOPB|CLOCAL;

  //local modes
  term.c_lflag &= ~(ISIG|ICANON|IEXTEN|ECHO);
  term.c_lflag |= NOFLSH;

  //set baud rate
  cfsetospeed(&term, brate);
  cfsetispeed(&term, brate);

  //set new device settings
  if(tcsetattr(handle, TCSANOW, &term)  != 0)
    {
    printf("Serial_Init:: tcsetattr() failed\n");
    return(4);
    }

  ReceiveBufferHead=ReceiveBufferTail=0;

  //printf("Serial_Init:: success\n");
  return(0);
  }
//------------------------------------------------------------------------------
void Uninit_Serial()
  {
  close(handle);
  handle=0;
  }
//------------------------------------------------------------------------------
void SendByte(unsigned char datum)
  {
  dword
    bytes_written;
  bytes_written=0;

  if(handle)
    {
    if((bytes_written=write(handle, &datum, 1)) != 1)
      printf("SendByte(): system call \"write()\" return error.\n  Asked for %d bytes to be written, but %d bytes reported as written.\n",
             1,(int)bytes_written);
    }
  else
    printf("SendByte(): \"handle\" is null\n");
  }
//------------------------------------------------------------------------------
void SendData(unsigned char *data,int length)
  {
  dword
    bytes_written;
  bytes_written=0;

  if(handle)
    {
    if((bytes_written=write(handle, data, length)) != length)
      printf("SendData(): system call \"write()\" return error.\n  Asked for %d bytes to be written, but %d bytes reported as written.\n",
             length,(int)bytes_written);
    }
  else
    printf("SendData(): \"handle\" is null\n");

  }
//------------------------------------------------------------------------------
void SendString(char *data)
  {
  while(*data)
    {
    usleep(500);
    SendByte(*data++);
    }
  }
//------------------------------------------------------------------------------
//Gets incoming data and puts it into SerialReceiveBuffer[].
void Sync_Read_Buffer(void)
  {
  ubyte
    Incoming[4096];
  long
    BytesRead;

  //  COMSTAT status;
  dword
    i;

  if(!handle)
    return;

  //get data
  BytesRead = read(handle, &Incoming, 4096);
  if(0<BytesRead)
  {
  //Read the incoming ubyte, store it.
  for(i=0; i < BytesRead; i++)
    {
    SerialReceiveBuffer[ReceiveBufferHead] = Incoming[i];

    //Increment the pointer and wrap if needed.
    ReceiveBufferHead++;
    if (RECEIVEBUFFERSIZE <= ReceiveBufferHead)
      ReceiveBufferHead=0;
      }
    }
  }
/*---------------------------------------------------------------------------*/
dword BytesAvail(void)
  {
  //LocalReceiveBufferHead and return_value are a signed variables.
  int
    LocalReceiveBufferHead;
  int
    return_value;

  //Get a register copy of the head pointer, since an interrupt that
  //modifies the head pointer could screw up the value. Convert it to
  //our signed local variable.
  LocalReceiveBufferHead = ReceiveBufferHead;
  if((return_value = (LocalReceiveBufferHead - (int)ReceiveBufferTail)) < 0)
    return_value+=RECEIVEBUFFERSIZE;

  return(return_value);
  }
/*---------------------------------------------------------------------------*/
ubyte GetByte(void)
  {
  dword
    LocalReceiveBufferTail;
  dword
    LocalReceiveBufferHead;
  ubyte
    return_byte=0;

  //Get a register copy of the tail pointer for speed and size.
  LocalReceiveBufferTail=ReceiveBufferTail;

  //Get a register copy of the head pointer, since an interrupt that
  //modifies the head pointer could screw up the value.
  LocalReceiveBufferHead=ReceiveBufferHead;


  //See if there are any more bytes available.
  if(LocalReceiveBufferTail!=LocalReceiveBufferHead)
    {
    //There is at least one more ubyte.
    return_byte=SerialReceiveBuffer[LocalReceiveBufferTail];

    //Increment the pointer and wrap if needed.
    LocalReceiveBufferTail++;
    if(RECEIVEBUFFERSIZE<=LocalReceiveBufferTail)
      LocalReceiveBufferTail=0;

    //Update the real ReceiveBufferHead with our register copy. Make sure
    //the ISR does not get serviced during the transfer.
    ReceiveBufferTail=LocalReceiveBufferTail;
    }

  return(return_byte);
  }
/*---------------------------------------------------------------------------*/
dword PeekBytesAvail(void)
  {
  //LocalReceiveBufferHead and return_value are a signed variables.
  int
    LocalReceiveBufferHead;
  int
    return_value;

  //Get a register copy of the head pointer, since an interrupt that
  //modifies the head pointer could screw up the value. Convert it to
  //our signed local variable.
  LocalReceiveBufferHead=ReceiveBufferHead;
  if((return_value=(LocalReceiveBufferHead-(int)ReceiveBufferTailPeek))<0)
    return_value+=RECEIVEBUFFERSIZE;
  return(return_value);
  }
/*---------------------------------------------------------------------------*/
void Sync_Peek_Pointer(void)
  {
  ReceiveBufferTailPeek=ReceiveBufferTail;
  }
/*---------------------------------------------------------------------------*/
void AcceptPeekedData(void)
  {
  ReceiveBufferTail=ReceiveBufferTailPeek;
  }
/*---------------------------------------------------------------------------*/
ubyte PeekByte(void)
  {
  int
    LocalReceiveBufferTailPeek;
  int
    LocalReceiveBufferHead;
  ubyte return_byte=0;

  //Get a register copy of the tail pointer for speed and size.
  LocalReceiveBufferTailPeek=ReceiveBufferTailPeek;

  //Get a register copy of the head pointer, since an interrupt that
  //modifies the head pointer could screw up the value.
  LocalReceiveBufferHead=ReceiveBufferHead;

  //See if there are any more bytes available.
  if(LocalReceiveBufferTailPeek!=LocalReceiveBufferHead)
    {
    //There is at least one more ubyte.
    return_byte=SerialReceiveBuffer[LocalReceiveBufferTailPeek];

    //Increment the pointer and wrap if needed.
    LocalReceiveBufferTailPeek++;
    if(RECEIVEBUFFERSIZE<=LocalReceiveBufferTailPeek)
      LocalReceiveBufferTailPeek=0;

    //Update the real ReceiveBufferHead with our register copy. Make sure
    //the ISR does not get serviced during the transfer.
    ReceiveBufferTailPeek=LocalReceiveBufferTailPeek;
    }
  return(return_byte);
  }
//============================================================================
//====================================================================================


//    return 0;
//}
