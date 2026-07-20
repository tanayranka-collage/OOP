#include <iostream>
using namespace std;

int main(){
    int *x = new int(0);
    *x = 24;
    cout << endl;
    cout << "Dynamically allocated value: " << *x;
    delete x;
    return 0;
}
