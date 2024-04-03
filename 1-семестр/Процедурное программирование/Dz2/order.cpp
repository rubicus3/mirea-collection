#include <iostream>

using namespace std;

int main()
{
    float x;
    cin >> x;
    int n = x;

    if (cin.fail() || n != x)
    {
        cout << "Неверные данные";
        return 0;
    }

    if (n <= 0)
    {
        cout << "n не натуральное";
        return 0;
    }

    for (int i = n; i < n + 11; i++)
    {
        cout << i << " ";
    }

    return 0;
}