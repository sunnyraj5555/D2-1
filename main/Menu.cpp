/*
 *  Menu.cpp
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


void main_menu(){
    cout<<endl;
    cout<<"\t\t Welcome To D2 - A BlockChain Based Secure Donation System !"<<endl;
    cout<<"\n\n";
    cout<<"\t\t1. Login as User "<<endl;
    cout<<"\t\t2. Login as Admin "<<endl;

    int choose;
    cout<<"\n\t\t Enter your choice: ";
    cin>>choose;
    
    switch(choose){
        case 1: {
            user_menu();
            break;
        }
        case 2: {
            admin_main_menu();
            break;
        }
           default: {
            cout<<"\t Invalid Input."<<endl;
            break;
        }
        
    }

}


void admin_main_menu(){
    while(1){
        
    cout<<endl;
    cout<<"Welcome ADMIN.! Please select one of the following operations: "<<endl;
    cout<<"1. Mine a Block "<<endl;
    cout<<"2. Display BlockChain "<<endl;
    cout<<"3. Display Ledger "<<endl;
    cout<<"4. Display Mempool "<<endl;
    cout<<endl;
    cout<<"Enter 0 to return to main menu. "<<endl;
    int choose;
    cout<<"\nEnter your choice: ";
    cin>>choose;
    cout<<endl;
    switch(choose){
        case 0: {
            main_menu();
            break;
        }
        case 1: {
            mine_block();
            break;
        }
        case 2: {
            display_Blockchain();
            break;
        }
        case 3: {
            display_Ledger();
            break;
        }
        case 4: {
            display_Mempool();
            break;
        }
        default: {
            cout<<"This feature is currntly being developed."<<endl;
            break;
        }
        
    }
    }
}


void user_menu(){
    while(1){
    cout<<endl;
    cout<<"Welcome USER.! Please select one of the following operations: "<<endl;

    cout<<"1. Donate Money "<<endl;
    cout<<"2. Create Post "<<endl;

    cout<<endl;
    cout<<"Enter 0 to return to main menu. "<<endl;

    int choose;
    cout<<"\nEnter your choice: ";
    cin>>choose;
    cout<<endl;
    switch(choose){
        case 0: {
            main_menu();
            break;
        }
        case 1: {
            post_list_menu();
            break;
        }
        case 2: {
            org_list_menu();
            break;
        }
        default: {
            cout<<"This feature is currently being developed."<<endl;
            break;
        }
        
    }
    }
}
