//code by tanay rankasycsse b 8
#include <iostream>
#include<string>
using namespace std;
class library{
    unsigned int id, pages;
    string title, author;
    unsigned long price;
    public:
    void accept(){
        cout << "Enter Book id: ";
        cin >> id;
        cout << "Enter total number of pages: ";
        cin >> pages;
        cout << "Enter the price: ₹";
        cin >> price;
        cin.ignore();
        cout << "Enter Name of the book: ";
        getline(cin, title);
        cout << "Enter Name of the Author: ";
        getline(cin, author);
        cout << endl;
    }
    void display(){
        cout << endl;
        cout << "Name of book is: " << title << endl;
        cout << "With a Book ID: " << id << endl;
        cout << "Author: " << author << endl;
        cout << "Total number of pages; " << pages << endl;
        cout << "Price: ₹" << price << endl;
    }
};
int main(){
    int n;
    cout << "Enter length: ";
    cin >> n;
    library x[n];
    for(int i=0;i<n;i++){
        cout << "Information for book: " << i+1 << endl;
        x[i].accept();
    }
    for(int i=0;i<n;i++){
        x[i].display();
    }

    return 0;
}
