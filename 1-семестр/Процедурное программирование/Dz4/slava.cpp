#include <iostream>

using namespace std;

int main()
{

    for (int i = 0; i < 13; i++)
    {
        if (i >= 1 && i <= 6)
        {
            cout << "* * * * * * ";
            for (int j = 0; j < 16; j++)
                cout << "---";
        }
        else
            for (int j = 0; j < 15; j++)
                cout << "----";
        cout << endl;
    }

    return 0;
}