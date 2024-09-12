#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    cout << endl
         << "Код задания (1.в)" << endl;

    unsigned int x = 25;
    const int n = sizeof(int) * 8;
    unsigned int maska = (1 << n - 1);
    cout << "Начальный вид маски: " << bitset<n>(maska) << endl;
    cout << "Результат: ";

    // Алгоритм выводит каждый бит числа используя маску сдвигая единицу маски вправо каждую итерацию 
    for (int i = 1; i <= n; i++)
    {
        cout << ((x & maska) >> (n - i));
        maska = maska >> 1; 
    }
    cout << endl;

    return 0;
}