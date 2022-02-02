// basic-calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "calculator.h"

int main()
{
    /*All variables to be used in this program*/
    char input = ' ', sign = ' ';
    char inparr[7] = { 'a', 's', 'm', 'd', 'e', 'x', 'q' };
    map <char, string> operationsNameMap = {
        {'a', "Addition"},
        {'s', "Subtraction"},
        {'m', "Multiplcation"},
        {'d', "Division"},
        {'e', "Exponent"},
        {'x', "Scientific Menu"},
        {'q', "Quit"}
    };
    map <char, char> operationsSignMap = {
        {'a', '+'},
        {'s', '-'},
        {'m', 'x'},
        {'d', '/'},
        {'e', '^'}
    };
    int validinp = -1, sizeArr = -1;
    double val1 = -9999, val2 = -9999, output = -9999;
    string subMenu = "";

    sizeArr = sizeof(inparr) / sizeof(inparr[0]);

    printStartWindow();
    clearScreen();

    while (input != 'q')
    {
        printMenu();
        cin >> input;
        input = tolower(input);

        validinp = validateInput(input, inparr, sizeArr);
        
        if (!validinp)
        {
            cout << "Wrong Input!" << endl;
            waitForKey();
            continue;
        }
        else if (input == 'q')
        {
            quitApplication();
            break;
        }

        subMenu = operationsNameMap[input];
        sign = operationsSignMap[input];
        preprocessInput(val1, val2, input, subMenu, sign);

        output = calculateEngine(input, val1, val2);

        displayOutput(subMenu, sign, output, val1, val2);
        
    }
    return 0;
}




