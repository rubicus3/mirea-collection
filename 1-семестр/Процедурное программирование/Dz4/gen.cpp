#include <iostream>

using namespace std;

int s(int m, int b, int c, int i) {
    if(i == 0) return b % c;

    return (m * s(m, b, c, i - 1) + b ) % c;
}


int main() {
    for (int i = 0; i < 100; i++)
    {
        cout << s(37, 3, 64, i)  << " ";
    }

    cout << endl;
    cout << endl;
    cout << endl;

    for (int i = 0; i < 100; i++)
    {
        cout << s(25173, 13849, 65537, i)  << " ";
    }
    


    return 0;
}