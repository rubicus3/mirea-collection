#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru_RU.utf8");
    string sub;
    cin >> sub;

    string ex[] = {"с", "т", "у","д","е","н","ч","е","с", "т", "в", "о",};

    for (int i = 0; i < 12; i++)
    {
            if (sub.find(ex[i]) == string::npos)
            {
                
                cout << "Не найдено" << endl;
                return 0;
            }
    }

    cout << "ОК";
    

    

    return 0;
}