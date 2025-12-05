//----------------------------------------------------------------
#include <vector>
#include <stack>
#include <iostream>
#include <errno.h>
#include <string> // For std::string
using namespace std;
//----------------------------------------------------------------
class CalculatorEngine
{
  public:
    enum binaryOperator { PLUS, MINUS, TIMES, DIVIDE, CLEAR };
    int  currentMemory ()                { return data.top(); }
    void pushOperand   (int value)       { data.push (value); }
    void doOperator    (binaryOperator);

  protected:
    stack< int, vector<int,allocator<int> > > data;
};//end class decl (CalculatorEngine)
//------------------------------------------------------------------
void CalculatorEngine::doOperator (binaryOperator theOp)
{
    float right = data.top();
    data.pop();
    float left = data.top();
    data.pop();
    switch (theOp)
    {
        case PLUS:   data.push(left + right); break;
        case MINUS:  data.push(left - right); break;
        case TIMES:  data.push(left * right); break;
        case DIVIDE: data.push(left / right); break;
	    case CLEAR: data.push(left = 0);data.push(right = 0);break;
    }
}//end class inplemtation (CalculatorEngine)
//------------------------------------------------------------------
    //std::string inputFormula;
void printHelpMessage()
{
    std::cout << "Usage: calcutate [OPTIONS]\n";
    std::cout << "Options:\n";
    std::cout << "  --help, -h    Display this help message\n";
    std::cout << "  --version, -v Display version info\n";
    std::cout << "  --input FORMULA  Specify a properly formatted math formula\n";
    cout << "For more information, visit https://https://github.com/RickMalik-sys/smudges\n";
    // Add more options and descriptions as needed
}//end --help msgs
//-----------------------------------------------------------------
int main(int argc, char* argv[])
{
    // Loop through the command-line arguments, starting from argv[1]
    // argv[0] is always the program name itself
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];

        if (arg == "--help" || arg == "-h") {
            printHelpMessage();
            return 0; // Exit after displaying help
        }
        // Add more argument handling here
        else if (arg == "--version" || arg == "-v") {
            std::cout << "Version 1.0.0.0 (c)2025 RMSoftware" << std::endl;
            return 0;
        }
        else if (arg == "--input") {
            if (i + 1 < argc) { // Check if there's a next argument for the filename
                std::string inputFormula = argv[++i];
                std::cout << "Entered math formula, improperly formatted. " << inputFormula << std::endl;
            } else {
                std::cerr << "Error: --input requires a formula." << std::endl;
                return 1; // Indicate error
            }
        }
        else {
            std::cerr << "Unknown argument: " << arg << std::endl;
            std::cerr << "Use --help for usage information." << std::endl;
            return 1; // Indicate error
        }
    }//end for(loop) 
    // meatgrinder
    {
    cout << "Calculator program\n" << endl;
    cout << "Enter an expression ending with = for result. For example 2+2+= or 2+5*3/=c\nEnter c to clear. Enter q to quit.\n\n";
    float intval;
    CalculatorEngine calc;
    char c;
    char x = 'q';
    while (cin >> c)
    if(c == 'q')
        {
        fprintf(stderr, "Program complete.\n");
        exit(EXIT_FAILURE);
        }//end if    
    else{
        switch (c)
           {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                {
                cin.putback(c);
                cin >> intval;
                calc.pushOperand(intval);
                break;
                }//end cases
		    case 'c': calc.doOperator(CalculatorEngine::CLEAR); break;
            case '+': calc.doOperator(CalculatorEngine::PLUS); break;
            case '-': calc.doOperator(CalculatorEngine::MINUS); break;
            case '*': calc.doOperator(CalculatorEngine::TIMES); break;
            case '/': calc.doOperator(CalculatorEngine::DIVIDE); break;
            case '=': cout << "result = " << calc.currentMemory() << endl;break;
	        default:
                {
                fprintf(stderr, "Not a valid formula.\n" );
                exit(EXIT_FAILURE);
                }//end default
            }//end switch
        }//end else
    }//end meatgrinder
}//end main
//--------------------------------------------------------------

