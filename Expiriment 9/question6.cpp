//code by tanay ranka sycse b 8
#include <iostream>
using namespace std;
class College{
    private:
    string name, department;
    int id;
    public:
    College(string n="MIT Polytechnic"){
        department = n;
    }
    void acc(){
        cout << "enter name: ";
        cin >> name;
        cin.ignore();
        cout << "Enter id: ";
        cin >> id;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "ID: " << id << endl;
        cout << endl;
    }
};

int main() {
    College s[3];
    int chavan, aditya;
    for(chavan=0;chavan<3;chavan++){
        s[chavan].acc();
    }
    for(aditya=0;aditya<3;aditya++){
        s[aditya].display();
    }

    return 0;
}
