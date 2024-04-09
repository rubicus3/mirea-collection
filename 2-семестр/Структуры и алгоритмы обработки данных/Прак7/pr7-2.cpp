#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Node
{
    int val;
    Node *next;
    Node(int _val) : val(_val), next(nullptr) {}
    void print()
    {
        cout << val << " ";
    }
};

struct List
{
    Node *first;
    Node *last;
    List() : first(nullptr), last(nullptr) {}
    bool is_empty()
    {
        return first == nullptr;
    }
    void push_back(int _val)
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
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int depth = 0;
int count = 0;

List create_list(List list, vector<int> values)
{
    if (values.size() == 0)
    {
        count += 1;
        return list;
    }

    int _val = values[0];
    values.erase(values.begin());
    Node *p = new Node(_val);
    count += 2;

    if (list.is_empty())
    {
        list.first = p;
        list.last = p;
        count += 2;
    }
    else
    {
        list.last->next = p;
        list.last = p;
        count += 2;
    }
    depth += 1;
    return create_list(list, values);
}

void print_list(Node *p)
{
    cout << p->val << " ";
    if (p->next == nullptr)
        return;
    count += 2;
    depth += 1;
    print_list(p->next);
}

List create_list_r(vector<int> values)
{
    cout << "Рекурсивное созданиие списка" << endl;
    auto start = high_resolution_clock::now();
    depth = 0;
    count = 0;

    List list;
    list = create_list(list, values);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();
    cout << "Время выполнения: " << duration << " мкс." << endl;
    cout << "Количество операций: " << count << endl;
    cout << "Глубина: " << depth << endl;

    return list;
}

void print_list_r(List list)
{
    cout << "Рекурсивный вывод списка" << endl;
    auto start = high_resolution_clock::now();
    depth = 0;
    count = 0;

    print_list(list.first);
    cout << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();
    cout << "Время выполнения: " << duration << " мкс." << endl;
    cout << "Количество операций: " << count << endl;
    cout << "Глубина: " << depth << endl;
}

int main()
{
    vector<int> q = {8, 3, 1, 4, 5, 7, 4, 6, 7, 8, 5, 3, 5, 6, 7, 8, 5, 3, 4, 6, 8, 9, 7, 6, 5, 3, 2, 4, 3, 6, 4, 6, 7, 4, 4};
    List l = create_list_r(q);
    cout << endl;
    print_list_r(l);
    return 0;
}