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
#include <regex>

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
    void User::set_User_Balance(long i){
        User_Balance = i;
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

void user_init(){
    //user 1
    User u1;
    u1.set_User_ID();
    u1.set_user_details("Sekhar", "9773526288", "sekhar@gmail.com", "sekhar");
    generate_keys(u1);   // this will be in encryption header file
    add_user_to_list(u1);

    //user 2

    User u2;
    u2.set_User_ID();
    u2.set_user_details("Aryan", "7521003731", "aryan@gmail.com", "aryan");
    generate_keys(u2);   // this will be in encryption header file
    add_user_to_list(u2);
}

// ================= To Check Phone Number =================
const int MAX = 10;
 
// Function that returns true if ch is a digit
bool IsDigit_Phone_No(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return true;
    }
    
    return false;
}
 
// Function that returns true if str contains all the digits from 0 to 9
bool Check_Phone_No(string str)
{
    int len = str.length();
    
    // To mark the present digits
    bool present[MAX] = { false };
 
    // For every character of the string
    for (int i = 0; i < len; i++) 
    {
        // If the current character is a digit
        if (IsDigit_Phone_No(str[i])) 
        {
            // Mark the current digit as present
            int digit = str[i] - '0';
            present[digit] = true;
        }
    }
 
    // For every digit from 0 to 9
    for (int i = 0; i < MAX; i++)
    {
        if (!present[i] && !(len == 10))
        {
            return false;
        }
    }
    
    return true;
}

// ================= To Check Email ID =================
bool Check_Email_ID(const string& email)
{
    // Regular expression definition
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
  
    // Match the string pattern with regular expression
    return regex_match(email, pattern);
}

// ================= To Check Password Strength ================= 
void Check_Password_Strength(string& input) 
{
    int n = input.length();
    
    bool hasLower = false, hasUpper = false;
    bool hasDigit = false, specialChar = false;
    string normalChars = "abcdefghijklmnopqrstu" "vwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
    
    for (int i = 0; i < n; i++) 
    {
        if (islower(input[i]))
        {
            hasLower = true;
        }
        if (isupper(input[i]))
        {
            hasUpper = true;
        }
        if (isdigit(input[i]))
        {
            hasDigit = true;
        }
        
        size_t special = input.find_first_not_of(normalChars);
        
        if (special != string::npos)
        {
            specialChar = true;
        }
    }
    
    // Check Password Strength
    cout << "\n Password Strength : ";
    
    if (hasLower && hasUpper && hasDigit && specialChar && (n >= 8))
    {
        cout << " Strong ";
    }
    else if ((hasLower || hasUpper) && specialChar && (n >= 6))
    {
        cout << " Moderate ";
    }
    else
    {
        cout << " Weak ";
    }
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
    
    PHONENO:
    cout << "\n Enter Phone_No : "; getline(cin, Phone_No);
    
    if(Check_Phone_No(Phone_No) == false)
    {
        cout << "\n !!Invalid Phone Number!! !!Please Enter Again!! \n";
        goto PHONENO;
    }
    
    EMAILID:
    cout << "\n Enter Email_ID : "; getline(cin, Email_ID);
    
    if(Check_Email_ID(Email_ID) == 0)
    {
        cout << "\n !!Invalid Email ID!! !!Please Enter Again!! \n";
        goto EMAILID;
    }
    
    char ch;
    
    cout << "\n Enter Password : "; getline(cin, Password);
    
    PASSWORD:
    Check_Password_Strength(Password);
    
    cout << "\n Want to change Password, enter Y or N : "; cin >> ch;
    
    if(ch == 'Y' || ch == 'y')
    {
        cout << "\n Enter Password : "; cin.ignore(); getline(cin, Password);
        goto PASSWORD;
    }

    User u;
    u.set_User_ID();
    u.set_user_details(Name, Phone_No, Email_ID, Password);
    generate_keys(u);   // this will be in encryption header file

    add_user_to_list(u);

    cout << "\n !!User Created Successfuly!! ";
}

void generate_keys(User &u)
{
   keys(u);
   cout << "\n !!Keys Created Successfuly!! ";
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
		cout << "\n User Balance : " << UserList[i].get_User_Balance();
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
        cout << "\n !!Invalid Admin Credentials!! ";
        PressEnter();
    }
}
