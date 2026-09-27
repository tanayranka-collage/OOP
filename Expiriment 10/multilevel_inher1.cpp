//code by tanay ranka sycse b 8
#include <iostream>
using namespace std;
class A{
    public:
    int value = 20;
};
class B: public A{
    protected:
    int value1 = 10;
};
class C: public B{
    public:
    void display(){
        cout << "value: " << value << endl;
        cout << "val: " << value1 << endl;
    }
};


int main() {
    C obj;
    obj.display();
    
    return 0;
}
