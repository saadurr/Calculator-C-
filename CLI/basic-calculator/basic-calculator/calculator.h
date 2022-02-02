#pragma once
#include <iostream>
#include <algorithm>
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

void printScientificMenu()
{
    system("CLS");

    cout << "\n\t\tCalculator App" << endl;
    cout << "\n\t\tScientific Menu" << endl;
    cout << "\n\n\tSelect any of the operation below:" << endl;
    cout << "\tsin. Sine" << endl;
    cout << "\tcos. Cosine" << endl;
    cout << "\ttan. Tangent" << endl;
    cout << "\tcot. Cotangent" << endl;
    cout << "\tsec. Secant" << endl;
    cout << "\txcsc. Cosecant" << endl;
    cout << "\n\tbk. Go Back..." << endl;
}

void printScientificSubmenu(string menuName)
{
    system("CLS");
    cout << "\n\t\tCalculator App - Scientific Operations" << endl;
    cout << "\n\n\tYou have selected " << menuName << "." << endl;
    cout << "\tPlease Enter Operand for " << menuName << ":" << endl;
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
    if (inp != 'x')
    {
        printSubmenu(menu, sign);

        cin >> val1;

        cout << "\n\tEnter second operand for " << menu << ":" << endl;

        cin >> val2;
    }
    else
    {
        printScientificSubmenu(menu);
        cin >> val1;
    }



}

bool validateSciInput(string testInp, string validArr[], int sizeArr)
{
    for (int i = 0; i < sizeArr; i++)
    {
        if (testInp == validArr[i])
            return true;
    }
    return false;
}


void displayOutput(string menuName, char sign, double output, double val1, double val2)
{
    clearScreen();

    cout << "\n\t\t Calculator App - Output Screen for " << menuName << " Result" << endl;

    if (sign == 'x')
    {
        cout << "\n\n\t " << menuName << " of " << val1 << " is " << output << endl;
    }
    else
    {
        cout << "\n\n\t " << val1 << " " << sign << " " << val2 << " = " << output << endl;
    }

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

//Scientific Functions
template <typename T>
void calcSin(T val, T& result)
{
    result = sin(val);
}

template <typename T>
void calcCos(T val, T& result)
{
    result = cos(val);
}

template <typename T>
void calcTan(T val, T& result)
{
    result = tan(val);
}

template <typename T>
void calcCot(T val, T& result)
{
    calcTan(val, result);
    result = 1 / result;
}

template <typename T>
void calcSec(T val, T& result)
{
    calcCos(val, result);
    result = 1 / result;
}

template <typename T>
void calcCsc(T val, T& result)
{
    calcSin(val, result);
    result = 1 / result;
}

template <typename T>
T calculateEngine(char operation, T val1, T val2, string sciOp)
{
    T result = 0.00;
    if (operation == 'x')
    {
        if (sciOp == "sin") calcSin(val1, result);
        else if (sciOp == "cos") calcCos(val1, result);
        else if (sciOp == "tan") calcTan(val1, result);
        else if (sciOp == "cot") calcCot(val1, result);
        else if (sciOp == "sec") calcSec(val1, result);
        else if (sciOp == "csc") calcCsc(val1, result);
    }
    else //non-scientific operations
    {
        if (operation == 'a') addition(val1, val2, result);
        else if (operation == 's') subtraction(val1, val2, result);
        else if (operation == 'm') multiplication(val1, val2, result);
        else if (operation == 'd') division(val1, val2, result);
        else if (operation == 'e') exponent(val1, val2, result);
    }

    return result;
}
