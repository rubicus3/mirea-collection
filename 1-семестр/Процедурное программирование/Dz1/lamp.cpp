#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    string lamp, shtora, time;

    cout << "Лампа включена? (Да / Нет): ";
    cin >> lamp;

    if (lamp == "Да")
    {
        cout << "Светло";
        return 0;
    }

    cout << "На улице день? (Да / Нет): ";
    cin >> time;

    cout << "Шторы задвинуты? (Да / Нет): ";
    cin >> shtora;

    if (time == "Да" && shtora == "Нет")
    {
        cout << "Светло";
        return 0;
    }

    cout << "Темно";
    return 0;
}