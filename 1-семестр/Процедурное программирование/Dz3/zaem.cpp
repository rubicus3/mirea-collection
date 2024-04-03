#include <iostream>
#include <cmath>

using namespace std;

int main() {

    float S, p;
    string nv;

    cin >> S >> p >> nv;
    int n = stoi(nv);

    if(to_string(n) != nv){
        cout << "полтора года ладно";
        return 0;
    }

    if(p < 0 || p > 100){

        cout << "ПРоцент !!!!!";
        return 0;
    }

    if(n < 0 || n > 40) {

        cout << "куда?";
        return 0;
    }

    float r = p / 100.0;

    float m = (S * r  * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));

    cout << m;

    return 0;
}