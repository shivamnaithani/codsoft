#include <iostream>
using namespace std;

int main()
{
    // Declare variables to store the numbers and the operation
    double num1, num2;
    char op;

    // Prompt the user to enter the first number
    cout << "Enter the first number: ";
    cin >> num1;

    // Prompt the user to enter the second number
    cout << "Enter the second number: ";
    cin >> num2;

    // Prompt the user to choose an operation
    cout << "Choose an operation (+, -, *, /): ";
    cin >> op;

    // Perform the operation and display the result
    switch (op)
    {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            // Check if the second number is zero
            if (num2 == 0)
            {
                // Display an error message
                cout << "Cannot divide by zero" << endl;
            }
            else
            {
                // Perform the division and display the result
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            }
            break;
        default:
            // Display an error message for invalid operation
            cout << "Invalid operation" << endl;
    }

    return 0;
}
