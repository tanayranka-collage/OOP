#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;
namespace DS{
    int data = 24;
};
struct Node{
    int data;
    Node *next;
};
class TT{
    public:
    int x;
    static int f;
    void display(){
        cout << "d: " << x << endl;
        cout << "P: " << f << endl;
    }
};
int TT::f = 23;

int og = 23;

int main() {
    TT re;
    re.x = 44;
    cout << "NAMESPACE: " << DS::data << endl;
    Node* t = new Node();
    t->data = 230;
    t->next = nullptr;
    Node* head = t;
    cout << "struct: " << t->data << endl;
    re.display();
    cout << "VAlue: " << ::og << endl;
    return 0;
}
