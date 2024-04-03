#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    float x, y, b;
    
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;

    if (b < y || b < x)
    {
        cout << "Undefined";
        return 0;
    }

    cout << log(b - y) * sqrt(b - x);
    return 0;
}