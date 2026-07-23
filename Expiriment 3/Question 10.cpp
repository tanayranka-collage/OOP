// code by tanay ranka sycse b 8
#include <iostream>
using namespace std;
class Staff{
    public:
    int id;
    string post;
    void accept();
    void display();
};
void Staff::accept(){
    cout << "Enter the post of member: ";
    cin >> Staff::post;
    cout << "Enter a id: ";
    cin >> Staff::id;
}
void Staff::display(){
    cout << "Post is: " << Staff::post << endl;
    cout << "Id is: " << Staff::id << endl;
}

int main(){
    Staff s[2];
    cout << endl;
    for(int i=0;i<2;i++){
        s[i].accept();
    }
    for(int i=0;i<2;i++){
        s[i].display();
    }
    return 0;
}
