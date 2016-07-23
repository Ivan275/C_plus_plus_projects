
#include "ATMQueue.h"


ATMQueue::ATMQueue()
{
       head = 0;
       tail = 0;
       size = 0;
}

ATMQueue::~ATMQueue()
{
    Node *nPtr = head;
    while (nPtr != 0)
    {
        Node *temp = nPtr->next;
        nPtr->Node::~Node();
        delete nPtr;
        nPtr = temp;
    }
}

int ATMQueue::getSize()
{
        return size;
}


void ATMQueue::add(Customer *customer)
{
        Node *newNode = new Node(customer);
        if (head == 0)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size ++;
}
Customer* ATMQueue::remove()
{
        Node *newNode;
        newNode = head;
        head = head->next;
        size--;
        return newNode->customer;

}



// TO DO:: Fill in.
