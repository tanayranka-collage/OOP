//code by tanay ranka syscse b 8
#include <iostream>

using  namespace std;
class Employee{
    private:
    int id;
    long salary;
    string name;
    string post;
    public:
    void acc(){
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter post: ";
        getline(cin, post)
        cout << "Enter Salary: ₹";
        cin >> salary;
        cout << "Enter Employee-id: ";
        cin >> id;
    }
    friend void display(Employee s);
};

void display(Employee s){
    cout << endl;
    cout << "Name: " << s.name << endl;
    cout << "ID: " << s.id << endl;
    cout << "Post: " << s.post << endl;
    cout << "Salary: ₹" << s.salary << endl;
}

int main() {
    Employee t;
    t.acc();
    display(t);
    return 0;
}
