#include <iostream>
using namespace std;

int main() {
    float price, gst, mrp;

    cout << "Enter Product Price: ";
    cin >> price;

    gst = price * 0.18;
    mrp = price + gst;

    cout << "GST = " << gst << endl;
    cout << "MRP = " << mrp;

    return 0;
}