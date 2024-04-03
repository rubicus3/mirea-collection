#include "const.h"

struct Node
{
    Node *next;
    Node *prev;
    string code, name, date;
    Node(string code, string name, string date);
    void print();
};

