/*
 * Customer.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */
#include "Customer.h"
#include <string>
#include <iostream>
Customer::Customer(){

}//end default constructor.
Customer::Customer(Customer *c) {
        last = c->getLast();
        initial = c->getInitial();
        balance = c->getBalance();
}//end copy consturctor.
Customer::Customer(string x, char y, int z) {
        last = x;
        initial = y;
        balance = z;
}//end initial constructor.
Customer::Customer(string x, char y) {
        last = x;
        initial = y;

}//end initial constructor.
Customer::~Customer(){

}//end destructor.
string Customer::getLast(){
    return last;
}//end get last name.
char Customer::getInitial(){
    return initial;
}//end get initial name.
int Customer::getBalance(){
    return balance;
}//end get balance.
void Customer::setBalance(int b){
    balance = b;
}//end set balance.
bool Customer::operator<(const Customer & f) const{
    int small =0;
    if(last.length()<f.last.length()){
        small = last.length();
    }
    else{
        small = f.last.length();
    }
    for(int i =0; i <small ; i++){
        if(last[i]<f.last[i]){
            return true;
        }
        else if(last[i]>f.last[i]){
            return false;
        }
    }
    if(last.length()<f.last.length()){
         return true;
     }
    if(last.length()==f.last.length()){
        if(initial<f.initial){
            return true;
        }
        else{
            return false;
        }
    }
    else{
            return false;
    }
}//end operator<.
bool Customer::operator<=(const Customer & f) const
{   int small =0;
    if(last.length()<=f.last.length()){
        small = last.length();
    }
    else{
        small = f.last.length();
    }
    for(int i =0; i <small; i++){

        if(last[i]<f.last[i]){
            cout<<"1"<<endl;
               return true;
        }
        else if(last[i]>f.last[i]){
               return false;
        }
    }
    if(last.length()<f.last.length()){
        return true;
    }
    if(last.length()==f.last.length()){
        if(initial <= f.initial){
            cout<<"2"<<endl;
           return true;
        }
    }
    else{
        return false;
    }
}//end operator<=.
bool Customer::operator>(const Customer & f) const{
    int small =0;
    if(last.length()>f.last.length()){
        small = f.last.length();
    }
    else{
        small = last.length();
    }
    for(int i =0; i <small ; i++){
        if(last[i]>f.last[i]){
            return true;
        }
        else if(last[i]<f.last[i]){
            return false;
        }
    }
    if(last.length()>f.last.length()){

         return true;
     }
    if(last.length()==f.last.length()){
        if(initial>f.initial){
            return true;
        }
        else{
            return false;
        }
    }
    else{
            return false;
    }

}//end operator>.

bool Customer::operator>=(const Customer & f) const
{       int small =0;
        if(last.length()>=f.last.length()){
            small = f.last.length();
        }
        else{
            small = last.length();
        }
        for(int i =0; i <small ; i++){
            if(last[i]>f.last[i]){
                return true;
            }
            else if(last[i]<f.last[i]){
                return false;
            }
        }
        if(last.length()>f.last.length()){

             return true;
         }
        if(last.length()==f.last.length()){
            if(initial>=f.initial){
                return true;
            }
            else{
                return false;
            }
        }
        else{
                return false;
        }


}//end operator>=.

bool Customer::operator==(const Customer & f) const{
    if(last.length()==f.last.length()){
        for(int i =0; i< last.length(); i++){
            if(last[i]==f.last[i]){
                if(initial == f.initial){
                    return true;
                }
            }
            return false;
        }
    }
    else{
        return false;
    }

}//end operator==.
bool Customer::operator!=(const Customer & f) const
{
    if(last.length()!=f.last.length()|| initial != f.initial){
        return true;
    }

    for(int i =0; i< last.length(); i++){
         if(last[i]!=f.last[i]){
              return true;
         }
         return false;
    }
}//end operator!=.
ostream& operator<<(ostream & os,  Customer & f) {
    os << f.last << ", " <<f.initial<<". "<<"("<<f.balance<<")";
}//end operator<<.
