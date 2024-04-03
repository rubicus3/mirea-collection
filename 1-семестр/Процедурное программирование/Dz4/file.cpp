#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");


    ofstream fout("file.txt"); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt

    int x;
    for(int i = 0; i < 10; i++){
        cin >> x;
        fout << x << "\n"; 
    }

    fout.close(); // закрываем файл

    ifstream fin("file.txt");
    string line;

    int sum = 0;
    while (getline(fin, line))
    {
        sum += stoi(line);
    }
    fin.close();

    cout << sum << endl;

    return 0;
}