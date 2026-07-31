//code by tanay ranka sycse b 8
#include <iostream>
#include<iomanip>
using namespace std;
class Circle{
    private:
    int r;
    const double pi = 3.1415280923;
    public:
    void accept(){
        cout << "Enter radius: ";
        cin >> r;
    }
    void area();
};

inline void Circle::area(){
    cout << "Area of circle is: " << setprecision(6) << pi * r * r << endl;
}
int main() {
    Circle p;
    p.accept();
    p.area();
    return 0;
}
