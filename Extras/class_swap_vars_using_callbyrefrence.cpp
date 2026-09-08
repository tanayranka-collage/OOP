// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class s{
    public:
    int a = 2;
    int b = 34;
}g;

void dd(s *s1){
    int temp = s1->a;
    s1->a = s1->b;
    s1->b = temp;
    cout << "A: " << s1->a << endl;
    cout << "B: " << s1->b << endl;
}

int main() {
    dd(&g);
    cout << "D: " << g.a;

    return 0;
}
