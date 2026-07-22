//code by tanay ranka sycse b 8
//explicit typecasting int to float and vice versa
#include <iostream>
using namespace std;
int main() {
    int num = 69;
    float gg = 21.234;
    
    cout << "Int to float: " << static_cast<float>(num) << endl;
    cout << "Float to int: " << static_cast<int>(gg) << endl;
    return 0;
}
