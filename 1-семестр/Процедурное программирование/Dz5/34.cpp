#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

    ifstream fin("pal.txt");
    string line;

    string sub;
    cout << "Введите подстроку: ";
    cin >> sub;

    int col = 1;
    while (getline(fin, line))
    {
        int i = 0;
        while(i < sizeof(line))
        {
            if (line.find(sub) != string::npos)
            {
                int pos = line.at(line.find_first_of(sub, i));

                cout << "Найдено в " << col << " строке на " << pos << " позиции";

                i += pos;
            }
            else
                break;
        }
        col += 1;
    }

    fin.close();
    return 0;
}