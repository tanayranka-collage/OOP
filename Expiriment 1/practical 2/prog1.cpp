// code by tanay ranka cse b 8
#include <iostream>
using namespace std;

int main() {
    float salary, bonus, grossSalary;

    cout << "Enter Basic Salary: ";
    cin >> salary;

    bonus = salary * 0.60;
    grossSalary = salary + bonus;

    cout << "Bonus = " << bonus << endl;
    cout << "Gross Salary = " << grossSalary;

    return 0;
}
