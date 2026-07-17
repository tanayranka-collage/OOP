#include <iostream>
using namespace std;

int main() {
    float percentage;

    cout << "Enter Percentage: ";
    cin >> percentage;

    if (percentage >= 95)
        cout << "Grade: A+";
    else if (percentage >= 85)
        cout << "Grade: A";
    else if (percentage >= 75)
        cout << "Grade: B";
    else if (percentage >= 65)
        cout << "Grade: C";
    else if (percentage >= 50)
        cout << "Grade: D";
    else
        cout << "Grade: F (Fail)";

    return 0;
}