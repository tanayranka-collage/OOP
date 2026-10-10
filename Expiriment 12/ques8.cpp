//code by tanay ranka sycse b 8
#include <iostream>
#include <iomanip>
using namespace std;
class Box{
    float l,b,h;
    public:
    void accept(){
        cout << "ENter Length: ";
        cin >> l;
        cout << "Enter Breath: ";
        cin >> b;
        cout << "Enter height: ";
        cin >> h;
    }
    void Area(){
        cout << "Area of the Box is: " << setprecision(4) << l*b << endl;
    }
    void Volume(){
        cout << "Volume of the Box is: " << setprecision(6) << l*b*h << endl;
    }
};
int main(){
    Box cube;
    Box *pointer = &cube;
    pointer->accept();
    pointer->Area();
    pointer->Volume();
    return 0;
}
