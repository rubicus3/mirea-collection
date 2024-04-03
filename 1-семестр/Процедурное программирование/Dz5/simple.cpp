#include <iostream>
#include <cmath>

using namespace std;

bool simple(int a)
{
    for (int i = 2; i <= sqrt(a) + 1; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (simple(i))
            cout << i << " ";
    }

    cout << endl;

    return 0;
}