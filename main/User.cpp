/*
 *  User.cpp
 *
 *  Created on: 1-Oct-2021
 *     Authors: Tanishka Vaswani, M Somasekhar, Aryan Mukerji
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

User UserList[N];
long UserList_size = 0;
long Logged_User_ID;
User Admin;

    void User::set_User_ID()
    {
        User_ID = UserList_size + 1;
    }
    
    void User::set_User_ID(long uid)
    {
        User_ID = uid;
    }
    
    long User::get_User_ID()
    {
        return User_ID;
    }
    
    void User::set_user_details(string Name, string Phone_No, string Email_ID, string Password)
    {
        User_Balance = 100000;
        this->Name = Name;
        this->Phone_No = Phone_No;
        this->Email_ID = Email_ID;
        this->Password = Password;
    }
    
    void User::set_user_private_key(int Private_Key)
    {
        this->Private_Key = Private_Key;
    }
    
    void User::set_user_public_key(int Public_Key)
    {
        this->Public_Key = Public_Key;
    }
    
    void User::set_user_EDFactor(int EDFactor)
    {
        this->EDFactor = EDFactor;
    }
    
    void User::get_User()
    {
        cout << "\n Name : " << Name;
        cout << "\n Phone_No : " << Phone_No;
        cout << "\n Email_ID : " << Email_ID;
    }
        
    string User::get_User_Name()
    {
        return Name;
    }
    
    string User::get_User_Phone_No()
    {
        return Phone_No;
    }
    
    string User::get_User_Email()
    {
        return Email_ID;
    }
    
    string User::get_User_Password()
    {
        return Password;
    }
    
    long User::get_User_Balance()
    {
        return User_Balance;
    }
    
    long User::get_User_Public_Key()
    {
        return Public_Key;
    }
    
    long User::get_User_Private_Key()
    {
        return Private_Key;
    }
    
    int User::get_User_EDFactor()
    {
        return EDFactor;
    }
    
    void User::deduct_User_Balance(long amount)
    {
        User_Balance -= amount;
    }

void admin_init()
{
    Admin.set_User_ID(0);
    Admin.set_user_details("Admin","123456789","admin","admin");
    generate_keys(Admin);
    cout << "\n !!Admin Created!! " << endl;
}

void create_user()
{
    ClearOS();
    Title();
    
    string Name, Phone_No, Email_ID, Password;
    string Public_Key, Private_Key;
    
    cout << "\n\n ********** Enter User Details ********** ";
    
    cin.ignore();
    cout << "\n\n Enter Name : "; getline(cin, Name);
    cout << "\n Enter Phone_No : "; getline(cin, Phone_No);
    cout << "\n Enter Email_ID : "; getline(cin, Email_ID);
    cout << "\n Enter Password : "; getline(cin, Password);

    User u;
    u.set_User_ID();
    u.set_user_details(Name, Phone_No, Email_ID, Password);
    generate_keys(u);   //this will be in encryption header file

    add_user_to_list(u);

    cout << "\n !!User Created Successfuly!! ";
}

void generate_keys(User &u)
{
   keys(u);
   //detailed implementation in encrytption file, for now hard coding
}

void add_user_to_list(User &u)
{
    UserList[UserList_size] = u;
    UserList_size++;
}

void display_UserList()
{
    ClearOS();
    
    if(UserList_size == 0)
    {
        cout<<"\n !!No Users Found!! ";
        return ;
    }
    
    cout << "\n\n ********** User List ********** ";
    
    for(int i=0; i<UserList_size; i++)
    {
        cout << "\n\n User ID : " << UserList[i].get_User_ID();
        cout << "\n Name : " << UserList[i].get_User_Name();
        cout << "\n Phone Number : " << UserList[i].get_User_Phone_No();
        cout << "\n Email : " << UserList[i].get_User_Email();
        cout << "\n Password : " << UserList[i].get_User_Password();
        cout << "\n Private Key : " << UserList[i].get_User_Private_Key();
        cout << "\n Public Key : " << UserList[i].get_User_Public_Key();
    }
}

long login_verify(string username, string password)      // this will return User_Id of user from UserList
{        
    for(int i=0; i<UserList_size; i++)
    {
        if(UserList[i].get_User_Email() == username && UserList[i].get_User_Password() == password)
        {
            return UserList[i].get_User_ID();
        }
    }
    
    return 0;
}

void user_login()
{
    ClearOS();
    Title();
    
    string Email_ID, Password;
    
    cout << "\n\n ********** User LogIn ********** ";
    
    cin.ignore();
    cout << "\n\n Email : "; getline(cin, Email_ID);
    cout << "\n Password : "; getline(cin, Password);

    long uid = login_verify(Email_ID, Password);
    
    if(uid == 0)
    {
        cout << "\n !!Invalid User Credentials!! Retry!! ";
        PressEnter();
        return ;
    }
    else
    {
        Logged_User_ID = uid;
        user_menu();
    }
}

void admin_login()
{
    ClearOS();
    Title();
    
    string Email_ID, Password;
    
    cout << "\n\n ********** Admin LogIn ********** ";
    
    cin.ignore();
    cout<<"\n\n Email : "; getline(cin, Email_ID);
    cout<<"\n Password : "; getline(cin, Password);


    if(Email_ID == "admin" && Password == "admin")
    {
        admin_main_menu();
    }
    else
    {
        cout<<"\n !!Invalid Admin Credentials!! ";
        PressEnter();
    }
}
