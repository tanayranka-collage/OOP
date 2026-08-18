//code by tanay rnakasycse b 8
#include <iostream>
using namespace std;
class customer{
    string name, interested_product, email;
    unsigned long contact_no;
    int id;
    public:
    void accept(){
        cout << "Enter Contact Number: ";
        cin >> contact_no;
        cout << "Enter Customer ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter Product of Interest: ";
        getline(cin, interested_product);
        cout << "Email iD: ";
        getline(cin, email);
        cout << endl;
    }
    void display(){
        cout << "Customer ID: " << id << endl;
        cout << "Name of Customer is: " << name <<endl;
        cout << "Product of Interest: " << interested_product << endl;
        cout << "Contact No.: +91 " << contact_no << endl;
        cout << "Email ID: " << email << endl;
    }
};
int main(){
    customer x[5];
    for(int i=0;i<5;i++){
        cout << "Information for Customer: #" << i+1 << endl;
        x[i].accept();
    }
    for (int i=0;i<5;i++){
        x[i].display();
    }

    return 0;
}
