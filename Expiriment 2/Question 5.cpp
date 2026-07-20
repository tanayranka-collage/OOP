#include <iostream>
using namespace std;
namespace Physics{
    const float pi = 3.14;
}
namespace Chemistry{
    const double pi = 3.141528190256;
}

int main(){
    cout << "Pi value in namespace Physics: " << Physics::pi << endl;
    cout << "Pi value in namespcae chemistry: " << Chemistry::pi << endl;
    return 0;
}
