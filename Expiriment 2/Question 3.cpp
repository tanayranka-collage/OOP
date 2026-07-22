// code by tanay ranka cse b 8
#include <iostream>
using namespace std;
int num = 100;
int main() {
    int num = 50;
    cout << "Global variable: " << ::num << endl;
    cout << "Local Variable: " << num << endl;
    return 0;
}
