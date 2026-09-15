//code by thebluemarble
//prog 4 copy constr
#include <iostream>
using namespace std;

class Node {
    private:
    int *data;     // pointer for data;
    public:
    Node(int x=0){ //   parameterized constructor with defualt arguments
        data = new int(x);  // initialize empty pointer
    }

    Node(const Node &obj){  // copy constructor syntax
        data = new int(0);  // initialize data pointer of second object.
        *data = *(obj.data);   // initialize data of first object to this
    }
    ~Node(){
        delete data;    // free data pointer using destructor
    }
    void display(){
        cout << "Data: " << *data << endl;
    }
};

int main() {
    Node dat1(24);      // constructor wit default args is called. 
    Node dat2 = dat1;    // copy constructor is called
    dat1.display();
    dat2.display();

    return 0;
}
