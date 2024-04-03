#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    float S, m;
    string nv;

    cin >> S >> m >> nv;
    int n = stoi(nv);

    if (to_string(n) != nv)
    {
        cout << "полтора года ладно";
        return 0;
    }

    if (n < 0 || n > 40)
    {
        cout << "куда?";
        return 0;
    }


    for (float p = 1.0; p <= 100.0; p += 0.1)
    {
        float r = p / 100.0;

        float x = (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));

        if (fabs(m - x) <= 0.01)
        {
            cout << round(p) << endl;
            return 0;
        }
    }

    cout << ":(";

    return 0;
}