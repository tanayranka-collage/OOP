#include <iostream>
using namespace std;

int main() {
    int a, b, c;

    cout << "Enter coefficients a, b and c: ";
    cin >> a >> b >> c;

    cout << "Quadratic Equation is: ";
    cout << a << "x^2 ";

    if (b >= 0)
        cout << "+ " << b << "x ";
    else
        cout << "- " << -b << "x ";

    if (c >= 0)
        cout << "+ " << c;
    else
        cout << "- " << -c;

    cout << " = 0";

    return 0;
}