#include <iostream>

using namespace std;

int gcd_i(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int depth = 0;

int gcd_r(int a, int b)
{
    if (a == 0)
    {
        cout << "Глубина рекурсии: " << depth << endl;
        return b;
    }
    depth += 1;
    return gcd_r(b % a, a);
}

int main()
{
    int a = 98, b = 56;

    cout << "НОД чисел " << a << " и " << b << endl;
    cout << "Итеративно: " << gcd_i(a, b) << endl;
    int v = gcd_r(a, b);
    cout << "Рекурсивно: " << v << endl;

    cout << endl;

    a = 642, b = 432;

    cout << "НОД чисел " << a << " и " << b << endl;
    cout << "Итеративно: " << gcd_i(a, b) << endl;
    int q = gcd_r(a, b);
    cout << "Рекурсивно: " << q << endl; 

    return 0;
}