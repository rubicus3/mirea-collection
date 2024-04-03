#include <iostream>
#include <cstring>

using namespace std;

void shellSort(char arr[], int d)
{
    for (int gap = d / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < d; i += 1)
        {
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
}

int main()
{
    char str[1024];
    cin >> str;

    shellSort(str, strlen(str));

    cout << str;

    return 0;
}