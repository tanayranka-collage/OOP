#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int choice;
    double a, b;

    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Sin\n";
    cout << "6. Cos\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "Result = " << a + b;
            break;

        case 2:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "Result = " << a - b;
            break;

        case 3:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "Result = " << a * b;
            break;

        case 4:
            cout << "Enter two numbers: ";
            cin >> a >> b;
            if (b != 0)
                cout << "Result = " << a / b;
            else
                cout << "Division by zero not allowed.";
            break;

        case 5:
            cout << "Enter angle in radians: ";
            cin >> a;
            cout << "sin(" << a << ") = " << sin(a);
            break;

        case 6:
            cout << "Enter angle in radians: ";
            cin >> a;
            cout << "cos(" << a << ") = " << cos(a);
            break;

        default:
            cout << "Invalid Choice";
    }

    return 0;
}