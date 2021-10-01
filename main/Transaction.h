/*
 *  Transaction.h
 *
 *  Created on: 1-Oct-2021
 *     Authors: M Somasekhar, Aryan Mukerji
 */

#include <iostream>
#include <cstring>

using namespace std;
#define N 100

#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction
{
    private:
    // creating sender & reciever variable to store names of the sender & reciver
    // transaction_msg stores transaction message that will be auto generated using sender and reciever
    // amount stores the amount sent by sender to reciever
    // Transaction_ID stores the transaction ID of the transaction made by sender
    string sender, reciever, transaction_msg;
    long long amount;
    long Transaction_ID;

    // fututre additions in data member
    // 1. Digital Signature got by sender (String Type)
    // 2. Public Key of sender (String Type)
    // 3. User_ID of sender (int type)

    public:

    // this function is used to set the transaction details when a trantransaction is made
    void set_Transaction(string sender, string reciever, long amount, long Transaction_ID);
    
    void set_transaction_msg(string message);
    
    void set_Transaction_ID();

    long get_Transaction_ID();

    string get_transaction_msg();
};


#endif /* TRANSACTION_H */
