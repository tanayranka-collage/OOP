// code by tanay ranka sycse b 8
#include<iostream>
using namespace std;
class Product{
    public:
    float price;
    int pid;
    string name;
    void accept();
    void display();
};

void Product::accept(){
    cout << "Pls ENter a name: ";
    cin >> Product::name;
    cout << "ENyter ID no.: ";
    cin >> Product::pid;
    cout << "Enter Price: ₹";
    cin >> Product::price;
}

void Product::display(){
    cout << "Product Name is: " << Product::name << endl;
    cout << "ID number is: " << Product::pid << endl;
    cout << "Price is ₹" << Product::price << endl;
}
int main(){
    Product sbi;
    sbi.accept();
    cout << endl;
    sbi.display();
    return 0;
}
