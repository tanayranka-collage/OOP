//code by tanay ranka syscse b 8
//just press enter in the output screen to kickstart the cin.ignore() function.
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
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter post: ";
        getline(cin, post);
        cout << "Enter Salary: ₹";
        cin >> salary;
        cout << "Enter Employee-id: ";
        cin >> id;
    }
    friend void compare(Employee s1, Employee s2);
};

void compare(Employee s1, Employee s2){
    if(s1.salary > s2.salary){
        cout << s1.name << " " << "Has more salary than " << s2.name << endl;
    }else{
        cout << s2.name << " " << "Has more salary than " << s2.name << endl;
    }

    if(s1.id > s2.id){
        cout << s1.name << " " << "Has more priority than " << s2.name << endl;
    }else{
        cout << s2.name << " " << "Has more priority than " << s1.name << endl;
    }
}

int main() {
    Employee t, y;
    t.acc();
    y.acc();
    compare(t, y);
    return 0;
}
