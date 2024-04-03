#include <iostream>
#include <string>

using namespace std;

string solve_linear(int b, int c)
{
    if (b == 0 && c == 0)
    {
        return "any x is possible";
    }

    if (b == 0 || c == 0)
    {
        return "0";
    }

    string res = to_string((-c) / b);
    return res;
}

int main()
{
    setlocale(LC_ALL, "rus");

    int b, c;
    cin >> b >> c;

    cout << solve_linear(b, c);
    return 0;
}