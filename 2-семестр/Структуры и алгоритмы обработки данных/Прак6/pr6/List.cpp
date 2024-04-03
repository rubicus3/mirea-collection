#include "List.h"


List::List() : first(nullptr), last(nullptr){};

bool List::is_empty()
{
    return first == nullptr;
}

Node *List::find(string code)
{
    Node *p = first;
    while (p && p->code != code)
        p = p->next;
    return (p && p->code == code) ? p : nullptr;
}

void List::push_back(string code, string name, string date)
{
    Node *p = new Node(code, name, date);
    if (is_empty())
    {
        p->prev = nullptr;
        p->next = nullptr;
        first = p;
        last = p;
        return;
    }
    p->prev = last;
    last->next = p;
    last = p;
}

void List::insert(string code, string name, string date)
{
    Node *f = first;


    while (f->next && f->code != code)
    {
        f = f->next;
    }

    Node *p = new Node(code, name, date);

    Node *pr = f;
    Node *nx = f->next;

    pr->next = p;
    nx->prev = p;
    p->prev = pr;
    p->next = nx;
}

void List::remove_first()
{
    first = first->next;
    first->prev = nullptr;
}

void List::remove_last()
{
    last = last->prev;
    last->next = nullptr;
}

bool List::remove(string code)
{
    if (is_empty())
        return false;
    if (first->code == code)
    {
        remove_first();
        return true;
    }
    else if (last->code == code)
    {
        remove_last();
        return true;
    }

    Node *f = first->next;
    while (f && f->code != code)
    {
        f = f->next;
    }

    if (!f)
    {
        return false;
    }

    Node *pr = f->prev;
    Node *nx = f->next;

    nx->prev = pr;
    pr->next = nx;
    return true;
}

void List::remove_all(string code)
{
    while (remove(code))
    {
    }
}

void List::print_l2r()
{
    Node *p = first;

    while (p)
    {
        p->print();
        cout << endl;
        p = p->next;
    }
}

void List::print_r2l()
{
    Node *p = last;

    while (p)
    {
        p->print(); 
        cout << endl;
        p = p->prev;
    }
}
