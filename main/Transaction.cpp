/*
 *  Transaction.cpp
 *
 *  Created on: 29-Sep-2021
 *     Authors: M Somasekhar, Aryan Mukerji
 */
 
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "main.h"
#include "Menu.h"
#include "Person.h"
#include "Transaction.h"
#include "Post.h"
#include "Block.h"

using namespace std;
#define N 100

Transaction Ledger[N];
Transaction Mempool[N];
//stack<int> List_of_Transaction_ID;
long Ledger_size =0;
long Mempool_size =0;
long Transaction_Ids =0;

//using a stack to store number of trans happend till now
//currently just storing the trans as int type denoting no.of.trans happended till a point = size of stack;
//currently this can also be substituted by a simple int varialble total_trans and we keep doing +1 every time new transaction happens.
//stack<int> List_of_Transaction_ID;

// Future goals:
// -----Try to design this stack template of our own Transaction class,
// -----to directly store the objects of transaction happened till time.
// -----then to get the id of a transaction we would do --> List_of_Transactions.top().get_Transaction_ID();

void Transaction::set_Transaction(string sender, string reciever, long amount, long Transaction_ID)
    {
        this->Transaction_ID = Transaction_ID;
        this->sender  = sender;
        this->reciever = reciever;
        this->amount = amount;

        transaction_msg = sender + " sent " + reciever + " amount " + to_string(amount) + " Rs.";
    }
    
    void Transaction::set_transaction_msg(string message)
    {
        transaction_msg = message;
    }

    void Transaction::set_Transaction_ID()
    {
        Transaction_ID = Transaction_Ids + 1;
    }
    
    long Transaction::get_Transaction_ID()
    {
        return Transaction_ID;
    }

    string Transaction::get_transaction_msg()
    {
        return transaction_msg;
    }

// having an array to save the trantransaction till time. (Max transactions hardcoded as N = 100 in the macro)
// this array will be using 1 based indexing
//Transaction Transaction_Array[N];

