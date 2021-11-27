/*
 *  Block.h
 *
 *  Created on: 29-Sep-2021
 *     Authors: Aryan Mukerji, M Somasekhar
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

Block BlockChain[N];
long BlockChain_size = 0;

    Block::Block()
    {
        No_of_Transactions_in_Block = 0;
        set_BlockNumber();
    }

    void Block::set_Previous_Hash()
    {
        if(BlockChain_size == 0)
        {   
            // for genesis Block
            Previous_Hash = "Genesis Block";
        }
        else
        {
            Previous_Hash = BlockChain[BlockChain_size - 1].get_Block_Hash();
        }
    }

    void Block::set_Previous_Hash(string Previous_Hash){
        this->Previous_Hash = Previous_Hash;
    }
    
    // this function will be called after SHA hashing the block object
    void Block::set_Block_Hash(string Block_Hash)
    {         
        this->Block_Hash = Block_Hash;
    }

    void Block::set_BlockNumber()
    {
        BlockNumber = BlockChain_size;
    }

    void Block::set_BlockNumber(long i){
        BlockNumber = i;
    }

    void Block::set_No_of_Transactions_in_Block(long i){
        No_of_Transactions_in_Block =i;
    }

    string Block::get_Previous_Hash()
    {
        return Previous_Hash;
    }

    string Block::get_Block_Hash()
    {
        return Block_Hash;
    }

    long Block::get_BlockNumber()
    {
        return BlockNumber;
    }

    long Block::get_No_of_Transactions_in_Block()
    {
        return No_of_Transactions_in_Block;
    }

    Transaction Block::get_Transactions_in_the_Block(int i){
        return Transactions_in_the_Block[i];
    }

    void Block::fill_transactions_in_the_block()
    {
        // int total_transactions = List_of_Transaction_ID.size();
        
        long total_transactions = Mempool_size;
        
        for(int i = 0; i<total_transactions; i++)
        {
            Transactions_in_the_Block[i] = Mempool[i];
        }

        No_of_Transactions_in_Block = total_transactions;
    }

    void Block::fill_transactions_in_the_block(Transaction &t, int i){
        Transactions_in_the_Block[i] = t;
    }

    string Block::get_transaction_msg_from_block(int i)
    {
        return Transactions_in_the_Block[i].get_transaction_msg();
    }
	
	string Block::get_sender_of_transaction_from_block(int i)
    {
        return Transactions_in_the_Block[i].get_sender();
    }
	
	string Block::get_reciever_of_transaction_from_block(int i)
    {
        return Transactions_in_the_Block[i].get_reciever();
    }
	
	long long Block::get_amount_of_transaction_from_block(int i)
    {
        return Transactions_in_the_Block[i].get_amount();
    }

    long Block::get_transaction_ID_from_block(int i)
    {
        return Transactions_in_the_Block[i].get_Transaction_ID();
    }

void create_Genesis_Block()
{
    Block b;
    b.set_Block_Hash( create_block_hash(b) );
    b.set_Previous_Hash();
    add_Block_to_BlockChain(b); // conitnuing after 10 mins
}

// this function will be encryption / hashing header file where all other functions also exist
string create_block_hash(Block &b)
{
    return "hash1234";
}

void add_Block_to_BlockChain(Block &b)
{
    BlockChain[BlockChain_size] = b;
    BlockChain_size++;
}

void display_Blockchain()
{
    ClearOS();
    
    if(BlockChain_size == 1)
    {
        cout << "\n !!BlockChain is Empty, No Blocks to Display!! ";
        return ;
    }
    else
    {
        cout << "\n\n ********** Blocks in BlockChain ********** ";
        
        for(int i = 1; i < BlockChain_size; i++)
        {
            cout << "\n\n ************************************************** "
                 << "\n Block ID : " << BlockChain[i].get_BlockNumber()
                 << "\n Previous Block hash : " << BlockChain[i].get_Previous_Hash()
                 << "\n Current Block hash : " << BlockChain[i].get_Block_Hash()
                 << "\n Transactions inside the Block : "
                 << "\n { ";
                
            for(int j=0; j<BlockChain[i].get_No_of_Transactions_in_Block(); j++)
            {
                // cout << "\n\t Transaction No : " << j+1;
                cout << "\n\t Transaction ID : " << BlockChain[i].get_transaction_ID_from_block(j)
					 << "\n\t Sender : " << BlockChain[i].get_sender_of_transaction_from_block(j)
					 << "\n\t Reciever : " << BlockChain[i].get_reciever_of_transaction_from_block(j)
					 << "\n\t Amount : " << BlockChain[i].get_amount_of_transaction_from_block(j)
					 // << "\n\t Sender's Public Key : " << BlockChain[i].get_sender_of_transaction_from_block(j)
                     // << "\n\t Transaction Message : " << BlockChain[i].get_transaction_msg_from_block(j) 
					 << endl;
            }
            
            cout<<"\n } ";
        }
    }
}

void mine_block()
{
    ClearOS();
    
    if(Mempool_size == 0)
    {
        cout << "\n !!No Blocks to Mine, Mempool is Empty!! ";
        return ;
    }
    
    Block b;
    
    b.fill_transactions_in_the_block();
    b.set_Previous_Hash();
    b.set_Block_Hash(create_block_hash(b));  // this create_block_hash(Block &b) will be there is another header which will have hashing functions
    
    cout << "\n !!Block Mined Successfully!! ";
    add_Block_to_BlockChain(b);
    
    cout << "\n !!Block Added to BlockChain Successfully!! ";
    
    for(int i = 0; i<Mempool_size; i++)
    {
        Ledger[i + Ledger_size] = Mempool[i];   // adding these to ledger as they are mined
    }
    
    cout << "\n !!Transactions are added to Ledger!! ";
    
    Ledger_size = Ledger_size + Mempool_size;   //  updating the Ledger_size
    Mempool_size = 0;   //  freeing Mempool
    
    cout << "\n !!Clearing Mempool!! ";

    // delete the block b too at the last
}

void display_Ledger()
{
    ClearOS();
    
    if(Ledger_size == 0)
    {
        cout << "\n !!Ledger is Empty!! ";
        return ;
    }
    
    cout << "\n\n ********** Ledger ********** ";
    
    for(int i = 0;i<Ledger_size;i++)
    {
        cout << "\n " << Ledger[i].get_Transaction_ID() << " : " << Ledger[i].get_transaction_msg();
    }
}

void display_Mempool()
{
    ClearOS();
    
    if(Mempool_size == 0)
    {
        cout << "\n !!Mempool is Empty!! ";
        return ;
    }
    
    cout << "\n\n ********** Mempool ********** ";
    
    for(int i = 0;i<Mempool_size;i++)
    {
        cout << "\n " << Mempool[i].get_Transaction_ID() << " : " << Mempool[i].get_transaction_msg();
    }
}
