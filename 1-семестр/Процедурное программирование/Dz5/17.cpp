#include <iostream>
#include <fstream>
#include <vector>

#include <cstring>
using namespace std;



int main()
{
    string a = "abcd", b = "dbca", line;

    string text;

    vector<string> res;

    ifstream fin("alp.txt");
    while (getline(fin, line, ' '))
    {
        res.push_back(line);
    }

    int d = res.size();

    for (int gap = d / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < d; i += 1)
        {
            string temp = res[i];

            int j;
            for (j = i; j >= gap && res[j - gap] > temp; j -= gap)
                res[j] = res[j - gap];

            res[j] = temp;
        }
    }

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    fin.close();
    return 0;
}