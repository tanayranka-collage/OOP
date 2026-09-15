//code by tanay ranka sycse b 8
// prog 3b)
#include <iostream>
using namespace std;
class student{
    private:
    string name;
    unsigned short roll;
    int marks;
    public:
    student(string n, unsigned short r, int m){
        name = n;
        roll = r;
        marks = m;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Roll No.: " << roll << endl;
        cout << "Marks: " << marks << endl;
    }
};
int main() {
    student hi("Aditya Chavahhan", 11, 88);
    student hihi("igfigfgfdfg ef", 625, 1);
    hi.display();
    hihi.display();

    return 0;
}
