#ifndef ATMQUEUE_H_
#define ATMQUEUE_H_
#include "Node.h"
#include "Customer.h"
class ATMQueue {
public:
    ATMQueue();
    ~ATMQueue();
    void add(Customer *customer);
    Customer* remove();
    int getSize();

private:
    int size;
    Node *head;
    Node *tail;
};

#endif /* ATMQUEUE_H_ */
