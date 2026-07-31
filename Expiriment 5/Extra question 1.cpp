//code by tanay ranka sucse b 8
#include <iostream>
using namespace std;
class fac{
    public:
    int num;
    void accept(){
        cout << "Enter a number: ";
        cin >> num;
    }
    long factorial(int n);
};


inline long fac::factorial(int n){
    if (n == 0 || n == 1){
        return 1;
    }else{
        return n * fac::factorial(n-1);
    }
}

int main() {
    fac x;
    x.accept();
    long k = x.factorial(x.num);
    cout << "Factorial of nymber is: " << k << endl;
    return 0;
}
