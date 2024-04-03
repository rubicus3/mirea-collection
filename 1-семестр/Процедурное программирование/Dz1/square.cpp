#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string solve_linear(float b, float c)
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

string solve_square(float a, float b, float c)
{
    if (a == 0)
        return solve_linear(b, c);

    float D = b * b - 4.0 * a * c;

    if (D < 0)
    {
        return "No roots";
    }

    if (D == 0)
    {
        float res = (-b) / (2.0 * a);

        if (res == 0)
            return "0";
        return to_string((-b) / (2.0 * a));
    }

    float res1 = ((-b) + sqrt(D)) / (2.0 * a);
    float res2 = ((-b) - sqrt(D)) / (2.0 * a);

    if (res1 == -0)
    {
        res1 = 0;
    }
    if (res2 == -0)
    {
        res2 = 0;
    }

    return to_string(res1) + " " + to_string(res2);
}

int main()
{
    setlocale(LC_ALL, "rus");

    float a, b, c;
    cin >> a >> b >> c;

    cout << solve_square(a, b, c);
    return 0;
}