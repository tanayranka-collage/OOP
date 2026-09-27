/code by tanay ranka sycse b 8
#include <iostream>
using namespace std;

class Grandfather {
public:
    void g() {
        cout << "This is a Grandfather class" << endl;
    }
    
};

class Father : public Grandfather {
public:
    void f() {
        cout << "This is Father class" << endl;
    }
};

class Child : public Father {
public:
    void c() {
        cout << "This is Son class" << endl;
    }
};

int main() {
    
    // Creating object of Child class
    Child obj;
    
    // Calling member methods of all classes
    // using Child object
    obj.c();
    obj.f();
    obj.g();
    return 0;
}
