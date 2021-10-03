/*
 *  Post.cpp
 *  
 *  Created on: 1-Oct-2021
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


class Post {
    
    private:
    
    long Post_ID;
    string Post_Title, Post_Description;
    long amount_requested, amount_collected, amount_left;
    
    long User_ID;
    string user_name, patient_name;
    
    long Org_ID;
    string org_phone_number;
    string org_name, org_address;
    
    public:
    
    void set_Post_ID();
    
    long get_Post_ID();
    
    void set_post_details(string Post_Title, string Post_Description);
    
    void set_org_details(long Org_ID, string org_name, string org_address, string org_phone_number);
    
    void set_user_details(long User_ID, string user_name, string patient_name);
    
    string get_Post_Title();
    
    string get_Post_Description();
    
    void get_user_details();
    
    string get_patient_name();
    
    void get_org_details();

    void set_amount(long amount_requested);
    
    void deduct_money(long amount_received);
    
    long get_amount_requested();
    
    long get_amount_collected();
    
    long get_amount_left();


};
