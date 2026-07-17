#include <iostream>
using namespace std;

int main() {
    float length, width;

    cout << "Enter length: ";
    cin >> length;

    cout << "Enter width: ";
    cin >> width;

    cout << "Area = " << length * width << endl;
    cout << "Perimeter = " << 2 * (length + width);

    return 0;
}