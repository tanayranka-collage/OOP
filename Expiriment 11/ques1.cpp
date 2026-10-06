//code by tanay ranka syscse b 8
#include <iostream>
using namespace std;
class A{
    protected:
    int secret = 69;
};
class B:virtual protected A{};
class C:virtual protected A{};
class D:public B, public C{
    public:
    void dis(){
        cout << "Value of Secret is: " << secret;
    }
};
int main() {
    D obj;
    obj.dis();
    return 0;
}
