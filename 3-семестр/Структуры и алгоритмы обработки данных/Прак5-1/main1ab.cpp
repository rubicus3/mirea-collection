#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    cout << "1.a" << endl;

    unsigned char x = 255;
    unsigned char maska = 1;

    for (int i = 0; i < 255; i+=34)
    {
        x = i;
        cout << "x: " << (int)x << endl;
        x = x & (~(maska << 4));
        cout << (int)x << endl;
    }

    cout << "1.б" << endl;


    for (int i = 0; i < 255; i += 37)
    {
        x = i;
        maska = 1;
        cout << "x: " << (int)x << endl;
        x = x | (maska << 6);
        cout << (int)x << endl;
    }
}
