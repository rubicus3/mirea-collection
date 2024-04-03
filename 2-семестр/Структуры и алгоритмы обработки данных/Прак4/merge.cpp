#include <iostream>
#include <fstream>

#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

using namespace std::chrono;

void mergeFiles(int chunkSize, int n)
{
    ifstream array("A.txt");

    ofstream lArr("B.txt");
    ofstream rArr("C.txt");

    int cl = 0;
    int cr = 0;
    bool q = true;
    string line;
    getline(array, line);
    int j = 0;
    while (j < n)
    {
        if (cl < chunkSize && q)
        {
            cl++;
            j++;
            lArr << line << endl;
            getline(array, line);
        }
        else
        {
            cl = 0;
            q = false;
        }
        if (cr < chunkSize && !q)
        {
            cr++;
            j++;
            rArr << line << endl;
            getline(array, line);
        }
        else
        {
            cr = 0;
            q = true;
        }
    }

    array.close();
    lArr.close();
    rArr.close();
    ifstream lSArr("B.txt");
    ifstream rSArr("C.txt");
    ofstream Arr("A.txt");

    int ch = 0;
    string l;
    string r;

    getline(lSArr, l);
    getline(rSArr, r);
    while (ch < n / 2)
    {
        int lq = 0;
        int rq = 0;

        while (lq < chunkSize && rq < chunkSize)
        {
            if (l <= r)
            {
                Arr << l << endl;
                lq++;
                getline(lSArr, l);
            }
            else
            {
                Arr << r << endl;
                rq++;
                getline(rSArr, r);
            }
        }

        while (lq < chunkSize)
        {
            Arr << l << endl;
            lq++;
            getline(lSArr, l);
        }
        while (rq < chunkSize)
        {
            Arr << r << endl;
            rq++;
            getline(rSArr, r);
        }

        ch += chunkSize;
    }
    lSArr.close();
    rSArr.close();
    Arr.close();
}

void mergeSortFiles(int n)
{
    auto start = high_resolution_clock::now();
    int ch = 1;
    while (ch <= n / 2)
    {
        mergeFiles(ch, n);
        ch = ch * 2;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();

    cout << "n = " << n << ": "
         << ", Время: " << duration << " мкс."
         << endl;
}

void fillFile()
{
    ifstream data("data.txt");
    ofstream A("A.txt");

    string line;
    A.clear();
    while(getline(data, line)){
        A << line << endl;
    }

    A.close();
    data.close();
}

int main()
{

    fillFile();
    mergeSortFiles(8);
    fillFile();
    mergeSortFiles(16);
    fillFile();
    mergeSortFiles(32);

    return 0;
}