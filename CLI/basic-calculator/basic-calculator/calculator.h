#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>

using namespace std;
/*All functions to be used in this program*/

void clearScreen()
{
    cout << "\n\n\n\t\tPress any key to continue..." << endl;
    cin.get();
    system("CLS");
}

void printStartWindow()
{
    cout << "\n\t\tWelcome to Calculator App" << endl;
}

void printMenu()
{
    cout << "Menu" << endl;
}

int validateInput(char testch, char chararr[])
{

    return false;

}