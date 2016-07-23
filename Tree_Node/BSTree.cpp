/*
 * BSTree.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "BSTree.h"


BSTree::BSTree() {
    root = 0;
}//end default constructor
BSTree::BSTree(const BSTree& rbt){
    copyTree(rbt.root,root);

}//end copy constructor
void BSTree::copyTree(Node *treeP,Node *&newP){
    if(treeP != NULL){
        newP = new Node(treeP->customer,NULL,NULL);
        copyTree(treeP->left,newP->left);
        copyTree(treeP->right,newP->right);
    }
    else{
        newP = NULL;//copy empty tree.
    }

}//end copytree

BSTree::~BSTree() {
    destroy(root);
}//end destructor.
void BSTree::destroy(Node* n){
    if(n !=0){
        destroy(n->left);
        destroy(n->right);
        delete n;
        n=NULL;
    }
}//end destroy.

bool BSTree::insert(string x, char y, int z){
    Customer cus(x,y,z);//initialize the contructor
    insertTwo(cus,root);
    return true;
}//end insert.
void BSTree::insertTwo( Customer cus,Node *&r){
    if(r == NULL){
        r = new Node(cus);//based case.
    }
    else if(cus< r->customer){
        insertTwo(cus,r->left);
        (r->left)->parent= r;//point back to parent.
    }else{
        insertTwo(cus,r->right);
        (r->right)->parent= r;//point back to parent.
        }

}//end insertTwo.


void BSTree::inorder(Node* p){
    if(p != NULL)
    {
        if(p->left){
            inorder(p->left);
        }
        cout<< p->customer<<endl;//it can print list in order;
        if(p->right){
            inorder(p->right);
        }
    }
    else return;
}//end inorder
bool BSTree::search(string x, char y)
{
    Customer cus(x,y);
    if (search(cus, root))
        return true;
    else
        return false;
}
Node* BSTree::search(Customer cus, Node* aRoot)
{
    if(aRoot == NULL)
        return NULL;
    else if(aRoot->customer == cus)//  find the customer
        return aRoot;
    else if(aRoot->customer > cus)
        return search(cus, aRoot->left);// find left by recusively
    else
        return search(cus, aRoot->right);// find right by recusively
}
bool BSTree::remove(string x, char y)
{
    Customer Data(x, y);
    Node* Target;
    Target = search(Data, root);
    if(Target != NULL) //if Target is in the tree
        return remove(Target);
    else{
        return false;
    }
}
bool BSTree::remove(Node* Target){
    Node* LeftChild = Target->left;
    Node* RightChild = Target->right;
    Node* Parent = Target->parent;
    if(Target == root){// check the root
        if ((LeftChild  == NULL)&&(RightChild == NULL)) //only root
            root = NULL;
        else if(LeftChild  != NULL){//check left child of the root
            Node* Temp = LeftChild ;
            removeLeft(LeftChild , RightChild , Parent, Temp);
            root = Temp; //set the Temp as the root
        }
        else{
            Node* Temp = RightChild ;
            removeRight(LeftChild , RightChild , Parent, Temp);
            root = Temp;//set the Temp as the root
        }
    }
    else if((LeftChild  == NULL)&&(RightChild  == NULL)){ //check the leaf;
        if(Target->customer < Parent->customer)
            Parent->left= NULL;// remove Left Child
        else
            Parent->right= NULL; //remove Right Child
    }
    else if(Target->customer < Parent->customer){// check left subtree.
        if(LeftChild  != NULL){  //check left child
            Node* Temp = LeftChild;
            removeLeft(LeftChild , RightChild , Parent, Temp);
            Parent->left = Temp; //link Parent and Temp
        }
        else //check right child
        {
            Node* Temp = RightChild ;
            removeRight(LeftChild , RightChild , Parent, Temp);
            Parent->left = Temp; //link Parent and Temp
        }
    }
    else if(Target->customer >= Parent->customer){// check right tree
        if(LeftChild  != NULL){ // check left child
            Node* Temp = LeftChild ;
            removeLeft(LeftChild , RightChild , Parent, Temp);
            Parent->right = Temp; //link Parent and Temp
        }
        else //check right child
        {
            Node* Temp = RightChild ;
            removeRight(LeftChild , RightChild , Parent, Temp);
            Parent->right = Temp; //link Parent and Temp
        }
    }
    delete Target;// delete target
    Target = NULL;//erease the pointer
    return true;
}
void BSTree::removeLeft(Node* LeftChild, Node* RightChild, Node* Parent, Node*& Temp){
    while(Temp->right!= NULL)
        Temp = Temp->right;// find the temp
    if(Temp != LeftChild){
        if(Temp->left!= NULL)//if temp has a left child
        {
            Temp->parent->right = Temp->left;
            Temp->left->parent = Temp->parent;
        }
        else // check it has a right child
            Temp->parent->right = NULL;
        Temp->left = LeftChild;
        LeftChild->parent = Temp;
        Temp->right= RightChild;
        if(RightChild != NULL)
            RightChild->parent = Temp;
        Temp->parent = Parent;
    }
    else{ //Temp equals left child
        Temp->parent = Parent;
        Temp->right = RightChild;
        if(RightChild != NULL) // check parent is not empty
            RightChild->parent = Temp;
    }
}
void BSTree::removeRight(Node* LeftChild, Node* RightChild, Node* Parent, Node*& Temp){
    while(Temp->left!= NULL)
        Temp = Temp->left;// find the temp
    if(Temp != RightChild)
    {
        if(Temp->right!= NULL)//Replace right child
        {
            Temp->parent->left= Temp->right;
            Temp->right->parent = Temp->parent;
        }
        else // Replace left child
            Temp->parent->left= NULL;
        Temp->right= RightChild;
        RightChild->parent = Temp;
        Temp->parent = Parent;
    }
    else{
        Temp->parent = Parent;
        Temp->left = LeftChild;
    }
}

vector<Customer> BSTree::rangeSearch(string x, char y, string z, char a) {

    vector<Customer> vec; //create new vector vec.
    range(root);
    Customer cusOne(x,y);
    Customer cusTwo(z,a);
    for(int i = 0;i< cc.size();i++){//check every position.
        if((cusOne<cc[i])&&(cc[i]<cusTwo)){
            vec.push_back(cc[i]);// add everything that satisfied condition,put them into new vector vec.
        }
        if(cusOne==cc[i]){
            vec.push_back(cc[i]);
        }
        if(cusTwo==cc[i]){
            vec.push_back(cc[i]);
        }
    }
        return vec;

}//end rangeSearch.

void BSTree::range(Node* p ){
    if(p != NULL)
    {
        if(p->left){
            range(p->left);
        }
        cc.push_back(p->customer);//assign every customer into vector cc by ordering.
        if(p->right){
            range(p->right);
        }
    }
    else {
        return ;
    }
}//end range.

void BSTree::inOrderPrint() {
    inorder(root);
}//end inOrderPrint.


