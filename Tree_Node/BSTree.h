/*
 * BSTree.h
 *
 */

#ifndef BSTREE_H_
#define BSTREE_H_

#include "Customer.h"
#include "Node.h"
#include<vector>
#include<string>
using namespace std;

class BSTree {
public:
	BSTree();
        BSTree(const BSTree & rbt);
        void copyTree(Node *treeP,Node *&newP);
        virtual ~BSTree();
        void destroy(Node* n);
        bool insert(string, char, int);
        void insertTwo(Customer cus,Node *&r);
        void inorder(Node* p);
        bool search(string x, char y);
        Node* search(Customer cus, Node* aRoot);
        bool remove(string x, char y);
        bool remove(Node* Target);
        void removeRight(Node* LeftChild, Node* RightChild, Node* Parent, Node*& Temp);
        void removeLeft(Node* LeftChild, Node* RightChild, Node* Parent, Node*& Temp);
	vector<Customer> rangeSearch(string, char, string , char);
        void range(Node* p);
	void inOrderPrint();

private:
        Node* root;
        vector<Customer> cc;
};

#endif /* BSTREE_H_ */
