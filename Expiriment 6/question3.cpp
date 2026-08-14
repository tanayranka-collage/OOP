//code by tanay ranka sycse b 8
#include <iostream>
#include <iomanip>
using  namespace std;
class Averahe{
    private:
    int a[5];
    public:
    void acc(){
        cout << "Enter values for 5 elements: \n";
        for(int i=0;i<5;i++){
            cout <<"Value for " << i+1 << ": ";
            cin >> a[i];
        }
    }
    friend void avg(Averahe s);
};

void avg(Averahe s){
    int sum = 0;
    for(int i=0;i<5;i++){
        sum+=s.a[i];
    }
    cout << endl;
    cout << "Average is: " << setprecision(4) << sum / 5 << endl;
}

int main() {
    Averahe t;
    t.acc();
    avg(t);
    return 0;
}
