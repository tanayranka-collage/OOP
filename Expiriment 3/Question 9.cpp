// code by tanay rana sycse b 8
#include <iostream>
#include<iomanip>
using namespace std;
int main() {
    float l,b;
    double area;
    cout << "Enter the length: ";
    cin >> l;
    cout << "Enter the breath: ";
    cin >> b;
    area = l * b;
    cout << endl;
    cout <<"Area in int (rounded): " << static_cast<int>(area) << endl;
    cout << "Area in 2 decimal place: " << fixed << setprecision(3) << static_cast<float>(area) << endl;

    return 0;
}
