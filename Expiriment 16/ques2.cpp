//code by tanay ranka sycse b 8

#include <iostream>
using namespace std;

class Number{
    int n;
    public:
    Number(int a=20){
        n = a;
    }
    Number operator -(Number b){
        Number t;
        t.n = n - b.n;
        return t;
    }
    void display(){
        cout << "N: " << n << endl;
    }
};

int main() {
    Number x(30),y,z;
    z = x-y;
    z.display();
    
    return 0;
}
