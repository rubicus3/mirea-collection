#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string solve_more(float a, float x)
{
    if (a - x * x < 0)
        return "Undefined solution";

    return to_string(sqrt(a - x * x));
}

string solve_less(float a, float x)
{
    return to_string(a * log(fabs(x)));
}

string solve(float a, float x)
{
    if (fabs(x) < 1)
    {
        if (a == 0)
            return "Undefined solution";

        return solve_less(a, x);
    }

    return solve_more(a, x);
}

int main()
{
    setlocale(LC_ALL, "rus");

    float a, x;

    cout << "Введите a: ";
    cin >> a;

    cout << "Введите x: ";
    cin >> x;

    cout << solve(a, x);

    return 0;
}