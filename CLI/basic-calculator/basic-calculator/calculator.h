#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <map>

using namespace std;
/*All functions to be used in this program*/

void waitForKey()
{
    cout << "\n\n\n\t\tPress any key to continue..." << endl;
    cin.get();
}
void clearScreen()
{
    waitForKey();
    system("CLS");
}

void printStartWindow()
{
    cout << "\n\t\tWelcome to Calculator App" << endl;
}

void printMenu()
{
    system("CLS");

    cout << "\n\t\tCalculator App" << endl;
    cout << "\n\t\tMain Menu" << endl;
    cout << "\n\n\tSelect any of the operation below:" << endl;
    cout << "\ta. Addition" << endl;
    cout << "\ts. Subtraction" << endl;
    cout << "\tm. Multiplication" << endl;
    cout << "\td. Division" << endl;
    cout << "\te. Exponent" << endl;
    cout << "\tx. Scientific Menu" << endl;
    cout << "\n\tq. Quit" << endl;
}

void printSubmenu(string menuName, char sign)
{
    system("CLS");
    cout << "\n\t\tCalculator App" << endl;
    cout << "\n\n\tYou have selected " << menuName << "." << endl;
    cout << "\n\n\t\tnum1 " << sign << " num2" << endl;
    cout << "\tPlease Enter First Operand for " << menuName << ":" << endl;
}

int validateInput(char testch, char chararr[], int sizeArr)
{

    for (int i = 0; i < sizeArr; i++)
    {
        if (testch == chararr[i])
        {
            return true;
        }
    }
    return false;

}

void quitApplication()
{
    system("CLS");
    cout << "\n\t\tQuitting Calculator App" << endl;
    cout << "\n\n\n\t\tPress any key to continue..." << endl;
    cin.get();
}

void preprocessInput(double& val1, double& val2, char inp, string menu, char sign)
{

    printSubmenu(menu, sign);

    cin >> val1;

    cout << "\n\tEnter second operand for " << menu << ":" << endl;
    
    cin >> val2;



}


void displayOutput(string menuName, char sign, double output, double val1, double val2)
{
    clearScreen();

    cout << "\n\t\t Calculator App - Output Screen for " << menuName << " Result" << endl;

    cout << "\n\n\t " << val1 << " " << sign << " " << val2 << " = " << output << endl;

    waitForKey();
}

template <typename T>
void addition(T val1, T val2, T& result)
{
    result = val1 + val2;
}

template <typename T>
void subtraction(T val1, T val2, T& result)
{
    result = val1 - val2;
}

template <typename T>
void multiplication(T val1, T val2, T& result)
{
    result = val1 * val2;
}

template <typename T>
void division(T val1, T val2, T& result)
{
    result = val1 / val2;
}

template <typename T>
void exponent(T val1, T val2, T& result)
{
    result = pow(val1, val2);
}


template <typename T>
T calculateEngine(char operation, T val1, T val2)
{
    T result = 0.00;

    if (operation == 'a') addition(val1, val2, result);
    else if (operation == 's') subtraction(val1, val2, result);
    else if (operation == 'm') multiplication(val1, val2, result);
    else if (operation == 'd') division(val1, val2, result);
    else if (operation == 'e') exponent(val1, val2, result);

    return result;
}
