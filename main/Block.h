/*
 *  Block.h
 *
 *  Created on: 1-Oct-2021
 *     Authors: M Somasekhar, Aryan Mukerji
 */

#include <iostream>
#include <cstring>

using namespace std;
#define N 100

#ifndef BLOCK_H
#define BLOCK_H


class Block
{
    private:

    long BlockNumber;       //every block has a number
    Transaction Transactions_in_the_Block[N];       // to store the list of transactions in array of transaction class objects for each transaction
    int No_of_Transactions_in_Block;            // to store how many transactions are there inside a particular block
    string Previous_Hash , Block_Hash;          // to store prev has and current block hash inside 

    public:

    Block();
    void set_Previous_Hash();           // to set previous hash 
    void set_Block_Hash(string Block_Hash);       // will set the hash of current block
    void set_BlockNumber();         //  will set the block number accordingly from the current blockchain

    string get_Previous_Hash(); 
    string get_Block_Hash();

    long get_BlockNumber();
    long get_No_of_Transactions_in_Block(); 

    // flush all the transaction objs from Transaction_Array (exists in Transaction.h/.cpp) into Transactions_in_the_Block[] 
    // also updating the value of No_of_Transactions_in_Block variable = Transaction_Array size
    void fill_transactions_in_the_block();      
    string get_transaction_msg_from_block(int i);
    long get_transaction_ID_from_block(int i);
};

extern Block BlockChain[N];
extern long BlockChain_size;

void create_Genesis_Block();
string create_block_hash(Block &b);
void add_Block_to_BlockChain(Block &b);

void mine_block();
void display_Ledger();
void display_Blockchain();
void display_Mempool();

#endif /* BLOCK_H */
