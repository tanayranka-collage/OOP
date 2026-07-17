#include <iostream>
using namespace std;

int main() {
    float a, b;
    char op;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> b;

    switch (op) {
        case '+':
            cout << "Result = " << a + b;
            break;

        case '-':
            cout << "Result = " << a - b;
            break;

        case '*':
            cout << "Result = " << a * b;
            break;

        case '/':
            if (b != 0)
                cout << "Result = " << a / b;
            else
                cout << "Division by zero is not allowed.";
            break;

        default:
            cout << "Invalid Operator";
    }

    return 0;
}