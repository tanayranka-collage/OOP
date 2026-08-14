// code by tanay ranka sycse  b 8
#include <iostream>
using  namespace std;
class Cls2;
class Cls1{
    private:
    int a;
    public:
    void acc(){
        cout << "Enter 1st no. ";
        cin >> a;
    }
    friend void addd(Cls1 as, Cls2 asg);
};

class Cls2{
    private:
    int b;
    public:
    void asss(){
        cout << "Enter 2nd no. ";
        cin >> b;
    }
    friend void addd(Cls1 as, Cls2 asg);
};

void addd(Cls1 as, Cls2 asg){
    cout << "Added numbers is: " << as.a + asg.b << endl;
}

int main() {
    Cls1 agh;
    Cls2 ad;
    agh.acc();
    ad.asss();
    addd(agh, ad);
    return 0;
}
