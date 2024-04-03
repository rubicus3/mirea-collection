#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

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

long long int move_count = 0;
long long int comp_count = 0;

void merge(int *array, int const left, int const mid,
           int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        move_count += 1;
        comp_count += 2;   
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        comp_count += 1;
        move_count += 1;
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    comp_count += 1;



    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        comp_count += 1;
        move_count += 1;
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    comp_count += 1;

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int *x, int begin, int end)
{
    if (begin < end)
    {
        int mid = floor((begin + end) / 2);
        mergeSort(x, begin, mid);
        mergeSort(x, mid + 1, end);
        merge(x, begin, mid, end);
    }
}

void mmemem(int *x, int begin, int end)
{
    move_count = 0;
    comp_count = 0;
    auto start = high_resolution_clock::now();

    mergeSort(x, begin, end);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start).count();

    cout << "n = " << end + 1 << ": "
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

    // Внешний цикл
    for (int i = 0; i < n - 1; i++)
    {
        bool iver = true;
        // Внутренний цикл
        for (int j = i + 1; j < n; j++)
        {
            comp_count += 1;

            // Сравнение
            if (x[i] > x[j])
            {
                iver = false;
                move_count += 1;
                // Перемещение
                int temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
        // Завершение сортировки по условию Айверсона
        if (iver)
            break;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start).count();

    cout << "n = " << n << ": "
         << "Сравнений - " << comp_count
         << ", Перемещений - " << move_count
         << ", Время: " << duration << " мс."
         << ", Всего операций: " << comp_count + move_count
         << endl;
}

int main()
{
    int n;
    int *x;

    cout << "Сортировка простым слиянием (Случайный массив)" << endl;

    n = 100;
    x = new int[n];
    getRandomArray(x, n);
    mmemem(x, 0, n - 1);

    cout << endl;

    
    n = 1000;
    x = new int[n];
    getRandomArray(x, n);
    mmemem(x, 0, n - 1);


    cout << endl;
    
    n = 10000;
    x = new int[n];
    getRandomArray(x, n);
    mmemem(x, 0, n - 1);

    cout << endl;
    
    n = 100000;
    x = new int[n];
    getRandomArray(x, n);
    mmemem(x, 0, n - 1);

    cout << endl;

    n = 1000000;
    x = new int[n];
    getRandomArray(x, n);
    mmemem(x, 0, n - 1);

    cout << endl;
    
    return 0;
}