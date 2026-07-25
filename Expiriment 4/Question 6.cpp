// code by tanay ranka sycse b 8
#include<iostream>
#include<cmath>
using namespace std;
class Squared{
    private:
    float num;
    double squared;
    public:
    double square(){
        cout << "Enter a num: ";
        cin >> num;
        squared = pow(num, 2);
        return squared;
    }
};
int main(){
    double sq;
    Squared e;
    sq = e.square();
    cout << endl;
    cout << "Square is: " << sq << endl;
    return 0;
}
