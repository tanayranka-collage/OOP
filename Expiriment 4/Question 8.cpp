// code by tanay ranka sycse b 8
#include<iostream>
using namespace std;
class Account{
    public:
    float bal;
    long acc_no;
    string holder_name;
    void accept();
    void display();
};

void Account::accept(){
    cout << "Pls ENter a name: ";
    cin >> Account::holder_name;
    cout << "ENyter account no.: ";
    cin >> Account::acc_no;
    cout << "Enter Balance: ";
    cin >> Account::bal;
}

void Account::display(){
    cout << "Holder Name is: " << Account::holder_name << endl;
    cout << "Account number is: " << Account::acc_no << endl;
    cout << "Balance is ₹" << Account::bal << endl;
}
int main(){
    Account sbi;
    sbi.accept();
    cout << endl;
    sbi.display();
    return 0;
}
