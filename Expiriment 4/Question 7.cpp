// code by tanay ranka sycse b 8
#include<iostream>
using namespace std;
class student{
    private:
    string name;int roll;
    public:
    void accept(){
        cout << "Pls ENter a name: ";
        cin >> name;
        cout << "ENyter a roll no.: ";
        cin >> roll;
    }
    void display(){
        cout << "Name si: " << name << endl;
        cout << "Roll number is: " << roll << endl;
    }
};
int main(){
    student maharastra;
    maharastra.accept();
    cout << endl;
    maharastra.display();
    return 0;
}
