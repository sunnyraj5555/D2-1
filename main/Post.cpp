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
long PostList_size = 0;
    
    void Post::set_Post_ID()
    {
        Post_ID = PostList_size + 1;
    }
    
    void Post::set_Post_ID(long i){
        Post_ID = i;
    }
    
    long Post::get_Post_ID()
    {
        return Post_ID;
    }
    
    void Post::set_post_details(string Post_Title, string Post_Description)
    {
        this->Post_Title = Post_Title;
        this->Post_Description = Post_Description;
    }
    
    void Post::set_org_details(long Org_ID, string org_name, string org_address, string org_phone_number)
    {
        this->Org_ID = Org_ID;
        this->org_name = org_name;
        this->org_address = org_address;
        this->org_phone_number = org_phone_number;
    }
    
    void Post::set_user_details(long User_ID, string user_name, string patient_name)
    {
        this->User_ID = User_ID;
        this->user_name = user_name;
        this->patient_name = patient_name;
    }
    
    string Post::get_Post_Title()
    {
        return Post_Title;
    }
    
    string Post::get_Post_Description()
    {
        return Post_Description;
    }
    
    void Post::get_user_details()
    {
        cout << "\n\n Posted By : " << user_name
             << "\n User ID : " << User_ID;
    }
    string Post::get_user_name(){
        return user_name;
    }

    long Post::get_User_ID(){
        return User_ID;
    }
    
    string Post::get_patient_name()
    {
        return patient_name;
    }
    
    void Post::get_org_details()
    {
        cout << "\n\n Organization ID : " << Org_ID
             << "\n Organization Name : " << org_name
             << "\n Address : " << org_address
             << "\n Helpline : " << org_phone_number;
    }
    long Post::get_Org_ID(){
        return Org_ID;
    }

    string Post::get_org_name()
    {
        return org_name;
    }

    string Post::get_org_address()
    {
        return org_address;
    }
    
    string Post::get_org_phone_number()
    {
        return org_phone_number;
    }
    
    
    void Post::set_amount(long amount_requested)
    {
        this->amount_requested = amount_requested;
        amount_collected = 0;
        amount_left = amount_requested;
    }

    void Post::set_amount_left(long i){
        amount_left = i;
    }
    void Post::set_amount_collected(long i){
        amount_collected = i;
    }
    
    void Post::deduct_money(long amount_received)
    {
        amount_collected += amount_received;
        amount_left -= amount_received;
    }
    
    long Post::get_amount_requested()
    {
        return amount_requested;
    }
    
    long Post::get_amount_collected()
    {
        return amount_collected;
    }
    
    long Post::get_amount_left()
    {
        return amount_left;
    }

void display_PostList()
{
    if(PostList_size == 0)
    {
        cout << "\n !!No Posts Found!! ";
        return ;
    }
    for(int i = 0; i<PostList_size; i++)
    {
        cout << "\n " << PostList[i].get_Post_ID() << " : " << PostList[i].get_Post_Title() 
             << " | " << PostList[i].get_amount_requested() << " | " << PostList[i].get_amount_left();
    }
}

void display_Post(long Post_ID)
{
    
    cout << "\n\n Post Title : " << PostList[Post_ID -1].get_Post_Title()
         << "\n Post ID : " << PostList[Post_ID -1].get_Post_ID()
         << "\n Patient Name : " << PostList[Post_ID -1].get_patient_name()
         << "\n\n Incident : " << PostList[Post_ID -1].get_Post_Description()
         << "\n Amount Required : " << PostList[Post_ID -1].get_amount_requested()
         << "\n Amount Left : " << PostList[Post_ID -1].get_amount_left();
    
    PostList[Post_ID -1].get_org_details();
    PostList[Post_ID -1].get_user_details();
}

void add_post_to_list(Post &p)
{
    PostList[PostList_size] = p;
    PostList_size++;
    
    cout << "\n !!Post Added successfully!! ";
}

void enter_org_details(long registration_number)
{
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
    
    cout << "\n\n ********** Enter Organization Details ********** ";
    
    cin.ignore();
    cout << "\n\n Organization Name : "; getline(cin, org_name);
    cout << "\n Address : "; getline(cin, org_address);
    cout << "\n Helpline : "; cin >> org_phone_number;
    
    o.set_org_details(org_name, org_address, org_phone_number);
    
    add_org_to_list(o);
    enter_post_details(o.get_Org_ID());
}

void enter_post_details(long Org_ID)
{
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

    User_ID = UserList[Logged_User_ID -1].get_User_ID();
    user_name = UserList[Logged_User_ID -1].get_User_Name();
    
    cout << "\n\n ********** Enter Post Details ********** ";
    
    cin.ignore();
    cout << "\n\n Enter Patient Name : "; getline(cin, patient_name);
    cout << "\n\n Post Title : "; getline(cin, Post_Title);
    cout << "\n Post Description : "; getline(cin, Post_Description);
    cout << "\n Donation Amount : "; cin >> amount_requested;
    
    p.set_user_details(User_ID, user_name, patient_name);
    p.set_post_details(Post_Title, Post_Description);
    p.set_amount(amount_requested);
    
    cout << "\n !!Post created successfully!! ";
    
    add_post_to_list(p);
}

void post_init()
{
    Post p;
    p.set_Post_ID();
    p.set_org_details(OrgList[0].get_Org_ID(), 
                      OrgList[0].get_org_name(), 
                      OrgList[0].get_org_address(), 
                      OrgList[0].get_org_phone_number());
    
    p.set_user_details(2, "Aryan", "Surya");
    p.set_post_details("Suffering from Covid-19!", "Please Donate! Need Help!");
    p.set_amount(5000);

    add_post_to_list(p);

    Post p1;
    p1.set_Post_ID();
    p1.set_org_details(OrgList[0].get_Org_ID(), 
                      OrgList[0].get_org_name(), 
                      OrgList[0].get_org_address(), 
                      OrgList[0].get_org_phone_number());
    
    p1.set_user_details(1, "Somasekhar", "Ramesh");
    p1.set_post_details("Cancer Patient", "Please Donate as much as you can, my brother is taking cancer treatment! Need Help!");
    p1.set_amount(100000);

    add_post_to_list(p1);
}