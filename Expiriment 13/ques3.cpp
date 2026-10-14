// code vy tanay ranka sycse b 8

#include <iostream>
using namespace std;
class Student{
    protected:
    string name;
    unsigned int roll;
    float marks1,marks2;
    public:
    void getdata(){
        cout << "Enter name: ";
        getline(cin, name);
        cout << "roll number ";
        cin >> roll;
        cout << "marks1: ";
        cin >> marks1;
        cout << "marks2: ";
        cin >> marks2;
    }
};
class Result: public Student{
    public:
    void per(){
        cout << "Name: "<< name << endl;
        cout << "roll no. " << roll << endl;
        cout << "perc: " << (marks1 + marks2)/2 << "%" << endl;
    }
};
int main() {
    Result obj, *ptr;
    ptr = &obj;
    ptr->getdata();
    ptr->per();
    return 0;
}
