#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    string text;

    getline(cin, text);

    ofstream fout("yay.txt"); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
    fout << text;             // запись строки в файл
    fout.close();             // закрываем файл

    string line;

    cout << endl;

    ifstream fin("yay.txt");
    while (getline(fin, line))
    {
        bool x = false;
        string res = "";

        for (int i = 0; i < line.length(); i++)
        {
            if (isdigit(line.at(i)))
            {
                res += line.at(i);
                x = true;
            }
            else
            {
                if (x)
                    res += " ";
                x = false;
            }
        }

        cout << res << endl;
    }
    fin.close();

    return 0;
}