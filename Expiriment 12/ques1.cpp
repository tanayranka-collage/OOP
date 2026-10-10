//code by tanay ranka sycse b 8
#include <iostream>
using namespace std;
class Employee{
    string name;
    unsigned int id;
    public:
    void accept(){
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Id: ";
        cin >> id;
    }
    void display(){
        cout << endl;
        cout << "Name: " << name << endl;
        cout << "Id: " << id << endl;
    }
};
int main(){
    Employee obj;
    Employee *ptr = &obj;
    ptr->accept();
    ptr->display();


    return 0;
}
