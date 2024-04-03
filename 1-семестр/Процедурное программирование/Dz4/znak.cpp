#include <iostream>

using namespace std;

int znak(int x)
{

    if (x < 0)
        return -1;

    if (x == 0)
        return 0;

    return 1;
}

int main()
{
    int x;
    cin >> x;
    cout << znak(x) << endl;
    return 0;
}