
#include "Customer.h"

Customer::Customer()
{
    trans = 0;
    arrival= 0;
}
Customer::Customer(int transaction, int ar)
{
    trans= transaction;
    arrival = ar;
}

void Customer::setTransaction(int transaction)
{
    trans = transaction;
}
int Customer::getTransaction()
{
    return trans;
}
void Customer::setArrival(int ar)
{
    arrival =  ar;
}
int  Customer::getArrival()
{
    return arrival;
}


// TO DO:: Fill in.


