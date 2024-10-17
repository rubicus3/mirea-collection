#include <iostream>
#include <vector>

using namespace std;

#define ul unsigned long long

// Entry
struct Node
{
    ul ISBN = 0; // Key value
    string author;
    string name;

    Node *next = nullptr;

    string get_print()
    {
        return to_string(ISBN) + " " + author + " " + name;
    }
};

// Bucket
struct LinkedList
{
    Node *first;
    Node *last;

    LinkedList() : first(nullptr), last(nullptr) {}

    bool is_empty()
    {
        return first == nullptr;
    }

    void push_back(ul ISBN, string author, string name)
    {
        Node *p = new Node(Node{ISBN, author, name});
        if (is_empty())
        {
            first = p;
            last = p;
            return;
        }
        if (find(ISBN) != nullptr) // Check for uniq
            return;

        last->next = p;
        last = p;
    }

    Node *find(ul _ISBN)
    {
        Node *p = first;
        while (p && p->ISBN != _ISBN)
            p = p->next;
        return (p && p->ISBN == _ISBN) ? p : nullptr;
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

    void remove(ul _ISBN)
    {
        if (is_empty())
            return;
        if (first->ISBN == _ISBN)
        {
            remove_first();
            return;
        }
        else if (last->ISBN == _ISBN)
        {
            remove_last();
            return;
        }

        Node *slow = first;
        Node *fast = first->next;
        while (fast && fast->ISBN != _ISBN)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast)
        {
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    int count()
    {
        if (is_empty())
            return 0;

        Node *p = first;
        int c = 1;
        while (p != last)
        {
            c += 1;
            p = p->next;
        }
        return c;
    }

    string get_print()
    {
        string result;
        if (is_empty())
            return "";

        Node *p = first;
        while (p)
        {
            result += p->get_print() + "\n";
            p = p->next;
        }
        return result;
    }
};

class HashMap
{
private:
    LinkedList *table;
    int size;

    ul hash_func(ul key)
    {
        return key % size;
    }

public:
    HashMap(int _size)
    {
        size = _size;
        table = new LinkedList[_size];
    }

    void insert(ul ISBN, string author, string name)
    {
        table[hash_func(ISBN)].push_back(ISBN, author, name);
    }

    void delete_entry(ul ISBN)
    {
        table[hash_func(ISBN)].remove(ISBN);
    }

    Node get(ul ISBN)
    {
        Node *found = table[hash_func(ISBN)].find(ISBN);
        if (found == nullptr)
            return Node{0, "None", "None"};
        return *found;
    }

    // Get func
    Node operator[](ul ISBN)
    {
        return get(ISBN);
    }

    float load_factor()
    {
        int n = 0;
        for (int i = 0; i < size; i++)
        {
            n += table[i].count();
        }
        return (float)n / (float)size;
    }

    bool rehash_table()
    {
        if (load_factor() < 0.75)
            return false;
        vector<Node *> tmp_array;
        for (int i = 0; i < size; i++)
            while (!table[i].is_empty())
            {
                tmp_array.push_back(table[i].first);
                table[i].remove_first();
            }
        delete table;

        size *= 2;
        table = new LinkedList[size];
        for (int i = 0; i < tmp_array.size(); i++)
            insert(tmp_array[i]->ISBN, tmp_array[i]->author, tmp_array[i]->name);
        for (int i = 0; i < tmp_array.size(); i++)
            delete tmp_array[i];

        return true;
    }

    string get_print() {
        string result = "";
        for (int i = 0; i < size; i++)
        {
            string r = table[i].get_print();
            if(r != "") {
                result += to_string(i) + " " + r;
            }
        }
        
        return result;
    }
};

void test()
{
    HashMap hashMap(5);

    hashMap.insert(123456789012, "John Doe", "Bang Bang");
    hashMap.insert(123456789013, "John ff", "Bang ss");
    hashMap.insert(123456789015, "John cc", "Bang bb");
    hashMap.insert(123459289015, "John bc", "Bang zz");
    hashMap.insert(123321389198, "Nom Jod", "Memes");

    cout << hashMap[123456789012].name << endl;
    cout << hashMap[819376789012].name << endl;

    hashMap.delete_entry(123456789012);
    hashMap.delete_entry(819376789012);

    cout << hashMap[123456789012].name << endl;
    cout << endl;
    hashMap.rehash_table();

    cout << hashMap[123456789015].name << endl;
    cout << hashMap[123456789012].name << endl;
    cout << hashMap[123459289015].name << endl;
    cout << hashMap[123321389198].name << endl;

    cout << hashMap.get_print();
}

int main()
{
    // test();

    HashMap hashMap(10);
    hashMap.insert(111111111111, "John Doe", "Bang Bang");
    hashMap.insert(222222222222, "Dohn Joe", "Gang Gang");
    hashMap.insert(333333333333, "Ohn Doj", "What");
    hashMap.insert(444444444444, "John Von", "C Language");
    hashMap.insert(555555555555, "Linus", "Linux");
    hashMap.insert(666666666666, "Windows", "Windows");
    hashMap.insert(777777777777, "Steve job", "Apple");
    hashMap.insert(888888888888, "Johnny Bravo", "Real Patriot");

    cout << "Командный интерфейс для управления хеш таблицей" << endl;
    cout << "В таблицу размера 8 занесены предустановленные записи с ключами:" << endl;
    cout << "111111111111, 222222222222, ... 888888888888" << endl;
    cout << "Ключи представляют собой 12-ти значные номера ISBN" << endl;
    cout << "С ними дополнительно хранятся автор и название книги" << endl;

    cout << "Меню: 0 - Получить элемент; 1 - Вствить элемент; 2 - Удалить элемент;" << endl;
    cout << "3 - Произвести рехеширование (Если фактор загрузки допускает); 4 - Вывод в консоль; 5 - Выход;" << endl;
    string command;
    while (true)
    {
        cout << "Введите команду: ";
        cin >> command;
        if (command == "0")
        {
            cout << "Введите номер ISBN: ";
            ul ISBN;
            cin >> ISBN;
            Node entry = hashMap[ISBN];
            cout << entry.ISBN << " " << entry.author << " " << entry.name << endl;
        }
        if (command == "1")
        {
            cout << "Введите значения через пробел ISBN автор название: ";
            ul ISBN;
            string author, name;
            cin >> ISBN >> author >> name;
            hashMap.insert(ISBN, author, name);
        }
        else if (command == "2")
        {
            cout << "Введите номер ISBN: ";
            ul ISBN;
            cin >> ISBN;
            hashMap.delete_entry(ISBN);
        }
        else if (command == "3")
        {
            if (hashMap.rehash_table())
                cout << "Рехеширование произведено" << endl;
            else
                cout << "Рехеширование не произведено (Фактор загрузки < 0.75)" << endl;
        }
        else if (command == "4") {
            cout << hashMap.get_print() << endl;
        }
        else if (command == "5")
        {
            break;
        }
    }
    return 0;
}