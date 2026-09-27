//code by tanay ranka sycse b 8
#include <iostream>
using namespace std;
class Vehicle{
    public:
    int n=20;
    void display(){
        cout << "value of n is: " << n << endl;
    }
};

class Bike{
    public:
    string bike = "Ducatti";
    void dis(){
        cout << "Name of bike Is: " << bike << endl;
    }
};

class Honda: public Vehicle, public Bike{
    public:
    Honda(){
        cout << "obj of Honda class is created.\n";
    }
};

int main() {
    Honda ss;
    ss.display();
    ss.dis();
    return 0;
}
