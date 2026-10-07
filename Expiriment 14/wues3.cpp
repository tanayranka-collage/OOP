// code vy tanay ranka sycse b 8
#include <iostream>
using namespace std;
void Vol(int l, int b, int h){
    cout << "volumeno f cuboid " << l*b*h;
}
void Vol(int a){
    cout << "columebof cube " << a*a*a;
}

int main() {
    int a,b,c;
    a = 29;
    b = 10;
    c = 24;
    a++;
    Vol(a,b,c);
    Vol(b);
    return 0;
}
