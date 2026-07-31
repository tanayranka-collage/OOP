//code by tanay ranka sycse b 8
#include<iostream>
using namespace std;

inline int largest(int a, int b, int c){
    if (a > b && a > c){
        return a;
    }else if(b > a && b > c){
        return b;
    }else{
        return c;
    }
}


int main() {
    int x,y,z;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second numbet: ";
    cin >> y;
    cout << "Enter third number: ";
    cin >> z;
    
    int large = largest(x, y, z);
    cout << endl;
    cout << "Largest number is: " << large;
    return 0;
}
