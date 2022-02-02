// basic-calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "calculator.h"

int main()
{
    /*All variables to be used in this program*/
    char input = ' ', sign = ' ';
    char inparr[7] = { 'a', 's', 'm', 'd', 'e', 'x', 'q' };
    string sciArr[7] = { "sin","cos","tan","cot","sec","csc","bk"};

    map <char, string> operationsNameMap = {
        {'a', "Addition"},
        {'s', "Subtraction"},
        {'m', "Multiplcation"},
        {'d', "Division"},
        {'e', "Exponent"},
        {'x', "Scientific Menu"},
        {'q', "Quit"}
    };

    map <string, string> sciOperationsNameMap = {
        {"sin", "sine"},
        {"cos", "cosine"},
        {"tan", "tangent"},
        {"cot", "cotangent"},
        {"sec", "secant"},
        {"csc", "cosecant"}
    };

    map <char, char> operationsSignMap = {
        {'a', '+'},
        {'s', '-'},
        {'m', 'x'},
        {'d', '/'},
        {'e', '^'}
    };

    bool validSci = false;
    int validinp = -1, sizeArr = -1, sizeSciArr = -1;
    double val1 = -9999, val2 = -9999, output = -9999;
    string subMenu = "", sciMenuInput = "";

    sizeArr = sizeof(inparr) / sizeof(inparr[0]);
    sizeSciArr = sizeof(sciArr) / sizeof(sciArr[0]);

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

        if (input == 'x')
        {
            while (sciMenuInput != "bk")
            {
                while (!validSci)
                {
                    printScientificMenu();
                    
                    cin >> sciMenuInput;
                    transform(sciMenuInput.begin(), sciMenuInput.end(), sciMenuInput.begin(), ::tolower);

                    validSci = validateSciInput(sciMenuInput, sciArr, sizeSciArr);
                    if (!validSci) cout << "\n\t\tWrong Input. Please try again." << endl;
                }
                subMenu = sciOperationsNameMap[sciMenuInput];

                preprocessInput(val1, val2, input, sciMenuInput, sign);

                output = calculateEngine(input, val1, val2, sciMenuInput);

                displayOutput(subMenu, input, output, val1, val2);

                validSci = false;
                sciMenuInput = "";
            }
        }
        else
        {
            subMenu = operationsNameMap[input];
            sign = operationsSignMap[input];
            preprocessInput(val1, val2, input, subMenu, sign);

            output = calculateEngine(input, val1, val2, sciMenuInput);

            displayOutput(subMenu, sign, output, val1, val2);
        }
        
    }
    return 0;
}




