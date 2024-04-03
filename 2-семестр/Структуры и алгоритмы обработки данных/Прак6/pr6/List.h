#include "Node.h"


struct List
{
    Node *first;
    Node *last;

    List();
    bool is_empty();
    Node *find(string code);

    void push_back(string code, string name, string date);
    void insert(string code, string name, string date);

    void remove_first();
    void remove_last();
    bool remove(string code);
    void remove_all(string code);


    void print_l2r();
    void print_r2l();
};