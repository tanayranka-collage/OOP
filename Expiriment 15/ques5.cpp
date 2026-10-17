//code by tanay ranka sycse b 8
#include <iostream>
using namespace std;
class Num{
    int c;
    public:
    Num(int x=20){
        c = x;
    }
    friend void operator-(Num &d);
    void dis(){
        cout << "Number: " << c << endl;
    } 
};

void operator -(Num &d){
    d.c = d.c * -1;
}

int main(){
    Num obj, obj1(10);
    obj.dis();
    -obj;
    obj.dis();
    cout << endl;
    obj1.dis();
    -obj1;
    obj1.dis();
    return 0;
}
