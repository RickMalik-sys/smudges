/////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>                                                                        //
#include <stdio.h>                                                                         //
#include <cstring>                                                                         //
#include <termios.h>                                                                       //
#include <unistd.h>                                                                        //
#include <term.h>                                                                          //
#include <conio.h>                                                                         //
/////////////////////////////////////////////////////////////////////////////////////////////

#include "borders.h"
using namespace std;


//------------------------------------------------------------------
// Custom getch() using termios.h  (if conio.h is not available on your system)
char getch() {  
    struct termios old_attr, new_attr;  
    char ch;  
 
    // Get current terminal attributes  
    tcgetattr(STDIN_FILENO, &old_attr);  
    new_attr = old_attr;  
 
    // Disable canonical mode and echo  

    // Disable canonical mode and echo  
    new_attr.c_lflag &= ~(ICANON | ECHO);  // ICANON = line buffering; ECHO = echo input  
    new_attr.c_cc[VMIN] = 1;               // Read at least 1 character  
    new_attr.c_cc[VTIME] = 0;              // No timeout  
 
    // Apply new settings  
    tcsetattr(STDIN_FILENO, TCSANOW, &new_attr);  
 
    // Read 1 character  
    read(STDIN_FILENO, &ch, 1);  
 
    // Restore original settings  
    tcsetattr(STDIN_FILENO, TCSANOW, &old_attr);  
 
    return ch;  
}
//---------------------------------------------------------------------------------------
void printHelpMessage() {
    cout << "Usage: borders [OPTIONS]" << endl;
    cout << "Options:" << endl;
    cout << "  -h  --help          Display this help message" << endl;
    cout << "  -v  --version       Display program version" << endl;
    cout << "  -f  --input FILE    Specify an input file" << endl;
    // Add more options and descriptions as needed
}

int main(int argc, char* argv[]) {
    // Loop through the command-line arguments, starting from argv[1]
    // argv[0] is always the program name itself
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];

        if (arg == "--help" || arg == "-h") {
            printHelpMessage();
            return 0; // Exit after displaying help
        }
        // Add more argument handling here
        else if (arg == "--version" || arg == "-v") {
            cout << "Borders Test Program Version 1.0" << endl;
            return 0;
        }
        else if (arg == "--input" || arg == "-f") {
            if (i + 1 < argc) { // Check if there's a next argument for the filename
                string inputFile = argv[++i];
                cout << "Input file specified: " << inputFile << endl;
            } else {
                cerr << "Error: --input requires a filename." << endl;
                return 1; // Indicate error
            }
        }
        else {
            cerr << "Unknown argument: " << arg << endl;
            cerr << "Use --help for usage information." << endl;
            return 1; // Indicate error
        }
    }

    // If no specific arguments are handled, or after handling them
    // Your main program logic goes here
//----------------------------------------------------------------------
Borders borders;

    system("clear");//clear screen
        int size = 3;
        string name = "Borders Test Program, version 1.0", cpr = "(c) 2025", author = "R. Malik";
        string titles [size] = {"" + name, "Copyright: " + cpr, "Author: " + author};
        int rows = 80;

        cout << borders.DOUBLE_DOWN_RIGHT;

        for (int i = 0; i < rows; i++)
            {
            cout << borders.DOUBLE_HORIZONTAL;
            }

        cout << borders.DOUBLE_DOWN_LEFT << "\n"; 
        //cout << endl;

        for (int i = 0; i < size; i++)
            {
            cout << borders.DOUBLE_VERTICAL << titles[i];
            double length = titles[i].length() ;

            for(int j = 0; j < (rows-length); j++)
                {
                cout << " ";
                }

            cout << borders.DOUBLE_VERTICAL << "\n";
            }

        cout << borders.DOUBLE_UP_RIGHT;

        for (int i = 0; i < rows; i++)
            {
            cout << borders.DOUBLE_HORIZONTAL;
            }

        cout << borders.DOUBLE_UP_LEFT << "\n";
        //cout <<  "\n";
//-------------------------------------------main program functions go here----------------------


//-------------------------------------------exit with 'q'---------------------------------------
   char c;  
   cout << "Press 'q' to quit: ";  
 
    while ((c = getch()) != 'q')
        {  
        printf("\nYou pressed: %c (ASCII: %d)", c, c);  
        }  
 
    printf("\nExiting...\n");   
//---------------------------------------------------------------------
    return 0;
}

