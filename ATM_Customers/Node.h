
#ifndef NODE_H_
#define NODE_H_

#include "Customer.h"

class Node {
public:
	Node();
	~Node();
	Node(Customer* a);
	Node(Customer* a, Node* nd);
	Customer* customer;
	Node* next;


};

#endif /* NODE_H_ */
