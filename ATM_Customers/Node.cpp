
#include "Node.h"
Node::Node()
{
	customer = 0;
	next = 0;
}

Node::Node(Customer* a)
{
	customer = a;
	next = 0;
}

Node::Node(Customer* a, Node* nd)
{
	customer = a;
	next = nd;
}

Node::~Node()
{

}



// TO DO:: Fill in.
