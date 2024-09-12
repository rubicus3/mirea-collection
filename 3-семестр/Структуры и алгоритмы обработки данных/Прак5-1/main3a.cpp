#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    const int size = 1024 * 1024;
    vector<unsigned char> xarr(size);
    unsigned char mask = 1;
    int t, j, k, m;

    ifstream infile("nums.txt");
    string line;
    while(getline(infile, line))
    {
        unsigned int t = stoi(line);
        j = floor(t / 8);
        k = t - 8 * j;
        m = mask << (8 - k - 1);
        xarr[j] = xarr[j] | m;
    }

    infile.close();
    ofstream output("sorted.txt"); 
    for (unsigned int i = 0; i < size; i++)
    {
        mask = 128;
        for (unsigned short j = 0; j < 8; j++)
        {
            if (xarr[i] & mask)
                output << 8 * i + j << "\n";
            mask = mask >> 1;
        }
    }
    return 0;
}