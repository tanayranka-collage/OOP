// code by tanayranka sycse b 8
#include <iostream>
using namespace std;
class SI{
    static float ROI;
    unsigned long prin;
    float dur;
    public:
    void acc(){
        cout << "Enter principal amount ₹";
        cin >> prin;
        cout << "Enter duration (in years): ";
        cin >> dur;
    }
    void dis(){
        cout << "Interest is: " << (prin * ROI * dur) / 100 << endl;
        cout << "Amount: ₹" << prin + (prin * ROI * dur)/100 << endl;
    }
};

float SI::ROI = 6.0;
int main() {
    SI ds;
    ds.acc();
    ds.dis();

    return 0;
}
