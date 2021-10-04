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
