//code by tanay ranka sycse b 8
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Circle{
    private:
    int r;
    const double pi = 3.141528364103;
    public:
    void area(){
        cout << "Enter a radius: ";
        cin >> r;
        cout << endl;
        cout << "Area is: " << setprecision(5) << pi * pow(r, 2) << endl;
    }
};
int main(){
    Circle sw;
    sw.area();
    return 0;
}
