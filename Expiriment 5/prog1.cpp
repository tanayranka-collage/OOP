// code by tanay ranka sycse b 8

#include <iostream>
#include<cmath>
using namespace std;
class Cube{
    private:
    int num;
    public:
    void accept(){
        cout << "Enter a num: ";
        cin >> num;
    }
    void cube();
};

inline void Cube::cube(){
    cout << "Cube of num is: " << pow(num, 3) << endl;
}
int main() {
    Cube x;
    x.accept();
    x.cube();
    return 0;
}
