
#ifndef CUSTOMER_H_
#define CUSTOMER_H_

class Customer {
    public:
        Customer();
        Customer(int transaction, int ar);
        void setTransaction(int ransaction);
        int getTransaction();
        void setArrival(int ar);
        int getArrival();


    private:
         int trans;
         int arrival;
};

#endif /* CUSTOMER_H_ */
