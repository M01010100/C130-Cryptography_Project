#pragma once
#include <string>
#include <iostream> 
#include <string>

using namespace std;
class machine
{
public:
    void setUser(string user);
    string getUser();
    void setShift(int shift);
    int getShift();
    void Ceaser(string user);
    void subset(string user);
    void csdecrypt(string user);
    void subdecrypt(string user);
    void textIn();
    void shiftIn();
    void initial();
    void menu();
private:
    string usertxt="";
    string alpha="abcdefghijklmnopqrstuvwxyz";
    string subalpha="qwertyuiopasdfghjklzxcvbnm";
    string encrypt;
    int shift=0;
    int index=0;
    int subsetIn=0;
    int ceaserIndex=0;
};