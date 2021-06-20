#include "Union.h"

class Node
{
protected:
	Union value;
	Node *next;
public:
	Node* Get_next();
	Union Get_value();
	Node(Union value);
	friend class Stack;
};


Node::Node(Union value)
{
	this->value = value;
}
Node* Node::Get_next()
{
	return next;
}
Union  Node::Get_value()
{
	return value;
}