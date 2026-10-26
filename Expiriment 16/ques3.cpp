//code by tabay ranka sycse b 8

#include <iostream>
using namespace std;


class Name{
    std::string name;
    public:
    Name(string s="not defined"){
        name = s;
    }
    bool operator ==(Name a){
        if(name == a.name){
            return true;
        }else{
            return false;
        }
    }
    
};
int main() {
    Name str("hello"), str1("hello"), s;
    if(str == str1){
        cout << "Equal strings."<<endl;
    }
    if(str1 == s){
        cout << "euql";
    }else{
        cout << "s and str1 not equal";
    }
    return 0;
}
