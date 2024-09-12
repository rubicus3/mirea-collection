#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int main()
{
    int n;
    unsigned long long int x = 0;
    unsigned long long int mask = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        unsigned long long int m = mask << t;
        x = x | m;
    }
    for (int i = 64 - 1; i >= 0; i--)
    {
        if (x & mask)
        {
            cout << 64 - i - 1 << " ";
        }
        mask = mask << 1;
    }
    cout << endl;
    return 0;
}