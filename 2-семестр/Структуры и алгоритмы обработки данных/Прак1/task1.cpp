#include <iostream>
#include <vector>
#include <random>

using namespace std;

int rnd()
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> d(1, 9);

    return d(rng);
}

void genRandomArray(int *x, int n)
{
    for (int i = 0; i < n; i++)
    {
        x[i] = rnd();
    }
}

void printArr(int *x, int n)
{
    cout << "n = " << n << ": ";
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}


int delFirstMethod(int *x, int n, int key)
{
    int i = 0;
    int op_count = 2; // инициализация переменной i и сравнение в цикле
    while (i < n)
    {
        op_count++; // условие цикла
        op_count++; // сравнение в условном операторе
        if (x[i] == key)
        {
            op_count++; // инициализация переменной j
            for (int j = i; j < n; j++)
            {
                op_count++; // сравнение в цикле
                x[j] = x[j + 1];
                op_count++; // перемещение элементов
            }
            n -= 1;
            op_count++; // уменьшение n
        }
        else
        {   
            i += 1;
            op_count++; // увеличение i
        }
    }

    op_count++; // возврат n
    cout << "delFirstMethod кол-во операций: " << op_count << endl;

    return n;
}

int delOtherMethod(int *x, int n, int key)
{
    int j = 0;
    int op_count = 2; // инициализация переменной i и j
    for (int i = 0; i < n; i++)
    {
        op_count += 1; // сравнение в цикле
        x[j] = x[i];
        op_count += 1; // перемещение элементов

        op_count += 1; // условынй оператор
        if (x[i] != key)
        {
            op_count += 1; // увеличивание j
            j++;
        };
    }

    op_count += 1; // присваивание
    n = j;

    op_count += 1; // возврат n

    cout << "delOtherMethod кол-во операций: " << op_count << endl;
    return n;
}

int main()
{
    int n = 10;
    int *x = new int[n];
    int key = 2;
    cout << "Тестирование для n = " << n << ", key = " << key << endl;
    cout << endl;

    

    cout << "Тестирование: Случайный массив" << endl;
    genRandomArray(x, n);
    printArr(x, n);
    n = delOtherMethod(x, n, key);
    printArr(x, n);

    cout << endl;


    cout << "Тестирование: Лучший массив" << endl;
    n = 10;
    x = new int[n]{2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    printArr(x, n);
    n = delOtherMethod(x, n, key);
    printArr(x, n);

    cout << endl;


    cout << "Тестирование: Худший массив" << endl;
    n = 10;
    x = new int[n]{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    printArr(x, n);
    n = delOtherMethod(x, n, key);
    printArr(x, n);

    // cin >> n;
    // genRandomArray(x, n);
    // n = delFirstMethod(x, n, key);
    // printArr(x, n);

    

    // n = 10;
    // int *y = new int[n]{1, 2, 3, 2, 2, 2, 5, 2, 2, 2};
    // n = delOtherMethod(y, n, key);
    // printArr(y, n);
    delete x;
    return 0;
}