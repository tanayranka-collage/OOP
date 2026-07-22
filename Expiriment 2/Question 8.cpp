// code by tanay ranka cse b 8
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "enter length: ";
    cin >> n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cout << "Enter for " << i+1 << " element: ";
        cin >> arr[i];
    }
    cout << endl;
    for(int i=0;i<n;i++){
        cout << " " << arr[i] << endl;
    }
    delete[] arr;    //deleting the array
    return 0;
}
