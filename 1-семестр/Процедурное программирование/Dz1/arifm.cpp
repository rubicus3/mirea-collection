#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    int a, b;

    cin >> a >> b;

    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;

    if (b == 0)
    {
        cout << "can't divide by 0";
        return 0;
    }

    cout << a / b;
    return 0;
}