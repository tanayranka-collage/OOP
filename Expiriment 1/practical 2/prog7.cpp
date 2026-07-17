#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double principal, rate, time, emi;

    cout << "Enter Loan Amount: ";
    cin >> principal;

    cout << "Enter Annual Interest Rate (%): ";
    cin >> rate;

    cout << "Enter Time (Years): ";
    cin >> time;

    rate = rate / (12 * 100);
    time = time * 12;

    emi = (principal * rate * pow(1 + rate, time)) /
          (pow(1 + rate, time) - 1);

    cout << "Monthly EMI = " << emi;

    return 0;
}