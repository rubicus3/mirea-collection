#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include <set>
#include <chrono>

using namespace std::chrono;
using namespace std;

string streets[7]{"Ул. Ленина", "Пр. Верндадского", "Ул. Покрышкина", "Ул. Коротышкина", "Пр. Нахимовский", "Ул. Прямая", "Ул. Кривая"};
#define NUM_SIZE 11
#define ADDR_SIZE 50
long long int key = 88005553535;
string key_addr = "Пр. Вернадского Дом №86";

string linear_search(string file_name, long long int key){
    ifstream input(file_name + ".bin", ios::binary);

    char addr_buf[ADDR_SIZE + 1] = {0};
    long long int lnum;
    string result = "";

    auto start = high_resolution_clock::now();
    while(input.read(reinterpret_cast<char *>(&lnum), sizeof(lnum))) {
        input.read(addr_buf, ADDR_SIZE);

        if(lnum == key) {
            result = to_string(lnum) + " " + string(addr_buf); 
            break;
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();
    cout << file_name << ": Время: " << duration << " мкс." << endl;
    return result;
}

string binary_offset_search(string file_name, long long int key) {
    return "";
}

int main()
{
    linear_search("data100", key);
    linear_search("data1000", key);
    linear_search("data10000", key);

    binary_offset_search("data100", key);
    binary_offset_search("data1000", key);
    binary_offset_search("data10000", key);
    return 0;
}