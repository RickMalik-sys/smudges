#include <iostream>
#include <string> // For std::string
#include <vector> // For std::vector (optional, but good for argument storage)
#include <errno.h>
#include <fstream>

using namespace std;

void printHelpMessage() {
    cout << "\nPurpose: readfile is used as a command line interface to output file contents.\nIt can be used to read a file to the terminal stdout, or into another command, or piped to a new file.\nFor example: readfile -f myfile.txt >> newfile.txt\n";
    cout << "Usage: myprogram [OPTIONS]" << endl;
    cout << "Options:" << std::endl;
    cout << "  --help, -h    Display this help message" << endl;
    cout << "  --version, -v Display program version" << endl;
    cout << "  --input, -f FILENAME  Specify an input file to open." << endl;
    // Add more options and descriptions as needed
}

int main(int argc, char* argv[]) {
    // Loop through the command-line arguments, starting from argv[1]
    // argv[0] is always the program name itself
string inputFileName;
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];

        if (arg == "--help" || arg == "-h") {
            printHelpMessage();
            return 0; // Exit after displaying help
        }
        // Add more argument handling here
        else if (arg == "--version" || arg == "-v") {
            cout << "ReadFile Version 1.0" << endl;
            return 0;
        }
        else if (arg == "--input" || arg == "-f") {
            if (i + 1 < argc) { // Check if there's a next argument for the filename
                inputFileName = argv[++i];
                //cout << inputFileName << endl <<endl;
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
    //cout << "Running main program logic..." << endl;
    // Your main program logic goes here
if(inputFileName == "")
    {cout << "Error: File name required.\n"; return 0;}
    else
    {
    fstream file(inputFileName, ios::in | ios::out);// | ios::app);
    if(file.is_open())
        {
        string data;
        while (getline(file,data))
            {
            cout << data << endl;
            }
        file.close();
        }
    else{cerr <<"error opening file" <<endl; return 0;}

    }

return 0;
}
