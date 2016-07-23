/*
 * Node.h
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#ifndef NODE_H_
#define NODE_H_

#include "Customer.h"

class Node {
public:
    Node();
    Node(Customer cus);
    Node(Customer cus,Node *a, Node *b);
    void setCustomer(Customer cus);
    void setLeft(Node *a);
    void setRight(Node *b);
    Customer getCustomer();
    Node* getLeft();
    Node* getRight();
    friend class BSTree;

private:
    Customer customer;
    Node *left;
    Node *right;
    Node* parent;

};

#endif /* NODE_H_ */
