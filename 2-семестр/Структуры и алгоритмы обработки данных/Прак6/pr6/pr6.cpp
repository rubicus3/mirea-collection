#include "List.h"

List get_list()
{
    List lst;
    vector<string> keys;

    for (auto const &imap : disciplines)
        keys.push_back(imap.first);
    for (int i = 0; i < 5; i++)
    {
        string theme = keys[rand() % 5];
        lst.push_back(theme, themes[theme][rand() % 5], dates[rand() % 40]);
    }
    return lst;
}

List create_list(vector<string> codes, vector<string> themes, vector<string> dates)
{
    List lst;
    for (int i = 0; i < codes.size(); i++)
    {
        lst.push_back(codes[i], themes[i], dates[i]);
    }
    return lst;
}

void menu()
{

    cout << "Двусвязный список: список тем уроков" << endl;
    cout << "Выберите команду из предложенных" << endl;
    cout << "1 - задать список вручную" << endl;
    cout << "2 - сгенерировать список" << endl;
    string comm;
    cin >> comm;
    List lst;
    if (comm == "1")
    {
        cout << "Введите количество элементов: ";
        int size = 0;
        cin >> size;
        vector<string> codes, themes, dates;
        cout << "Доступные темы: " << endl;
        for (auto const &imap : disciplines)
            cout << imap.first << " - " << imap.second << endl;
        cout << "Введите элементы списка через строку в формате: { код тема дата }: " << endl;
        for (int i = 0; i < size; i++)
        {
            string code, theme, date;
            cin >> code >> theme >> date;
            codes.push_back(code);
            themes.push_back(theme);
            dates.push_back(date);
        }
        lst = create_list(codes, themes, dates);
        cout << endl;
    }
    else if (comm == "2")
    {
        lst = get_list();
        cout << "Список сгенерирован" << endl;
    }
    else
    {
        cout << "Неизвестная команда" << endl;
        return;
    }

    while (true)
    {
        cout << "Выберите команду из предложенных" << endl;
        cout << "1 - вывести список слева направо" << endl;
        cout << "2 - вывести справа слева налево" << endl;
        cout << "3 - найти узел по ключу (коду дисциплины) и вывести " << endl;
        cout << "4 - вставить сведения по теме урока после последней темы с такой дисциплиной" << endl;
        cout << "5 - удалить все темы по ключу (коду дисциплины)" << endl;
        cout << "6 - выход" << endl;

        cin >> comm;
        if (comm == "1")
        {
            cout << endl;
            lst.print_l2r();
            cout << endl;
        }
        else if (comm == "2")
        {
            cout << endl;
            lst.print_r2l();
            cout << endl;
        }
        else if (comm == "3")
        {
            cout << "Введите код дисциплины: ";
            string code;
            cin >> code;
            lst.find(code)->print();
            cout << endl;
        }
        else if (comm == "4")
        {
            cout << "Введите новую запись в формате: { код тема дата }: ";
            string code, theme, date;
            cin >> code >> theme >> date;
            lst.insert(code, theme, date);

            cout << "Вставка успешна" << endl;
        }
        else if (comm == "5")
        {
            cout << "Введите код дисциплины: ";
            string code;
            cin >> code;
            lst.remove(code);
            cout << "Удаление успешно" << endl;
        }
        else if (comm == "6")
        {
            cout << "Выход..." << endl;
            return;
        }
    }
}

int main()
{
    menu();
    return 0;
}