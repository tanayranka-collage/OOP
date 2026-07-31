// code by tanay ranka sycse b 8
#include <iostream>
using namespace std;
class swaping {
    private:
    int num1, num2;
    public:
    void accept(){
        cout << "Enter First number: ";
        cin >> num1;
        cout << "Enter second Number: ";
        cin >> num2;
    }
    void swap();
};
inline void swaping::swap(){
    int temp = num1;
    num1 = num2;
    num2 = temp;
    cout << endl;
    cout << "First num is: " << num1 << endl;
    cout << "Second num is: " << num2 << endl;
}
int main() {
    swaping s;
    s.accept();
    s.swap();
    return 0;
}
