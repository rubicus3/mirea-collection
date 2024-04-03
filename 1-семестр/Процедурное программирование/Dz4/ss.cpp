#include <iostream>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

map<char, int> mto10{
    {'0', 0},
    {'1', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'A', 10},
    {'B', 11},
    {'C', 12},
    {'D', 13},
    {'E', 14},
    {'F', 15},
    {'G', 16},
    {'H', 17},
    {'I', 18},
    {'J', 19},
    {'K', 20},
};

map<int, char> mfrom10{
    {0, '0'},
    {1, '1'},
    {2, '2'},
    {3, '3'},
    {4, '4'},
    {5, '5'},
    {6, '6'},
    {7, '7'},
    {8, '8'},
    {9, '9'},
    {10, 'A'},
    {11, 'B'},
    {12, 'C'},
    {13, 'D'},
    {14, 'E'},
    {15, 'F'},
    {16, 'G'},
    {17, 'H'},
    {18, 'I'},
    {19, 'J'},
    {20, 'K'},
};

void reverseStr(string& str)
{
    int n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

bool check(char a[], int s)
{
    for (int i = 0; i < strlen(a); i++)
    {
        if (mto10[a[i]] >= s)
            return false;
    }
    return true;
}

long long int to10(char a[], int s)
{
    long long int res = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        res += mto10[a[i]] * pow(s, (strlen(a) - i - 1));
    }

    return res;
}

string from10(long long int a, int s)
{
    string res = "";
    while (a > 0)
    {
        res += mfrom10[a % s];
        a = a / s;
    }

    reverseStr(res);

    return res;

}

int main()
{
    char a[128];
    int s1, s2;

    cout << "Введите число: ";
    cin >> a;

    cout << "Основание: ";
    cin >> s1;

    if (!check(a, s1))
    {
        cout << "Несуществующее вводное число" << endl;
        return 0;
    }

    cout << "Новое основание: ";
    cin >> s2;

    long long int q = to10(a, s1);


    string res = from10(q, s2);

    cout << res << endl;

    return 0;
}