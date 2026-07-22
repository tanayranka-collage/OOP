// code by tanay ranka cse b 8
#include <iostream>
using namespace std;

int main() {
    float maths, physics, english;
    float total, percentage, average;

    cout << "Enter Maths Marks: ";
    cin >> maths;

    cout << "Enter Physics Marks: ";
    cin >> physics;

    cout << "Enter English Marks: ";
    cin >> english;
    cout << endl;

    total = maths + physics + english;
    percentage = total / 3;
    average = total / 3;

    cout << "\nTotal Marks = " << total << endl;
    cout << "Percentage = " << percentage << "%" << endl;
    cout << "Average = " << average << endl;

    if (maths >= 35 && physics >= 35 && english >= 35)
        cout << "Result: PASS";
    else
        cout << "Result: FAIL";

    return 0;
}
