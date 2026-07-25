// code by tanay ranka sycse b 8
#include<iostream>
using namespace std;
class rectangle{
    private:
    float l,b,Area;
    public:
    void area();
};
inline void rectangle::area(){
    cout << "Enter Length: ";
    cin >> l;
    cout << "enter Breth: ";
    cin >> b;
    cout << endl;
    Area = l*b;
    cout << "Area of ractangle is: " << Area << endl;
    
}
int main(){
    rectangle e;
    e.area();
    return 0;
}
