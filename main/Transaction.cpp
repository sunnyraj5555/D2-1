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
