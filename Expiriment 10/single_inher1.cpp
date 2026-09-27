//code by tanay rank asycse b 8
#include <iostream>
using namespace std;

class Physics{
    public:
    double pi = 3.1415284940458395395;
    void dis(){
        cout << "Exact Value of pi is: " << pi << endl;
    }
};

class Maths: public Physics{
    public:
    float PI = 3.14;
    void display(){
        cout << "Value of PI in Maths: " << PI;
    }
};

int main() {
    Maths ss;
    ss.dis();
    ss.display();
    return 0;
}
