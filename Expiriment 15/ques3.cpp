//code by tanay ranka sycse b 8
#include <iostream>
using namespace std;
class D{
    static int c;
    public:
    void operator --(){
        c--;
    }
    void dis(){
        cout << "Number: " << c << endl;
    } 
};
int D::c = 100;
int main(){
    D x, *t; 
    t = &x;
    x.dis();
    --x;
    t->dis();
    --x;
    --x;
    x.dis();
    return 0;
}
