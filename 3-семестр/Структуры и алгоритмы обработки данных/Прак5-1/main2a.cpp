#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    unsigned char x = 0;
    unsigned int mask = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        int m = mask << t;
        x = x | m;
    }
    for (int i = 8 - 1; i >= 0; i--)
    {
        if ((int)(x & mask) != 0)
        {
            cout << 8 - i - 1 << " ";
        }
        mask = mask << 1;
    }
    cout << endl;
    return 0;
}