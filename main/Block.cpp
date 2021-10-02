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
long BlockChain_size =0;

    Block::Block()
    {
        No_of_Transactions_in_Block = 0;
        set_BlockNumber();
        set_Previous_Hash();
    }

    void Block::set_Previous_Hash()
    {
        if(BlockChain_size == 1)
        {       //for genesis Block
            Previous_Hash = "";
        }else
        {
            Previous_Hash = BlockChain[BlockChain_size - 2].get_Block_Hash();
        }
    }

    void Block::set_Block_Hash(string Block_Hash){         //this function will be called after SHA hashing the block object
        this->Block_Hash = Block_Hash;
    }

    void Block::set_BlockNumber()
    {
        BlockNumber = ++BlockChain_size - 1;
    }

    string Block::get_Previous_Hash()
    {
        return Previous_Hash;
    }

    string Block::get_Block_Hash()
    {
        return Block_Hash;
    }

    long Block::get_BlockNumber(){
        return BlockNumber;
    }

    long Block::get_No_of_Transactions_in_Block()
    {
        return No_of_Transactions_in_Block;
    }

    void Block::fill_transactions_in_the_block()
    {
        //int total_transactions = List_of_Transaction_ID.size();
        
        long total_transactions = Mempool_size;
        for(int i = 0;i<total_transactions;i++)
        {
            Transactions_in_the_Block[i] = Mempool[i];
        }

        No_of_Transactions_in_Block = total_transactions;
    }

    string Block::get_transaction_msg_from_block(int i)
    {
        return Transactions_in_the_Block[i].get_transaction_msg();
    }

    long Block::get_transaction_ID_from_block(int i)
    {
        return Transactions_in_the_Block[i].get_Transaction_ID();
    }

void intitialise_BlockChain_size()
{
    BlockChain_size = 0;
    create_Genesis_Block();
}

void create_Genesis_Block()
{
    Block b;
    b.set_Block_Hash( create_block_hash(b) );
    BlockChain[0] = b; //conitnuing after 10 mins
}


// this function will be encryption / hashing header file where all other functions also exist
string create_block_hash(Block &b)
{
    return "hash1234";
}

void add_Block_to_BlockChain(Block &b)
{
    BlockChain[BlockChain_size -1] = b;
}

void display_Blockchain(){
    
    if(BlockChain_size == 1){
        cout<<"BlockChain is Empty. No Blocks to Display"<<endl;

    }
    else{
        
        for(int i = 1; i < BlockChain_size; i++){
    
            cout<<" ---------------------"<<endl;
            cout<<"Block ID: " << BlockChain[i].get_BlockNumber()<<endl;
            cout<<"Previous Block hash: "<<BlockChain[i].get_Previous_Hash()<<endl;
            cout<<"Current Block hash: "<<BlockChain[i].get_Block_Hash()<<endl;
            cout<<"Transactions inside the Block: "<<endl;
            cout<<"{"<<endl;
    
            for(int j =0;j<BlockChain[i].get_No_of_Transactions_in_Block();j++){
                cout<<"\t Transaction No: "<<j+1<<endl;
                cout<<"\t Transaction ID: "<<BlockChain[i].get_transaction_ID_from_block(j)<<endl;
                cout<<"\t Transaction Message: "<<BlockChain[i].get_transaction_msg_from_block(j)<<endl;
                cout<<endl;
            }
            cout<<"}"<<endl;
            cout<<endl;
        }
    }
}


void display_Ledger(){
    if(Ledger_size == 0){
        cout<<"Ledger is Empty."<<endl;
        return ;
    }
    cout<<"Ledger: ----------->"<<endl;
    for(int i = 0;i<Ledger_size;i++)
    {
        cout<<"\t"<<Ledger[i].get_Transaction_ID()<<" : "<<Ledger[i].get_transaction_msg();
        cout<<endl;
    }
}

void display_Mempool(){
    if(Mempool_size == 0){
        cout<<"Mempool is Empty."<<endl;
        return ;
    }
    cout<<"Mempool: --------->"<<endl;
    for(int i = 0;i<Mempool_size;i++)
    {
        cout<<"\t"<<Mempool[i].get_Transaction_ID()<<" : "<<Mempool[i].get_transaction_msg();
        cout<<endl;
    }
}