//code by tanay ranka sycse b 8
#include <iostream>
using namespace std;
class Student{
    string name;
    unsigned int roll;
    public:
    Student(string nav="Not SET", unsigned int r=0){
        this->name = nav;
        this->roll = r;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "ROll Number: " << roll << endl;
        cout << endl;
    }
};
int main(){
    Student s1("Rohit Sharma", 24);
    Student s2;
    s1.display();
    s2.display();
    return 0;
}
