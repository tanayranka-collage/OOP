//code by tanay ranka sycse b 8
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

void Display(Node **ref){
    Node *t = *ref;
    while(t != NULL){
        cout << "Data: " << t->data << endl;
        t = t->next;
    }
    cout << endl;
}

int main(){
    Node *fir = new Node;
    Node *sec = new Node;
    Node *th = new Node;
    Node *head = fir;
    fir->data = 10;
    fir->next = sec;
    sec->data = 20;
    sec->next = th;
    th->data = 30;
    th->next = NULL;

    Display(&head);
    
    delete fir;
    delete sec;
    delete th;
    return 0;
}
