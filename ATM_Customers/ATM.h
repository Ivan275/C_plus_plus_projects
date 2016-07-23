
#ifndef ATM_H_
#define ATM_H_
#include "ATMQueue.h"
#include "Customer.h"
#include <iostream>
class ATM {
public:
    ATM();
    ~ATM();
    int getRemain();
    void addCustomer(Customer *x);
    void processCustomer(int x);
    int getWaitingTime();
    ATMQueue *atmQueue;

private:
    bool availability;
    int waitingTime;
    Customer *currentCustomer;
    int remainingTime;
    int begin;
    int currentTime;
};

#endif /* ATM_H_ */
