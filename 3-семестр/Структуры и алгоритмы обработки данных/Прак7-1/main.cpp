#include <iostream>

using namespace std;

struct Node
{
    string key = "";
    unsigned char height;

    Node *left;
    Node *right;
    Node(string k)
    {
        key = k;
        left = right = 0;
        height = 0;
    }
};

unsigned char height(Node *p)
{
    return p ? p->height : 0;
}

int bfactor(Node *p)
{
    return height(p->right) - height(p->left);
}

void fixheight(Node *p)
{
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = (hl > hr ? hl : hr) + 1;
}

Node *rotateright(Node *p)
{
    Node *q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

Node *rotateleft(Node *q)
{
    Node *p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

Node *balance(Node *p)
{
    fixheight(p);
    if (bfactor(p) == 2)
    {
        if (bfactor(p->right) < 0)
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if (bfactor(p) == -2)
    {
        if (bfactor(p->left) > 0)
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p; // балансировка не нужна
}

Node *insert(Node *p, string k) // вставка ключа k в дерево с корнем p
{
    if (!p)
        return new Node(k);
    if (k < p->key)
        p->left = insert(p->left, k);
    else
        p->right = insert(p->right, k);
    return balance(p);
}

int find_height(const Node *p, const string key, int height = 0)
{
    if (!p)
        return -1;
    if (p->key == key)
        return height;
    if (key < p->key)
        return find_height(p->left, key, height + 1);
    return find_height(p->right, key, height + 1);
}

void symmetric_out(Node *p)
{
    if (!p) return;
    symmetric_out(p->left);
    cout << p->key << " ";
    symmetric_out(p->right);
}

void reverse_out(Node *p)
{
    if (!p) return;
    reverse_out(p->left);
    reverse_out(p->right);
    cout << p->key << " ";
}

void printBT(const string &prefix, const Node *node, bool isLeft)
{
    if (!node)
        return;
    cout << prefix;
    cout << (isLeft ? "├──" : "└──");
    cout << node->key << endl;
    printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
    printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
}

void printBT(const Node *node)
{
    printBT("", node, false);
}

void menu()
{
    cout << "АВЛ-дерево. Узел: Строка-город" << endl;
    cout << "Введите номер команды:" << endl;
    cout << "0 - Вывод дерева" << endl;
    cout << "1 - Вставка элемента (с балансировкой)" << endl;
    cout << "2 - Обратный обход" << endl;
    cout << "3 - Симметричный обход" << endl;
    cout << "4 - Найти длину от корня до заданного значения" << endl;
    cout << "5 - Найти высоту дерева" << endl;
    cout << "exit - Выход" << endl;
    string command;

    Node *root = nullptr;

    while (true)
    {
        cout << "Введите номер команды: ";
        cin >> command;
        if (command == "0")
            printBT(root);
        else if (command == "1")
        {
            string name;
            cout << "Введите имя узла: ";
            cin >> name;
            if (!root)
                root = new Node(name);
            else
                root = insert(root, name);
        }
        else if (command == "2")
        {
            reverse_out(root);
            cout << endl;
        }
        else if (command == "3")
        {
            symmetric_out(root);
            cout << endl;
        }
        else if (command == "4")
        {
            string name;
            cout << "Введите имя узла: ";
            cin >> name;
            int res = find_height(root, name);
            if (res < 0)
                cout << "Не найдено элемента с таким названием" << endl;
            else
                cout << res << endl;
        }
        else if (command == "5")
        {
            cout << (unsigned int)height(root) << endl;
        }
        else if (command == "exit")
        {
            cout << endl;
            break;
        }
    }
}

int main()
{
    menu();
    return 0;
}