#include "headers.h"

struct Node
{
    pair<int, float> val;
    Node *next;
    Node(pair<int, float> _val) : val(_val), next(nullptr) {}
    void print()
    {
        if(val.second == 0) return;
        if (val.first == 0) cout << val.second;
        else if (val.first == 1) cout << "x";
        else if (val.second == 1) cout << "x^" << val.first;
        else cout << val.second << "x^" << val.first;
    }
    void edit_val(pair<int, float> _val) { this->val = _val; }
};

struct list
{
    Node *first;
    Node *last;
    list() : first(nullptr), last(nullptr) {}
    bool is_empty()
    {
        return first == nullptr;
    }
    void push_back(pair<int, float> _val)
    {
        Node *p = new Node(_val);
        if (is_empty())
        {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }
    void print()
    {
        if (is_empty())
            return;
        Node *p = first;
        while (p)
        {
            p->print();
            if (p->next != nullptr && p->val.second != 0)
                cout << " + ";
            p = p->next;
        }
        cout << endl;
    }
    Node *find(pair<int, float> _val)
    {
        Node *p = first;
        while (p && p->val != _val)
            p = p->next;
        return (p && p->val == _val) ? p : nullptr;
    }

    void insert_first(float coef)
    {
        // Создание нового узла
        Node *p = new Node(pair<int, float>{0, coef});
        // Задание ему следующего как первого текущего
        p->next = first;
        // Замена первого на новый узел
        first = p;

        p = p->next;
        while (p->next != nullptr)
        {
            p->edit_val(pair<int, float>{p->val.first + 1, p->val.second});
            p = p->next;
        }
    }

    void remove_first()
    {
        first = first->next;
    }
    void remove_last()
    {
        Node *p = first;
        while (p->next != last)
        {
            p = p->next;
        }
        last = p;
        p->next = nullptr;
    }

    void remove(int power)
    {
        if (is_empty())
            return;
        if (first->val.first == power)
        {
            remove_first();
            return;
        }
        else if (last->val.first == power)
        {
            remove_last();
            return;
        }
        Node *slow = first;
        Node *fast = first->next;
        while (fast && fast->val.first != power)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast)
        {
            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    // Рекурсивный подсчёт значения при заданном x по схеме горнера
    float calc_x(float x, Node *p)
    {
        if (p->next == nullptr)
        {
            return p->val.second;
        }

        return p->val.second + x * calc_x(x, p->next);
    }
};

int rnd()
{
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> d(0, 9);

    return d(rng);
}

list get_list()
{
    list lst;
    for (int i = 0; i < 11; i++)
    {
        pair<int, float> a = {i, rnd()};
        lst.push_back(a);
    }
    return lst;
}

list create_list(vector<float> coefs)
{
    list lst;
    for (int i = 0; i < coefs.size(); i++)
    {
        pair<int, float> a = {i, coefs[i]};
        lst.push_back(a);
    }
    return lst;
}

void menu()
{
    cout << "Односвязный список: линейный многочлен n-ой степени" << endl;
    cout << "Выберите команду из предложенных" << endl;
    cout << "1 - задать список вручную" << endl;
    cout << "2 - сгенерировать список" << endl;
    string comm;
    cin >> comm;
    list lst;
    if (comm == "1")
    {
        cout << "Введите количество элементов: ";
        int size = 0;
        cin >> size;
        vector<float> coefs;
        cout << "Введите коэффиценты многочлена: ";
        for (int i = 0; i < size; i++)
        {
            float el;
            cin >> el;
            coefs.push_back(el);
        }
        lst = create_list(coefs);
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
        cout << "1 - вывести список" << endl;
        cout << "2 - вставить значение перед первым элементом" << endl;
        cout << "3 - вычислить значение многочлена при заданном x" << endl;
        cout << "4 - удалить значение по ключу (степени)" << endl;
        cout << "5 - выход" << endl;

        cin >> comm;
        if (comm == "1")
        {
            cout << endl;
            lst.print();
            cout << endl;
        }
        else if (comm == "2")
        {
            cout << "Введите коэффицент: ";
            int cskn;
            cin >> cskn;
            lst.insert_first(cskn);
            cout << "Вставка успешна" << endl;
        }
        else if (comm == "3")
        {
            cout << "Введите x: ";
            int x;
            cin >> x;
            cout << "Вычисленная сумма: " << lst.calc_x(x, lst.first) << endl;
        }
        else if (comm == "4")
        {
            cout << "Введите степень перед x: ";
            int x;
            cin >> x;
            lst.remove(x);
            cout << "Удаление успешно" << endl;
        }
        else if (comm == "5")
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
