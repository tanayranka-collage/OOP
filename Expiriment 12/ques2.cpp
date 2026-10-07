
// code by tanay ranka sycse b 8
#include <iostream>
using namespace std;
void Max(int a, int b){
    if(a > b){
        cout << a << " is greatest";
    }else if(b > a){
        cout << b << " is greatest";
    }else{
        cout << "both are same";
    }
}

void Max(float a, float b){
    if(a > b){
        cout << a << " is greatest";
    }else if(b > a){
        cout << b << " is greatest";
    }else{
        cout << "both are same";
}

int main() {
    float x,y;
    cout << "dbter a";
    cin >> x;
    cout << "enter y";
    cin >> y;
    Max(x,y);
    Max(static_cast<int>(x), static_cast<int>(y));
    
}
