#include <iostream>
#include <string> // For std::string
#include <vector> // For std::vector (optional, but good for argument storage)

void printHelpMessage() {
    std::cout << "Usage: myprogram [OPTIONS]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  --help, -h    Display this help message" << std::endl;
    std::cout << "  --version, -v Display program version" << std::endl;
    std::cout << "  --input FILE  Specify an input file" << std::endl;
    // Add more options and descriptions as needed
}

int main(int argc, char* argv[]) {
    // Loop through the command-line arguments, starting from argv[1]
    // argv[0] is always the program name itself
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "--help" || arg == "-h") {
            printHelpMessage();
            return 0; // Exit after displaying help
        }
        // Add more argument handling here
        else if (arg == "--version" || arg == "-v") {
            std::cout << "My Program Version 1.0" << std::endl;
            return 0;
        }
        else if (arg == "--input") {
            if (i + 1 < argc) { // Check if there's a next argument for the filename
                std::string inputFile = argv[++i];
                std::cout << "Input file specified: " << inputFile << std::endl;
            } else {
                std::cerr << "Error: --input requires a filename." << std::endl;
                return 1; // Indicate error
            }
        }
        else {
            std::cerr << "Unknown argument: " << arg << std::endl;
            std::cerr << "Use --help for usage information." << std::endl;
            return 1; // Indicate error
        }
    }

    // If no specific arguments are handled, or after handling them
    std::cout << "Running main program logic..." << std::endl;
    // Your main program logic goes here

    return 0;

}
