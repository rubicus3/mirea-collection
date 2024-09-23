#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <random>
#include <set>

using namespace std;

string streets[7] {"Ул. Ленина", "Пр. Верндадского", "Ул. Покрышкина", "Ул. Коротышкина", "Пр. Нахимовский", "Ул. Прямая", "Ул. Кривая"};
#define NUM_SIZE 11
#define ADDR_SIZE 50
long long int key = 88005553535;
string key_addr = "Пр. Вернадского Дом №86";

long long int rnd()
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> d(1, 9999999999);

    return d(rng);
}

int rnd2()
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> d(0, 6);

    return d(rng);
}

int rnd3()
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> d(0, 255);

    return d(rng);
}


void generate_file(int file_size, string file_name) {

    // Генерация txt файла
    ofstream file(file_name + ".txt");
    set<long long int> uniqs;
    uniqs.insert(key);
    
    for (int i = 0; i < file_size - 1; i++)
    {
        // Уникальная генерация
        long long int unum = rnd();
        while(!uniqs.insert(unum).second) {
            unum = rnd();
        }
        string num = to_string(unum);
        string addr = streets[rnd2()] + " Дом №" + to_string(rnd3());

        num.insert(0, NUM_SIZE - num.length() - 1, '0');
        num = "8" + num;
        addr.insert(addr.end(), 50 - addr.size(), '9');

        file << num << ";" << addr << endl;
    }
    key_addr.insert(key_addr.end(), 50 - key_addr.size(), ' ');
    file << key << ";" << key_addr;
    file.close();

    ifstream txtfile(file_name + ".txt");
    ofstream binfile(file_name + ".bin", ios::binary | ios::out);
    string line;

    while(getline(txtfile, line)) {
        istringstream ss(line);
        string num, addr;
        long long int lnum;

        getline(ss, num, ';');
        getline(ss, addr);

        lnum = stoll(num);
        char addr_buf[ADDR_SIZE];
        strcpy(addr_buf, addr.c_str());

        binfile.write(reinterpret_cast<char *>(&lnum), sizeof(lnum));
        binfile.write(addr_buf, ADDR_SIZE);
    }
    
}


int main() {
    generate_file(100, "data100");
    generate_file(1000, "data1000");
    generate_file(10000, "data10000");    

    return 0;
}