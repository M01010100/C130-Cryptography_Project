#include "crypto.h"
#include <iostream>
#include <string>
#include <array>

using namespace std;

void machine::setUser(string user)
{
    usertxt=user;
}
string machine::getUser()
{
    return usertxt;
}
void machine::setShift(int shift)
{
    shift=shift;
}
int machine::getShift()
{
    return shift;
}
void machine::Ceaser(string user)
{
   array<string, 50>encrypt{};
   for(int j=0; j < user.length(); j++)
   {
        for(int i=0; i < 27; i++)
        {
            if (user[j]==alpha[i])
            index = i;
        }
        ceaserIndex = (index + shift) % 27;
        encrypt[j]=alpha[ceaserIndex];
        cout << encrypt[j];
   }
}
void machine::subset(string user)
{
    array<string, 50>encrypt{};
    for(int j=0; j < usertxt.length(); j++)
    {
        for(int i=0; i < 27; i++)
        {
            if (user[j]==alpha[i])
            index = i;
        }
        subsetIn = index;
        encrypt[j]=alpha[index];
        cout << encrypt[j];
    }
}
void machine::csdecrypt(string user)
{
    array<string, 50>encrypt{};
    shift = 8;
    for(int j=0; j < usertxt.length(); j++)
    {
        for(int i=0; i < 27; i++)
        {
            if (user[j]==alpha[i])
            index = i;
        }
        ceaserIndex = (index + (27 - shift)) % 27;
        encrypt[j]=alpha[ceaserIndex];
        cout << encrypt[j];
    }
}
void machine::subdecrypt(string user)
{
    array<string, 50>encrypt{};
    shift = 8;
    for(int j=0; j < usertxt.length(); j++)
    {
        for(int i=0; i < 27; i++)
        {
            if (user[j]==alpha[i])
            index = i;
        }
        subsetIn = index;
        encrypt[j]=subalpha[index];
        cout << encrypt[j];
    }
}
void machine::textIn()
{
    cout << "Please enter your message: \n";
    cin.ignore();
    getline(cin, usertxt);
}
void machine::shiftIn()
{
    cout << "\nPlease enter your shift: \n";
    cin >> shift;
    cout << "\nYour New Message: \n";
}
void machine::initial()
{
    int c = 0;
    while (c <= 64)
    {
        cout << "*";
        c++;
    }
    c = 0;
    cout << endl;
    cout <<"*           Machine for Encryption and Decryption               *" << endl;
    cout <<"*   A Ceaser Cipher requires both a Messeage and a shift value  *" << endl;
    cout <<"*                      Enter -1 to quit                         *" << endl;
    while (c <= 64)
    {
        cout << "*";
        c++;
    }
    menu();
}

void machine::menu()
{
    int userin;
    cout << "\nOPTIONS: " << endl;
    cout << "\n\t1. Ceaser Cipher Encryption \n" << endl;
    cout << "\n\t2. Ceaser Cipher Decryption \n" << endl;
    cout << "\n\t3. Substitution Cipher Encryption \n" << endl;
    cout << "\n\t4. Substitution Cipher Decryption \n" << endl;
    cout << "\n\t5. Decryption for both Ciphers" << endl;
    cin >> userin;
    switch(userin)
    {
        case 1:
            textIn();
            shiftIn();
            Ceaser(usertxt);
            cout << endl;
            menu();
            break;
        case 2:
            textIn();
            shiftIn();
            csdecrypt(usertxt);
            cout << endl;
            menu();
            break;
        case 3:
            textIn();
            cout << "\nYour New Message: " << endl;
            subset(usertxt);
            cout << endl;
            menu();
            break;
        case 4:
            textIn();
            cout << "\nYour New Message: " << endl;
            subdecrypt(usertxt);
            cout << endl;
            menu();
            break;
        case 5:
            cout << "If substitution cipher, enter 0 for shift" << endl;
            textIn();
            cout << "\nCeaser Decryption: " << endl;
            for(shift = 0; shift <= 26; shift++)
            {
                cout << "Shift: " << shift << "=";
                csdecrypt(usertxt);
                cout << endl;
            }
            cout << endl;
            cout << "\nSubstitution Decryption: " << endl;
            subdecrypt(usertxt);
            cout << endl;
            menu();
            break;
        case -1:
            break;
        default:
            cout << "-1 to quit" << endl;
            break;
    }
}