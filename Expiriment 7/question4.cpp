//code by tanay ranka sycse b 8
#include <iostream>
using namespace std;
class Force{
    static float mass;
    float g;
    public:
    void acc(){
        cout << "Enter Value of Acceleration due to gravity at your planet: ";
        cin >> g;
    }
    void dis(){
        cout << "Your Weight is: " << mass*g << " N" << endl; // formula according to Sir. Issac Newton in 1666 17th Century,Europe
    }
};

float Force::mass = 5;
int main() {
    Force ds;
    ds.acc();
    ds.dis();

    return 0;
}
