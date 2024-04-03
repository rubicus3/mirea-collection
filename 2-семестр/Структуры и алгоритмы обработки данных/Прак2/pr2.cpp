#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

using namespace std::chrono;

int rnd()
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> d(1, 9);

    return d(rng);
}

void getRandomArray(int *x, int n)
{
    for (int i = 0; i < n; i++)
    {
        x[i] = rnd();
    }
}

void getAscArray(int *x, int n)
{
    for (int i = 0; i < n; i++)
    {
        x[i] = i;
    }
}

void getDescArray(int *x, int n)
{
    for (int i = 0; i < n; i++)
    {
        x[i] = n - i;
    }
}

void printArr(int *x, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

void insertionSort(int *x, int n)
{
    long long int move_count = 0;
    long long int comp_count = 0;
    auto start = high_resolution_clock::now();

    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = x[i];


        j = i - 1;

        comp_count += 1;
        while (j >= 0 && x[j] > key)
        {
            comp_count += 1;
            
            move_count += 1;
            x[j + 1] = x[j];
            j -= 1;
        }

        x[j + 1] = key;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();

    cout << "n = " << n << ": "
         << "Сравнений - " << comp_count
         << ", Перемещений - " << move_count
         << ", Время: " << duration << " мс."
         << ", Всего операций: " << comp_count + move_count
         << endl;
}

void exchangeSort(int *x, int n)
{
    long long int move_count = 0;
    long long int comp_count = 0;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            comp_count += 1;
            if (x[i] > x[j])
            {
                move_count += 1;
                int temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();

    cout << "n = " << n << ": "
         << "Сравнений - " << comp_count
         << ", Перемещений - " << move_count
         << ", Время: " << duration << " мс."
         << endl;
}

int main()
{
    int n;
    int *x;

    cout << "Сортировка простой вставки (Случайный массив)" << endl;

    n = 100;
    x = new int[n];
    getRandomArray(x, n);
    insertionSort(x, n);

    n = 1000;
    x = new int[n];
    getRandomArray(x, n);
    insertionSort(x, n);

    n = 10000;
    x = new int[n];
    getRandomArray(x, n);
    insertionSort(x, n);

    n = 100000;
    x = new int[n];
    getRandomArray(x, n);
    insertionSort(x, n);

    cout << endl << "Сортировка простой вставки (Лучший случай)" << endl;

    n = 100;
    x = new int[n];
    getAscArray(x, n);
    insertionSort(x, n);

    n = 1000;
    x = new int[n];
    getAscArray(x, n);
    insertionSort(x, n);

    n = 10000;
    x = new int[n];
    getAscArray(x, n);
    insertionSort(x, n);

    n = 100000;
    x = new int[n];
    getAscArray(x, n);
    insertionSort(x, n);

    cout << endl << "Сортировка простой вставки (Худший случай)" << endl;

    n = 100;
    x = new int[n];
    getDescArray(x, n);
    insertionSort(x, n);

    n = 1000;
    x = new int[n];
    getDescArray(x, n);
    insertionSort(x, n);

    n = 10000;
    x = new int[n];
    getDescArray(x, n);
    insertionSort(x, n);

    n = 100000;
    x = new int[n];
    getDescArray(x, n);
    insertionSort(x, n);


    delete x;

    return 0;
}