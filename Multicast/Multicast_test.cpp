#include <iostream>
#include <string>
#include "Multicast.cpp"
using namespace std;
//p��ohjelma
int main() {
    //luodaan olio
    Multicast chat;
    cout << "-- Input 'QUIT' to exit --" << endl;
    cout << "Enter command: 'USER', 'PASSWORD', 'SEND'"  << endl;
    //luodaan muuttuja
    string command;
    //ohjelma jatkaa eloaan kunnes k�ytt�j� p��tt�� lopettaa
    while (true)
    {
        cout << "> ";
        //arvo sy�tet��n muuttujaan
        getline(cin, command);
        //jos k�ytt�j� sy�tt�� QUIT, ohjelman suoritus p��ttyy
        if (command == "QUIT")
        {
            break;
        }
        //arvo joka tallentuu olioon mit� k�ytet��n funktion konstruktorissa
        chat.MultiCommand(command);
    }
    return 0;
}