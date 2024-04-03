#include <iostream>

using namespace std;

float solveRectangle()
{
    cout << "Введите длины сторон" << endl;
    float a, b;
    cin >> a >> b;
    return a * b;
}

float solveTriangle()
{
    cout << "Введите длины основания и высоты" << endl;
    float a, b;
    cin >> a >> b;
    return 0.5 * a * b;

}

float solveCircle()
{
    cout << "Введите радиус окружности" << endl;
    float r;
    cin >> r;
    return 3.1415926535897932 * r;
}

int main()
{
    cout << "1: Прямоугольник" << endl;
    cout << "2: Треугольник" << endl;
    cout << "3: Круг" << endl;
    cout << "Выберите фигуру (1/2/3): ";

    int figure;
    cin >> figure;
    cout << endl;

    float result;
    switch (figure)
    {
    case 1:
        result = solveRectangle();
        break;
    case 2:
        result = solveTriangle();
        break;
    case 3:
        result = solveCircle();
        break;

    default:
        break;
    }

    cout << result << endl;
    return 0;
}