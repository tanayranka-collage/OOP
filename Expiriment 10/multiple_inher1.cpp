//code by tanay ranka sycse b 8
#include <iostream>
using namespace std;
class Vehicle{
    public:
    Vehicle(){
        cout << "Vehicle obj created.\n";
    }
};

class Car{
    public:
    Car(){
        cout << "Car obj created.\n";
    }
};

class SUV: public Car, public Vehicle{
    private:
    int model;
    public:
    void acc(){
        cout << "Enter Model: ";
        cin >> model;
    }
    void d(){
        cout << "MOdel is: " << model << endl;
    }
};
int main() {
    SUV ss;
    ss.acc();
    ss.d();
    return 0;
}
