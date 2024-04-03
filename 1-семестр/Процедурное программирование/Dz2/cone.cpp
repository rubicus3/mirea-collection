#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    float r, R, h;

    cout << "Введите радиус нижнего основания конуса: ";
    cin >> r;
    cout << "Введите радиус верхнего основания конуса: ";
    cin >> R;
    cout << "Введите высоту конуса: ";
    cin >> h;

    if (r <= 0 || R <= 0 || h <= 0)
    {
        cout << "Неверные данные";
        return 0;
    }

    if (r <= R)
    {
        cout << "Верхнее основание должно быть меньше нижнего";
        return 0;
    }

    float pi = 3.1415926535897;

    float l = sqrt((r - R) * (r - R) + h * h);

    float sq = pi * (R * R + (R + r) * l + r * r);
    float v = (pi * h * (R * R + (R * r) + r * r)) / 3.0;

    cout << "V = " << v << endl;
    cout << "S = " << sq;

    return 0;
}