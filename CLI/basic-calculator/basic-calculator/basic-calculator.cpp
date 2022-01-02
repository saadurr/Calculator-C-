// basic-calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "calculator.h"

int main()
{
    /*All variables to be used in this program*/
    char input = ' ';
    char inparr[7] = { 'a', 's', 'm', 'd', 'l', 'o', 'q' };
    int validinp = -1;

    printStartWindow();
    clearScreen();

    while (input != 'q')
    {
        printMenu();
        cin >> input;
        input = tolower(input);

        validinp = validateInput(input, inparr);
        //this function shall return an integer based on whatever was entered
        

        
    }
    return 0;
}




