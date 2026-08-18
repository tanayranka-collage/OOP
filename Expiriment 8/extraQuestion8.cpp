//code by tanay rank sycxse b 8
#include <iostream>
using namespace std;
class employee{
    string name, department;
    int id;
    public:
    void accept(){
        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter Working Department: ";
        getline(cin, department);
        cout << endl;
    }
    void display(){
        cout << "Employee ID: " << id << endl;
        cout << "Name of Employee is: " << name <<endl;
        cout << "Working Department: " << department <<endl;
        cout << endl;
    }
};
int main(){
    employee x[5];
    for(int i=0;i<5;i++){
        cout << "Information for Employee: #" << i+1 << endl;
        x[i].accept();
    }
    for (int i=0;i<5;i++){
        x[i].display();
    }

    return 0;
}
