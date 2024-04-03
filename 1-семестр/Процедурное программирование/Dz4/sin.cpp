#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int oy = 40, ox = 60;

    string a[oy][ox];

    for (int i = 0; i < oy; i++)
    {
        for (int j = 0; j < ox; j++)
        {
            a[i][j] = " ";
        }
    }

    for (float rx = 0; rx < ox / 10; rx+= 0.1)
    {
        float res = sin(rx);

        int y = round(res * (oy / 2)) + (oy / 2);
        int x = rx * 10;

        if(y == oy) y--;
        if(x == ox) x--;

        cout << x <<  " " << y << endl; 

        a[y][x] = "*";
    }

    for (int i = 0; i < oy; i++)
    {
        for (int j = 0; j < ox; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}