/*
 *  Post.h
 *  
 *  Created on: 1-Oct-2021
 *     Authors: M Somasekhar, Aryan Mukerji
 */

#include <iostream>
#include <cstring>

using namespace std;
#define N 100

#ifndef POST_H
#define POST_H

class Post 
{
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
    string get_org_name();

    void set_amount(long amount_requested);
    void deduct_money(long amount_received);
    long get_amount_requested();
    long get_amount_collected();
    long get_amount_left();
};

extern Post PostList[N];
extern long PostList_size;

void display_PostList();
void display_Post(long Post_ID);
void add_post_to_list(Post &p);
void enter_org_details(long registration_number);
void enter_post_details(long Org_ID);
void post_init();

#endif /* POST_H */
