// code by tanay ranka cse b 8
#include <iostream>
using namespace std;
class Student{
    public:
    int roll, marks;
    string name;
    void accept();
    void display();
};
// accesing using Scope Resolution Operator
void Student::accept(){
    cout << "Enter roll no: ";
    cin >> Student::roll;
    cout << "Enter marks: ";
    cin >> Student::marks;
    cout << "Enter name: ";
    cin >> Student::name;
}

void Student::display(){
    cout << endl;
    cout << "Name: " << Student::name << endl;
    cout << "Marks: " << Student::marks << endl;
    cout << "Roll No.: " << Student::roll << endl;
}
int main() {
    Student f;
    f.accept();
    f.display();
    return 0;
}
