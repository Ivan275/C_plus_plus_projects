/*
 * Customer.h
 *
 *  Created on: Mar 20, 2012
 *      Author: ivan
 */
#include <string>
#include <iostream>
using namespace std;
#ifndef CUSTOMER_H_
#define CUSTOMER_H_
class Customer{
        public:
                Customer();
                Customer(Customer *c);
                Customer(string x, char y, int z);
                Customer(string x, char y);
                ~Customer();
                string getLast();
                char getInitial();
                int getBalance();
                void setBalance(int b);
                bool operator<(const Customer & f) const;
                bool operator<=(const Customer & f) const;
                bool operator>(const Customer & f) const;
                bool operator>=(const Customer & f) const;
                bool operator==(const Customer & f) const;
                bool operator!=(const Customer & f) const;
        private:
                 string last;
                 char initial;
                 int balance;
                friend ostream& operator<<(ostream & os,  Customer & f);
};

#endif /* CUSTOMER_H_ */
