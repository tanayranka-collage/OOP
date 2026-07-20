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

/* 
SYNTAX for defining member function outside class using SRO:
class Class_name{
    public:
    void funct();
};
return_type Class_name::function_name(parameters_list){
    //body
}
*/
