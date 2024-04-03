#include <iostream>
#include <algorithm>


using namespace std;

int main()
{
    int n;
    cout << "Кол-во шариков: ";
    cin >> n;

    int a[100], res = 1;

    for (int i = 0; i < n; i++) a[i] = i + 1;

    while(next_permutation(a, a + n)) {
        for (int i = 0; i < n; i++)
        {
            if(a[i] == i + 1) {
                res += 1;
                break;
            }
        }
    }

    cout << res << endl;

    return 0;
}