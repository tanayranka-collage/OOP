//code by tanay ranka sycse b 8
#include <iostream>
using namespace std;
class Parent{
    protected:
    int secret_value = 69;
};

class Child1: protected Parent{
    public:
    void dis(){
        cout << "Child1 obj created." << endl;
        cout << "Value is: " << secret_value << endl;
    }
};

class Child2: protected Parent{
    public:
    void d(){
        cout << "Child2 obj created." << endl;
        cout << "Value is: " << secret_value << endl;
    }
};

int main() {
    Child1 obj1;
    Child2 obj2;
    obj1.dis();
    cout << endl;
    obj2.d();
    return 0;
}
