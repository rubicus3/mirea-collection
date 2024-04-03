#include <iostream>

using namespace std;

float max(float a, float b)
{
    if (a >= b)
        return a;
    return b;
}

int main()
{
    float a[3][4] = {
        {5, 2, 0, 10},
        {3, 5, 2, 5},
        {20, 0, 0, 0}};

    float b[4][2] = {
        {1.2, 0.5},
        {2.8, 0.4},
        {5.0, 1.0},
        {2.0, 1.5}};

    float c[3][2] = {
        {0.0, 0.0},
        {0.0, 0.0},
        {0.0, 0.0}};

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 2; col++)
        {
            for (int i = 0; i < 4; i++)
            {
                c[row][col] += a[row][i] * b[i][col];
            }
            cout << c[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int res1[2] = {
        1,
        1,
    };

    for (int i = 1; i < 3; i++)
    {
        if (c[i][0] - c[i][1] > c[i - 1][0] - c[i - 1][1])
            res1[0] = i + 1;
        else
            res1[1] = i + 1;
    }

    int res2[2] = {
        1,
        1,
    };
    for (int i = 1; i < 3; i++)
    {
        if (c[i][1] > c[i - 1][1])
            res2[0] = i + 1;
        else
            res2[1] = i + 1;
    }
    float res3 = 0, res4 = 0, res5 = 0;
    for (int i = 0; i < 3; i++)
    {
        res3 += c[i][0] - c[i][1];
        res4 += c[i][1];
        res5 += c[i][0] + c[i][1];
    }

    cout << "Продавец с наибольшей выручкой: " << res1[0] << ", с наименьшей: " << res1[1] << endl;
    cout << "Продавец с наибольшей комиссионной: " << res2[0] << ", с наименьшей " << res2[1] << endl;
    cout << "Общая выручка: " << res3 << endl;
    cout << "Общие комиссионные: " << res4 << endl;
    cout << "Прошедшие деньги: " << res5 << endl;

    return 0;
}