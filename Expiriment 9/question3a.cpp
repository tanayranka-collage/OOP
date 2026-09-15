//code by tanay ranka sycse b 8
#include <iostream>
using namespace std;

class student{
    private:
    string name;
    unsigned short roll;
    int marks;
    public:
    student(){
        name = "Aitya Chavan";
        roll = 11;
        marks = 90;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << roll << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {
    student hi;
    hi.display();
    return 0;
}
