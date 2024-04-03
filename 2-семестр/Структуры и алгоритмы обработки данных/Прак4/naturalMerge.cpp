#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

using namespace std::chrono;

const int BLOCK_SIZE = 1024;

void sort_block(vector<string> &block)
{
    sort(block.begin(), block.end());
}

void merge_blocks(const vector<string> &block1, 
const vector<string> &block2, vector<string> &output)
{
    int i = 0, j = 0;
    while (i < block1.size() && j < block2.size())
    {
        if (block1[i] < block2[j])
        {
            output.push_back(block1[i++]);
        }
        else
        {
            output.push_back(block2[j++]);
        }
    }
    while (i < block1.size())
    {
        output.push_back(block1[i++]);
    }

    while (j < block2.size())
    {
        output.push_back(block2[j++]);
    }
}

void naturalMergeSort(const string &input_filename, const string &output_filename)
{
    ifstream input(input_filename);
    ofstream output(output_filename);
    vector<string> block;
    while (true)
    {
        block.clear();
        for (int i = 0; i < BLOCK_SIZE; i++)
        {
            string line;
            getline(input, line);
            if (line.empty())
            {
                break;
            }
            block.push_back(line);
        }
        sort_block(block);
        if (block.size() < BLOCK_SIZE)
        {
            for (const string &line : block)
            {
                output << line << endl;
            }
            break;
        }
        string temp_filename = "temp.txt";
        ofstream temp(temp_filename);
        for (const string &line : block)
        {
            temp << line << endl;
        }
        temp.close();
        naturalMergeSort(temp_filename, output_filename);
        remove(temp_filename.c_str());
    }
    input.close();
    output.close();
}

void nmc(int n, const string &input_filename, const string &output_filename)
{

    auto start = high_resolution_clock::now();

    naturalMergeSort(input_filename, output_filename);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();
    cout << "n = " << n << ": "
         << ", Время: " << duration << " мкс."
         << endl;
}

void fillFile(int n)
{
    ifstream data("data.txt");
    ofstream A("A.txt");

    string line;
    A.clear();
    int i = 0;
    while (i < n)
    {
        getline(data, line);
        A << line << endl;
        i++;
    }

    A.close();
    data.close();
}

int main()
{
    int n = 8;
    fillFile(n);
    nmc(n, "A.txt", "output.txt");

    n = 16;
    fillFile(n);
    nmc(n, "A.txt", "output.txt");
    
    n = 32;
    fillFile(n);
    nmc(n, "A.txt", "output.txt");

    return 0;
}