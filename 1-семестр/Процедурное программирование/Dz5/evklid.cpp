#include <iostream>

using namespace std;

int nodmin(int a, int b) {

    while(a > 0 and b > 0) {
        if(a > b) {
            a -= b;
        }
        else b -= a;

    }  
    return a + b;
}

int noddiv(int a, int b) {

    while(a > 0 and b > 0) {
        if(a > b) {
            a %= b;
        }
        else b %= a;

    }  
    return a + b;
}


int main() {
    int a, b;

    cin >> a >> b;

    cout << "minus: " << nodmin(a, b) << endl;
    cout << "div:   " << noddiv(a, b) << endl;

    return 0;
}