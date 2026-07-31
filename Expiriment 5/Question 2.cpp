//code by tanay rankas sycse b 8
#include <iostream>
#include<cmath>
using namespace std;
class maxi{
    private:
    int num1, num2;
    public:
    void accept(){
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second num: ";
        cin >> num2;
    }
    void cal();
};

inline void maxi::cal(){
    if (num1 > num2){
        cout << "Greantest num is: " << num1 << endl;
    }else{
        cout << "Greatest num is: " << num2 << endl;
    }
}
int main() {
    maxi x;
    cout << endl;
    x.accept();
    x.cal();
    return 0;
}
