/*
 * Node.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "Node.h"

Node::Node(){

    left = 0;
    right = 0;
    parent = 0;
}
Node::Node(Customer cus){
    left = 0;
    right = 0;
    parent = 0;
    customer = cus;
}
Node::Node(Customer cus,Node *a, Node *b){
    customer = cus;
    left = a;
    right = b;

}
void Node::setCustomer(Customer cus){
    customer = cus;
}
void Node::setLeft(Node *a){
    left = a;
}
void Node::setRight(Node *b){
    right = b;
}
Customer Node::getCustomer(){
    return customer;
}

Node* Node::getLeft(){
    return left;
}
Node* Node::getRight(){
    return right;
}
