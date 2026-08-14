// code by tanay ranka sycse b 8
#include <iostream>
using  namespace std;
class Number{
    private:
    int a,b;
    public:
    void acc(){
        cout << "Enter 1st no. ";
        cin >> a;
        cout << "Enter 2nd no. ";
        cin >> b;
    }
    friend void p(Number as);
};

void p(Number as){
    if(as.a > as.b){
        cout << "Max is " << as.a << endl;
    }else{
        cout << "MAx is " << as.b << endl;
    }
}

int main() {
    Number ag;
    ag.acc();
    p(ag);
    return 0;
}
