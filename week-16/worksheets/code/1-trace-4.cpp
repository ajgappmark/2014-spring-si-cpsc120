#include <iostream>
using namespace std;

int main() {
    int a = 3, b = 3, c = 3;
    cout<<"a: "<<a<<"  b: "<<b<<"  c: "<<c<<endl;
    {
        int a = 5, b = 5;
        c = b;
        cout<<"a: "<<a<<"  b: "<<b<<"  c: "<<c<<endl;
        {
            int a = 7;
            b = a;
            cout<<"a: "<<a<<"  b: "<<b<<"  c: "<<c<<endl;
        }
        cout<<"a: "<<a<<"  b: "<<b<<"  c: "<<c<<endl;
    }
    cout<<"a: "<<a<<"  b: "<<b<<"  c: "<<c<<endl;

    return 0;
}

