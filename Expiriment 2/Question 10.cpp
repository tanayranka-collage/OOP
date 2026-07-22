// code by tanay ranka cse b 8
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string subject[5] = {"English", "Maths", "Science", "Computer", "History"};
    int marks[5];
    int total = 0;
    float average;

    // Accept marks
    cout << "Enter marks for 5 subjects:\n";
    for(int i = 0; i < 5; i++)
    {
        cout << subject[i] << ": ";
        cin >> marks[i];
        total += marks[i];
    }

    average = total / 5.0;

    cout << "\n";
    cout << setfill('=') << setw(34) << "" << endl;
    cout << setfill(' ');
    cout << left << setw(20) << "Subject"
         << right << setw(10) << "Marks" << endl;
    cout << setfill('-') << setw(34) << "" << endl;
    cout << setfill(' ');

    for(int i = 0; i < 5; i++)
    {
        cout << left << setw(20) << subject[i]
             << right << setw(10) << marks[i] << endl;
    }

    cout << setfill('-') << setw(34) << "" << endl;
    cout << setfill(' ');
    cout << left << setw(20) << "Total"
         << right << setw(10) << total << endl;

    cout << left << setw(20) << "Average"
         << right << setw(10) << fixed << setprecision(2) << average << endl;

    cout << setfill('=') << setw(34) << "" << endl;

    return 0;
}
