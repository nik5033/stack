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
