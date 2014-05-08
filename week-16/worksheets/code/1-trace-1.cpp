#include <iostream>
using namespace std;

int main() {
    cout << "a b temp\n" << "--------\n";

    int a = 5;     cout<<a<<endl;
    int b = 7;     cout<<a<<" "<<b<<endl;

    int temp = a;  cout<<a<<" "<<b<<"  "<<temp<<endl;
    a = b;         cout<<a<<" "<<b<<"  "<<temp<<endl;
    b = temp;      cout<<a<<" "<<b<<"  "<<temp<<endl;

    return 0;
}

