//code by tanay ranka sycse b 8

#include <iostream>
#include <iomanip>
using namespace std;
void area(float x, float y){
    cout << "Area of rectangle is: " << setprecision(5) << x*y << endl;
}

void area(float x){
    cout << "Area of circle: " << setprecision(5) << 3.14*x*x << endl;
}

void area(int x){
    cout << "Area of square is: " << x*x << endl;
}
int main() {
    float a,b;
    cout << "enter @";
    cin >> a;
    cout << "enter b";
    cin >> b;
    area(a,b);
    area(a);
    int c = static_cast<int>(a);
    area(c);
    
    return 0;
    
}
