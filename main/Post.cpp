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
Post PostList[N];
long PostList_size =0;

   void Post::set_Post_ID(){
        Post_ID = PostList_size + 1;
    }
    
    long Post::get_Post_ID(){
        return Post_ID;
    }
    
    void Post::set_post_details(string Post_Title, string Post_Description){
        this->Post_Title = Post_Title;
        this->Post_Description = Post_Description;
    }
    
    void Post::set_org_details(long Org_ID, string org_name, string org_address, string org_phone_number){
        this->Org_ID = Org_ID;
        this->org_name = org_name;
        this->org_address = org_address;
        this->org_phone_number = org_phone_number;
    }
    
    void Post::set_user_details(long User_ID, string user_name, string patient_name){
        this->User_ID = User_ID;
        this->user_name = user_name;
        this->patient_name = patient_name;
    }
    
    string Post::get_Post_Title(){
        return Post_Title;
    }
    string Post::get_Post_Description(){
        return Post_Description;
    }
    
    
    void Post::get_user_details(){
        cout<<"\tPosted By: "<<user_name<<endl;
        cout<<"\t      Uid: "<<User_ID<<endl;
    }
    
    string Post::get_patient_name(){
        return patient_name;
    }
    
    void Post::get_org_details(){
        
        cout<<"\t  Org ID: "<< Org_ID <<endl;
        cout<<"\tOrg Name: "<< org_name <<endl;
        cout<<"\t Address: "<< org_address <<endl;
        cout<<"\tHelpline: "<< org_phone_number <<endl;
    }

    void Post::set_amount(long amount_requested){
        
        this->amount_requested=amount_requested;
        amount_collected = 0;
        amount_left = amount_requested;
    }
    
    void Post::deduct_money(long amount_received){
        amount_collected += amount_received;
        amount_left -= amount_received;
    }
    
    long Post::get_amount_requested(){
        return amount_requested;
    }
    
    long Post::get_amount_collected(){
        return amount_collected;
    }
    
    long Post::get_amount_left(){
        return amount_left;
    }


void add_post_to_list(Post &p){
    PostList[PostList_size] = p;
    PostList_size++;
    
    cout<<"Post Added successfully."<<endl;
}

