#include <iostream>
using namespace std;
class test{
    public:
    void display();
};

void test::display(){
    cout << "Hello from the object" << endl;
}
int main() {
    test test1;
    test1.display();
    return 0;
}
