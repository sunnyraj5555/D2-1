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


void org_list_menu(){
    
    cout<<"List of Orgs ------------>"<<endl;
    cout<<endl;
    display_OrgList();
    cout<<endl;
    cout<<endl;
    cout<<"\t Press 1 to select Org from above list."<<endl;
    cout<<"\t Press 2 to enter your own Org details."<<endl;
    cout<<"\t Press 0 to return to user menu."<<endl;
    
    cout<<endl;
    int choose1;
    cout<<"\nEnter your choice: ";
    cin>>choose1;
    cout<<endl;
    if(choose1 == 1){
        cout<<"Enter the Org ID you want to link "<<endl;
        cout<<"OR"<<endl;
        cout<<"Enter 0 to return to user menu"<<endl;
        long choose1;
        cout<<"\nEnter your choice: ";
        cin>>choose1;
        cout<<endl;
        switch(choose1){
            case 0: {
                user_menu();
                break;
            }
            default: {
                enter_post_details(choose1);
                break;
            }
        }
    }
    else if(choose1 == 2){
        create_org();
    }
    else{
        user_menu();
        return ;
    }
}


void post_list_menu(){
    
    if(PostList_size == 0){
        cout<<"Currently no posts available for donation. !"<<endl;
        return ;
    }
    cout<<"List of Posts ------------>"<<endl;
    cout<<endl;
    display_PostList();
    cout<<"Enter the post ID you want to read and donate to "<<endl;
    cout<<"OR"<<endl;
    cout<<"Enter 0 to return to user menu"<<endl;
    long choose1;
    cout<<"\nEnter your choice: ";
    cin>>choose1;
    cout<<endl;
    switch(choose1){
        case 0: {
            user_menu();
            break;
        }
        default: {
            display_Post(choose1);
            donate_to_post_menu(choose1);
            break;
        }
    }
}