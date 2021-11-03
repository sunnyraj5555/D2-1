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

extern long Mempool_size;
extern long Ledger_size;

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

extern Transaction Ledger[N];
extern Transaction Mempool[N];
Transaction NewTransaction(string sender, string reciever, long amount);
void donate_money_UI(long Post_ID);

// client side functions
string prepare_transmission_buffer(Transaction &t, long user_priv_key ,long admin_pub_key);
void send_transaction_from_client_to_server(Transaction &t, long user_priv_key ,long admin_pub_key );

void recieve_transaction_from_client(string recived_buffer, Transaction &t);
bool verify_transaction(string buffer);

#endif /* TRANSACTION_H */
