#include <iostream>
using namespace std;

int main() {
    int a = 3, b = 3;
    cout<<"a: "<<a<<"  b: "<<b<<endl;
    {
        int a = 5;
        b = a;
        cout<<"a: "<<a<<"  b: "<<b<<endl;
    }
    cout<<"a: "<<a<<"  b: "<<b<<endl;

    return 0;
}

