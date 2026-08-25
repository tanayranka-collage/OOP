//code by tanay ranka sycse b 8
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
class Staff{
    string name, post;
    unsigned long sal;
    public:
    void acc(){
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Post: ";
        cin >> post;
        cout << "Enter Salary: ₹";
        cin >> sal;
    }
    void dis(){
        cout << endl;
        if(post.compare("HOD") == 0){
            cout << name << post << "₹" << sal << endl;
        }
    }
};
int main() {
    Staff s[5];
    for(int i=0;i<2;i++){
        s[i].acc();
    }
    for(int i=0;i<2;i++){
        s[i].dis();
    }
    return 0;
}
