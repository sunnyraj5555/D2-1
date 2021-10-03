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


void enter_org_details(long registration_number){
    
    string org_name;
    string org_address;
    string org_phone_number;

    string Post_Title, Post_Description;
    long amount_requested, amount_collected, amount_left;
    long User_ID;
    string user_name, patient_name;
    
    Organization o;
    
    
    o.set_Org_ID();
    
    
    o.set_registration_number(registration_number);
    
    
    cout<<"Enter Organization DETAILS: "<<endl;
    cin.ignore();
    cout<<"\t"<<"Org Name: "; getline(cin, org_name);
    
    cout<<"\t"<<" Address: "; getline(cin, org_address);
    
    cout<<"\t"<<"Helpline: "; cin>>org_phone_number;
    
    o.set_org_details(org_name, org_address, org_phone_number);
    
    add_org_to_list(o);
    
    
    enter_post_details(o.get_Org_ID());
 
}


void enter_post_details(long Org_ID){

    
    string Post_Title, Post_Description;
    long amount_requested;
    
    long User_ID;
    string user_name, patient_name;
    
    Post p;
    p.set_Post_ID();
    
    p.set_org_details(OrgList[Org_ID -1].get_Org_ID(), 
                    OrgList[Org_ID -1].get_org_name(), 
                    OrgList[Org_ID -1].get_org_address(), 
                    OrgList[Org_ID -1].get_org_phone_number());
    
    
    // User details will be automatically entered with parameters from the func, we will not ask user.
    cout<<"\nEnter your User ID: ";
    cin>>User_ID;
    cin.ignore();
    cout<<"\nEnter your User Name: ";
    getline(cin, user_name);
    
    
    
    cout<<"\nEnter Patient Name: ";
    getline(cin, patient_name);
    
    p.set_user_details(User_ID, user_name, patient_name);
    
    cout<<endl;
    
    cout<<"\nEnter Post DETAILS: "<<endl;
    
    cout<<"\t"<<"Post Title: "; getline(cin, Post_Title);
    
    cout<<"\t"<<"Post Description: "; getline(cin, Post_Description);
    
    p.set_post_details(Post_Title, Post_Description);
    
    cout<<"\t"<<"Donation Amount: "; cin>>amount_requested;
    
    p.set_amount(amount_requested);
    
    cout<<endl;
    cout<<"Post created successfully."<<endl;
    
    add_post_to_list(p);
}



void display_PostList(){
    if(PostList_size == 0){
        cout<<"No Posts Found. "<<endl;
        return ;
    }
    for(int i =0;i<PostList_size;i++){
        cout<<"\t"<<PostList[i].get_Post_ID()<<" : "<<PostList[i].get_Post_Title()<<" | "<<PostList[i].get_amount_requested()
        <<" | "<<PostList[i].get_amount_left();
        cout<<endl;
    }
    cout<<endl;
}

void display_Post(long Post_ID){
    cout<<"\t"<<"TITLE: "<<PostList[Post_ID -1].get_Post_Title()<<endl;
    cout<<"\t"<<"Pid: "<<PostList[Post_ID -1].get_Post_ID()<<endl;
    cout<<endl;
    cout<<"\t"<<"Patient: "<<PostList[Post_ID -1].get_patient_name()<<endl;
    cout<<endl;
    cout<<"\t"<<"Incident: "<<PostList[Post_ID -1].get_Post_Description()<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"\t"<<" Amount Req: "<<PostList[Post_ID -1].get_amount_requested()<<endl;
    cout<<"\t"<<"Left amount: "<<PostList[Post_ID -1].get_amount_left()<<endl;
    cout<<endl;
    PostList[Post_ID -1].get_org_details();
    cout<<endl;
    PostList[Post_ID -1].get_user_details();
    cout<<endl;
}
