// oced by tanay ranka sycse b 8
#include <iostream>
using namespace std;
class SI{
    private:
    int p, r;
    float t;
    public:
    void accept(){
        cout << "Enter principal amount: ₹";
        cin >> p;
        cout << "Enter R.O.I: ";
        cin >> r;
        cout << "Enter time in decimals: ";
        cin >> t;
    }
    void simple_i();
};

inline void SI::simple_i(){
    float f = (p * r * t) / 100;
    cout << "Total Amount after S.I is: ₹" << p + f << endl;
}
int main() {
    SI pd;
    pd.accept();
    pd.simple_i();
    return 0;
}
