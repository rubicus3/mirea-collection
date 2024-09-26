#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include <set>
#include <map>
#include <chrono>
#include <cmath>
#include <algorithm>

using namespace std::chrono;
using namespace std;

string streets[7]{"Ул. Ленина", "Пр. Верндадского", "Ул. Покрышкина", "Ул. Коротышкина", "Пр. Нахимовский", "Ул. Прямая", "Ул. Кривая"};
#define NUM_SIZE 11
#define ADDR_SIZE 50

string linear_search(string file_name, long long int key)
{
    ifstream input(file_name + ".bin", ios::binary);

    char addr_buf[ADDR_SIZE + 1] = {0};
    long long int lnum;
    string result = "";

    auto start = high_resolution_clock::now();
    while (input.read(reinterpret_cast<char *>(&lnum), sizeof(lnum)))
    {
        input.read(addr_buf, ADDR_SIZE);

        if (lnum == key)
        {
            result = to_string(lnum) + " " + string(addr_buf);
            break;
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();
    cout << file_name << ": Время: " << duration << " мкс." << endl;

    input.close();
    return result;
}

string binary_offset_search(string file_name, long long int key)
{
    ifstream input(file_name + ".bin", ios::binary);

    char addr_buf[ADDR_SIZE + 1] = {0};
    long long int lnum;

    // Initializing offset table
    vector<pair<long long int, int>> offset_table;
    int offset = sizeof(long long int) + ADDR_SIZE;
    int size = 0;
    while (input.read(reinterpret_cast<char *>(&lnum), sizeof(lnum)))
    {
        input.read(addr_buf, ADDR_SIZE);
        offset_table.push_back(pair<long long int, int>(lnum, offset * size));
        size += 1;
    }

    sort(offset_table.begin(), offset_table.end(), [](auto a, auto b)
         { return a.first < b.first; });

    auto start = high_resolution_clock::now();

    // Uniform Binary search
    long long int found = 0;
    int pow = 1;
    int curr_position = 0;
    do
    {
        pow <<= 1;
        offset = (size + (pow >> 1)) / pow;

        if (offset_table[curr_position].first == key)
        {
            found = curr_position;
            break;
        }
        else if (offset_table[curr_position].first < key)
        {
            curr_position += offset;
        }
        else
        {
            curr_position -= offset;
        }

    } while (offset > 0);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start).count();
    cout << file_name << ": Время: " << duration << " нс." << endl;

    // Get result
    input.seekg(offset_table[found].second); // Offset bits based on offset table data
    input.read(reinterpret_cast<char *>(&lnum), sizeof(lnum));
    input.read(addr_buf, ADDR_SIZE);
    string result = to_string(lnum) + " " + string(addr_buf);

    input.close();
    return result;
}

int main()
{
    long long int key = 88005553535;

    cout << "Linear search" << endl;
    linear_search("data100", key);
    linear_search("data1000", key);
    linear_search("data10000", key);

    cout << endl
         << "Binary search" << endl;
    binary_offset_search("data100", key);
    binary_offset_search("data1000", key);
    binary_offset_search("data10000", key);
    return 0;
}
