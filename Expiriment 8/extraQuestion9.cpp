//code by tanay ranka sycse b 8
#include <iostream>
using namespace std;
class student{
    string name;
    unsigned int roll, perc;
    public:
    void accept(){
        cout << "Enter Student Roll no.: ";
        cin >> roll;
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter percentage: ";
        cin >> perc;
        cout << endl;
    }
    void display(){
        if (perc > 75){
            cout << "Student roll no: " << roll << endl;
            cout << "Name of student is: " << name <<endl;
            cout << "Percentage is: " << perc <<endl;
            cout << endl;
        }
    }
};
int main(){
    student x[10];
    for(int i=0;i<10;i++){
        cout << "Information for student: #" << i+1 << endl;
        x[i].accept();
    }
    for (int i=0;i<10;i++){
        x[i].display();
    }

    return 0;
}
