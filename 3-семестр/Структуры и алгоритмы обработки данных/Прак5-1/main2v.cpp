#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int main()
{
    int n;
    unsigned char xarr[128]{0};
    unsigned char mask = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        int j = floor(t / 8);
        int k = t - 8 * j;
        int m = mask << (8 - k - 1);
        xarr[j] = xarr[j] | m;
    }
    for (int i = 0; i < 128; i++)
    {
        mask = 128;
        for (int j = 0; j < 8; j++)
        {
            if (xarr[i] & mask)
                cout << 8 * i + j << " ";
            mask = mask >> 1;
        }
    }
    cout << endl;
    return 0;
}