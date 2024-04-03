#include "Node.h"

Node::Node(string code, string name, string date)
{
    this->code = code;
    this->name = name;
    this->date = date;
}

void Node::print() 
{
    cout << disciplines[code] << " " << name << " " << date;
}
