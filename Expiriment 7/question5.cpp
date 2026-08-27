//code by taanay ranlka sycse b 8
#include <iostream>
using namespace std;
class TEMP{
    static int count;
    string name;
    public:
    TEMP(string f){
        count++;
        name = f;
    }
    void dis(){
        cout << "Your Name is: " << name << endl;
        cout << endl;
        cout << "Total objects: " << count << endl;
    }
};
int TEMP::count;
int main() {
    TEMP g("Henry");
    TEMP h("Baburao");
    h.dis();
    g.dis();

    return 0;
}
