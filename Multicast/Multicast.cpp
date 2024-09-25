#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
//luodaan luokka
class Multicast 
{
    //määritetään private muuttuja ja taulukko
private:
    string userId;
    vector<string> passwords;
    //luokan konstruktori
public:
    Multicast() {}
    //funktio mikä ei palauta mitään
    void MultiCommand(const string& command)
    {
        //strinstram olio i saa arvonsa funktiosta
        stringstream i(command);
        string com;
        //tallennetaan arvo muuttujaan
        i >> com;
        //ehto jos käyttäjä päättää syöttää USER
        if (com == "USER")
        {
            //luodaan muuttuja
            string coms;
            i >> coms;
            //totuusarvo joka saa falsen arvoksi
            bool exists = false;
            //luodaan iteraatio tauliukosta
            //tarkistetaan taulukko
            for (vector<string>::iterator it = passwords.begin(); it != passwords.end(); it++)
            {
                //ehto jos arvo löytyy taulukosta, suoritus päättyy
                if (*it == coms)
                {
                    exists = true;
                    break;
                }
            }
            //tulostetaan virhe ilmoitus jos exists arvo on tosi
            if (exists)
            {
                cout << "User ID cannot be same as password" << endl;
            }
            //muussa tapauksessa jos arvo false asetetaan arvo userId
            else
            {
                userId = coms;
                cout << "User ID set to: '" << userId << "'" << endl;
            }
        }
        //jos käyttäjä syöttää arvon PASSWORD
        else if (com == "PASSWORD")
        {
            //talletetaan arvo muuttujaan
            string password;
            i >> password;
            //tarkistetaan vastaako salasana userID
            if (password == userId)
            {
                cout << "Password cannot be the same as User ID" << endl;
            }
            else
            {
                // luodaan totuusarcvo muuttuja joka on false arcvoinen
                bool exists = false;
                //luodaan iteraattori
                //käydään koko taulukko lävitse
                for (vector<string>::iterator it = passwords.begin(); it != passwords.end(); it++)
                {
                    //ehto jos arvo löytyy taulukosta, suoritus päättyy 
                    if (*it == password)
                    {
                        exists = true;
                        break;
                    }
				}
                //tulostetaan virhe ilmoitus jos exists arvo on tosi
                if (exists)
                {
                    cout << "Try other Password" << endl;
                }
                //muussa tapauksessa talletetaan arvo taulukkoon
                else
                {
                passwords.push_back(password);
                cout << "Password added to list" << endl;
                }
            }
        }
        //jos käyttäjä syöttää SEND
        else if (com == "SEND")
        {
            //luodaan muuttujat
            string password, message;
            //talletetaan arvo muuttujaan
            i >> password;
            //lukee merkkijonon ja tallettaa sen muutujaan
            getline(i >> ws, message);
            //luodaam iteraattori
            // luodaan totuusarvo joka saa arvoksi false
            bool exists = false;
            for (vector<string>::iterator it = passwords.begin(); it != passwords.end(); it++)
            {
                //ehto jos arvo löytyy taulukosta, tulostetaan viesti ja suoritus päättyy
                if (*it == password)
                {
                    exists = true;
                    cout << "ID '" << userId << "': " << message << endl;
                    break;
                }
            }
            //tulostetaan virhe
            if (!exists)
            {
                cout << "Invalid password" << endl;
            }
        }
        //muussa tapauksessa tulostetaan virhe
        else
        {
            cout << "Unknown command" << endl;
        }
    }
};
