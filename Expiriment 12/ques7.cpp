//code by tanay ranka sycse b 8
#include <iostream>
using namespace std;
class Book{
    string name;
    string auth_name;
    float price;
    public:
    void accept(){
        cout << "enter book name: ";
        cin >> name;
        cout << "enter author name: ";
        cin.ignore();
        getline(cin, auth_name);
        cout << "Prince: ₹";
        cin >> price;
    }
    void display(){
        cout << endl;
        cout << "Name: " << name << endl;
        cout << "Author Name: " << auth_name << endl;
        cout << "Price: ₹" << price;
    }
};
int main(){
    Book book1;
    Book *ptr = &book1;
    ptr->accept();
    ptr->display();

    return 0;
}
