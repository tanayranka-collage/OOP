//code by tanay ranka sycse b 8
#include <iostream>
using namespace std;

class Parent{
    public:
    string DNA = "XX";
    void dis(){
        cout << "DNA of Parent is: " << DNA << endl;
    }
};

class Child: public Parent{
    public:
    Child(){
        cout << "Child class obj has been created;" << endl;
    }
};

int main() {
    Child ss;
    ss.dis();
    return 0;
}
