//code by tanay ranka sycse b 8
#include <iostream>
using namespace std;
class Num{
    static int c;
    public:
    friend void operator ++(Num &d);
    void dis(){
        cout << "Number: " << c << endl;
    } 
};
int Num::c = 99;

void operator ++(Num &d){
    Num::c++;
}

int main(){
    Num obj;
    obj.dis();
    ++obj;
    ++obj;
    obj.dis();
    return 0;
}
