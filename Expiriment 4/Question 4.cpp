// code by tanay ranka sycse b 8
#include<iostream>
using namespace std;
class student{
    private:
    string name;
    int rollno;
    long prn;
    public:
    void accept();
    void display();
};
inline void student::accept(){
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter roll no: ";
    cin >> rollno;
    cout << "Enter PRN number: ";
    cin >> prn;
}
inline void student::display(){
    cout << "Name is: " << name << endl;
    cout << "Roll No. is: " << rollno << endl;
    cout << "PRN number is: " << prn << endl;
}

int main(){
    cout << endl;
    student s1;
    s1.accept();
    s1.display();
    
    
    
    return 0;
}
