//code by tabay ranka sycse b 8

#include <iostream>
using namespace std;


class Number{
    int num;
    public:
    Number(int a=20){
        num = a;
    }
    friend int operator >(Number &, Number &);
};

int operator >(Number &a, Number &b){
    if(a.num >= b.num){
        return a.num;
    }else{
        return b.num;
    }
}

int main() {
    Number aa(40),ab(10),o;
    int t,x;
    t = aa > ab;
    x = ab > o;
    cout << "greatest num: " << t << endl;
    cout<< "greatest: " << x << endl;
    return 0;
}
