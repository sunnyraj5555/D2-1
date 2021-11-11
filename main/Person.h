/*
 *  Person.h
 *  
 *  It is the common header file for User.cpp and Organisation.cpp
 *  
 *  Created on: 1-Oct-2021
 *     Authors: Aryan Mukerji
 */

#include <iostream>
#include <cstring>

using namespace std;
#define N 100

#ifndef PERSON_H
#define PERSON_H

// ================================= User.cpp ==================================

class User
{
    long User_ID;
    string Name;        
    string Phone_No;
    string Email_ID;
    string Password;
    int Public_Key, Private_Key, EDFactor;
    long User_Balance;
    
    public:
    
    void set_User_ID();
    void set_User_ID(long uid);   // overloaded for assigning admin ID manually
    long get_User_ID();
    void set_user_details(string Name,string Phone_No,string Email_ID,string Password);
    // void set_user_keys(long Private_Key, long Public_Key);
    void set_user_private_key(int Private_Key);
    void set_user_public_key(int Public_Key);
    void set_user_EDFactor(int EDFactor);
    
    void get_User();
    string get_User_Name();
    string get_User_Phone_No();
    string get_User_Email();
    string get_User_Password();
    long get_User_Public_Key();
    long get_User_Private_Key();
    int get_User_EDFactor();
    long get_User_Balance();

    void deduct_User_Balance(long amount);
};

extern User UserList[N];
extern long UserList_size ;
extern long Logged_User_ID;
extern User Admin;

void admin_init();
bool IsDigit_Phone_No(char ch);
bool Check_Phone_No(string str);
bool Check_Email_ID(const string& email);
void Check_Password_Strength(string& input);
void create_user();
void add_user_to_list(User &u);
void display_UserList();

void user_login();
void login_verify();
void admin_login();

void generate_keys(User &u);   // this will be in the encryption headerfile

// ============================== Organisation.cpp =============================

class Organization
{
    private:
    
    string org_name;
    string org_address;
    long registration_number; // This is the registration number provided by government
    string org_phone_number;
    long Org_ID;    // This is the organiztion ID provided by D2 to all Organization
  
    public:
  
    void set_Org_ID();
    void set_Org_ID(long i);
    long get_Org_ID();
  
    void set_org_details(string org_name, string org_address, string org_phone_number );
    void get_org_details();
  
    string get_org_name();
    string get_org_address();
    string get_org_phone_number();
    void set_registration_number(long registration_number);
    long get_registration_number();
};

extern Organization OrgList[N];
extern long OrgList_size;

void display_OrgList();
void add_org_to_list(Organization &o);
bool verify_org(long Org_ID);
void create_org();

void intitialise_OrgList();


#endif /* PERSON_H */
