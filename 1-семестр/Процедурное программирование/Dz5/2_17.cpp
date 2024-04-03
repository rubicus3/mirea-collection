#include <iostream>
#include <cmath>


using namespace std;


int factorial(int k) {
    int res = 1;

    for (int i = 2; i <= k; i++)
    {
        res *= i;
    }

    return res;
    
}


int main()
{
    cout << "Введите x: ";

    float x;
    double eps = pow(10, -6);
    cin >> x;
    double a0 = 2 / pow(x, 2);

    double a;

    int k = 1;
    while(true) {
        a = (double) factorial(k + 2) / (double) (pow(k + 1, 2) * pow(x, 2 * k + 2));

        cout << fabs(a - a0) << " " << a << " " << a0<< endl;
        if(fabs(a - a0) < eps) {
            break;
        }   
        k += 1;
        a0 = a;
    }

    cout << "Результат: " << a << endl;

    return 0;
}