// code by tanay ranka sycse b 8
#include <iostream>
using namespace std;

class Demo
{
    static int count;

public:
    static void increment()
    {
        count++;
    }

    static void display()
    {
        cout << "Count = " << count << endl;
    }
};

int Demo::count = 0;

int main()
{
    Demo::increment();
    Demo::increment();
    Demo::increment();

    Demo::display();

    return 0;
}
