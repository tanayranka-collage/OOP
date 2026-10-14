// code by tanay ranka sycse b 8
#include <iostream>
#include <iomanip>
using namespace std;
class Bank{
    protected:
    unsigned long int account_no;
    string IFSC, name, holder;
    long int balance;
    double age;
    public:
    Bank(){
        account_no = 54533806634;
        IFSC = "JPMC900100";
        name = "JPMorganChase Inc.";
        balance= 0;
    }
    
};
class Fun: protected Bank{
    char x;
    long int temp;
    public:
    Fun(): Bank(){}
    void init(){
        cout << "enter your name: ";
        getline(cin, holder);
        cout << "Age of Account: ";
        cin >> age;
    }
    void menu(){
        while(1){
        cout << setfill('=') << setw(20) << endl;
        cout << "1. display Balance" << endl;
        cout << "2. withdraw"<< endl;
        cout << "3. deposit" << endl;
        cout << "4. exit" << endl;
        cout << setfill('=') << setw(20) << endl;
        cout << endl;
        cout << "choice: ";
        cin >> x;
        switch (x){
            case '1':
            cout << "acc no. " << account_no << endl;
            cout << "IFSC: " << IFSC << endl;
            cout << "name: " << name << endl;
            cout << "balance: ₹"<<balance<<endl;
            cout << endl;
            break;
            case '2':
            cout << "enter amount: ";
            cin >> temp;
            balance-=temp;
            cout << "done";
            break;
            case '3':
            cout << "enter amount: ";
            cin >> temp;
            balance += temp;
            cout << "done";
            break;
            case '4':
            cout << "bye.";
            return;
            default:
            cout << "invalid flag";
            break;
        }
    }
    }
};

int main() {
    Fun xyz, *ptr;
    ptr = &xyz;
    ptr->init();
    ptr->menu();
    return 0;
}
