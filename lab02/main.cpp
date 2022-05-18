#include <iostream>
#include <cmath>

using namespace std;

struct Calculator
{
    int firstNum, secondNum, operation;

    Calculator(int firstNum, int secondNum, int operation)
    {
        this->firstNum = firstNum;
        this->secondNum = secondNum;
        this->operation = operation;
    }

    enum Operations
    {
        Add = 1,
        Subtract = 2,
        Divide = 3,
        Multiply = 4,
        Power = 5,
        Sqrt = 6,
        Log = 7,
        Sin = 8,
        Cos = 9,
        Tan = 10,
    };

    // Calculate the result of the operation
    double calculate()
    {
        switch (operation)
        {
        case Operations::Add:
            return firstNum + secondNum;
        case Operations::Subtract:
            return firstNum - secondNum;
        case Operations::Multiply:
            return firstNum * secondNum;
        case Operations::Divide:
            return (double)firstNum / secondNum;
        case Operations::Power:
            return pow(firstNum, secondNum);
        case Operations::Sqrt:
            return sqrt(firstNum);
        case Operations::Log:
            return log(firstNum);
        case Operations::Sin:
            return sin(firstNum);
        case Operations::Cos:
            return cos(firstNum);
        case Operations::Tan:
            return tan(firstNum);
        default:
            return -1;
        }
    }
};

int main()
{
    int firstArg, secondArg, operation;
    bool run = true;
    // Run the program until the user enters cancels
    while (run)
    {
        cout << "Enter operation (1-add, 2-subtract, 3-multiply, 4-divide, 5-power, 6-sqrt, 7-log, 8-sin, 9-cos, 10-tan): ";
        // ignore if not a number or not within range
        while (!(cin >> operation) || operation < 1 || operation > 10)
        {
            cin.clear();
            cout << "Invalid input. Please enter a number between 1 and 10: ";
        }

        cout << "Enter first number: ";
        // ignore if not a number
        while (!(cin >> firstArg))
        {
            cin.clear();
            cout << "Invalid input. Please enter a number: ";
        }
        // don't require second number if square root
        if (operation < 6)
        {
            cout << "Enter second number: ";
            // ignore if not a number
            while (!(cin >> secondArg))
            {
                cin.clear();
                cout << "Invalid input. Please enter a number: ";
            }
        }
        else
        {
            secondArg = 0;
        }
        // create calculator object
        Calculator calc(firstArg, secondArg, operation);
        // calculate result
        cout << calc.calculate() << endl;

        // ask if user wants to continue
        while (true)
        {
            cout << "Do you want to perform another operation? (y/n): ";
            char input;
            cin >> input;
            if (input == 'y' || input == 'Y')
            {
                break;
            }
            else if (input == 'n' || input == 'N')
            {
                run = false;
                break;
            }
            else
            {
                cout << "Invalid input. Try again." << endl;
            }
        }
    }
    cout << "Goodbye!" << endl;
}