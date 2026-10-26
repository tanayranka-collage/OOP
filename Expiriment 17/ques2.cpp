// code by tanay ranka sycse b 8

#include <iostream>
using namespace std;
class Base{
    public:
    virtual void show(){
        cout << "Base class got called" << endl;
    }
};

class Derived: public Base{
    public:
    void show() override {
        cout << "Derived class got called\n";
    }
};

int main() {
    Base *pt,ob;
    Derived obj;
    pt = &ob;
    pt->show();
    pt = &obj;
    pt->show();
    
    return 0;
}
