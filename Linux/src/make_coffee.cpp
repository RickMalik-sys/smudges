//----------------------------------------------------
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
using namespace std;
using std::locale; //::global(std::locale(""));
int main()
{
int i = 10;
cout << "Set timer (seconds).";
cin >> i;
string s = "x";
cout << "Making coffee. Please standby.\n";
sleep(i);
system("aplay -q /home/rick/Music/Sounds/tada.wav");
/*cout << "Cream and sugar?";//add 15 seconds
cin >> s;
if(s=="y")
    {
    cout << "okay\n";
    sleep(3);
    cout << "Pouring cream\n";
    sleep(3);
    cout << "Scooping sugar\n";
    sleep(3);
    cout << "clink clink clink clink clink\n";
    sleep(6);
    }
    else
    {
    cout << "black then.\n";
    }*/
std::cout << "Done.\n";

return 0;
}
