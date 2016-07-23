
#include "ATM.h"
ATM::ATM()
{
    currentTime = 0;
    remainingTime = 0;
    availability = true;
    waitingTime = 0;
    begin = 0;
    atmQueue = new ATMQueue();

}

ATM::~ATM()
{
    delete atmQueue;
}
int ATM::getRemain()
{
    return remainingTime;
}

void ATM::addCustomer(Customer *x)
{
    atmQueue->add(x);
}

int ATM::getWaitingTime()
{
    return waitingTime;
}

void ATM::processCustomer(int currentTime)
{

    if ( availability== true && atmQueue->getSize() != 0)//current customer is finished
    {
        delete currentCustomer;// remove customer
        availability = false;// atm is not available
        begin = currentTime;//assigne the begin time = current time
        currentCustomer = atmQueue->remove();//remove customer from atm Queue;
        waitingTime = waitingTime + (currentTime - currentCustomer->getArrival());//total waitingtime
    }
    if (availability == false)// atm is not available;
    {
        remainingTime = currentCustomer->getTransaction()-(currentTime-begin);//remaintingtime
    }
    if (remainingTime == 1)//when remaingtime is going to equal current time;
    {
        availability = true;//atm is available to customer
    }
}

