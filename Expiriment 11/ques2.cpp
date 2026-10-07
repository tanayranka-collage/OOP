//code by tanay ranka sycse b 8

#include <iostream>
using namespace std;
class Cricketer{
    protected:
    string name;
    public:
    void getname(){
        cout << "enter name";
        cin >> name;
    }
};
class Bowler:virtual public Cricketer{};
class Batsmen:virtual public Cricketer{};
class Allrounder: public Bowler, public Batsmen{
    public:
    void display(){
        cout << "bame is: " << name;
    }
};

int main() {
    Allrounder obj;
    obj.getname();
    obj.display();
    return 0;
}
