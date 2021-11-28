/*
 *  Block.h
 *
 *  Created on: 1-Oct-2021
 *     Authors: M Somasekhar, Aryan Mukerji
 */

#include <iostream>
#include <cstring>
#include "Transaction.h"
#include "main.h"
#include "Menu.h"
#include "Person.h"
#include "Post.h"
#include "Block.h"



using namespace std;


#ifndef READWRITE_H
#define READWRITE_H

bool Is_empty(ifstream& pFile);
void Check_UserList_size();
    void Check_UserList();
    void Check_Transaction_Ids();
    void Check_PostList_size();
    void Check_PostList();
    
    void Check_OrgList_size();
    void Check_OrgList();
    
    void Check_Mempool_size();
void Check_Ledger_size();
void Check_BlockChain_size();


void read_all();
void write_all();
void file_init();

// FILE HANDELING FUNCTIONS

//---------- Transaction_Ids READ() WRITE() ---------

void read_Transaction_Ids();
void write_Transaction_Ids();

//---------- Mempool & Ledger READ() WRITE() -----------------
string create_Transaction_string(Transaction &t);
void extract_Transaction(string s, Transaction &t);

void write_Mempool_size();
void read_Mempool_size();
void write_Mempool();
void read_Mempool();

void write_Ledger_size();
void read_Ledger_size();
void write_Ledger();
void read_Ledger();

//----------- BlockChain READ() WRITE()-----------------------
string create_Block_string(Block &b);
void extract_Block(string s, Block &b);

void write_BlockChain_size();
void read_BlockChain_size();
void write_BlockChain();
void read_BlockChain();

//----------- Organization READ() WRITE()---------------------
string create_Organization_string(Organization &o);
void extract_Organization(string s, Organization &o);

void write_OrgList_size();
void read_OrgList_size();
void write_OrgList();
void read_OrgList();

//----------- Post READ() WRITE()-----------------------------
string create_Post_string(Post &p);
void extract_Post(string s, Post &p);

void write_PostList_size();
void read_PostList_size();
void write_PostList();
void read_PostList();

//----------- User READ() WRITE()-----------------------------
string create_User_string(User &u);
void extract_User(string s, User &u);

void write_UserList_size();
void read_UserList_size();
void write_UserList();
void read_UserList();


#endif /* READWRITE_H */
