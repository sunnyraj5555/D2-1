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

void main_menu()
{
    MAIN:
        
        int choose;
        
        ClearOS();
        Title();
        
        cout << "\n\n 1. Login as User "
             << "\n 2. SignUp as User "
             << "\n 3. Login as Admin "
             << "\n 4. Exit "
             << "\n\n Enter Your Choice : ";
        cin >> choose;
        
        switch(choose)
        {
            case 1: user_login();
            break;
            
            case 2: create_user();
            break;
            
            case 3: admin_login();
            break;
            
            case 4: exit(0);
            
            default: cout << "\n !!Invalid Input!! ";
        }
        
    goto MAIN;    
}

void admin_main_menu()
{
    ADMIN:
        
        int choose;
        
        ClearOS();
        Title();
        
        cout << "\n\n Welcome ADMIN !! \n Please select one of the following operations :- "
             << "\n\n 1. Mine a Block "
             << "\n 2. Display BlockChain "
             << "\n 3. Display Ledger "
             << "\n 4. Display Mempool "
             << "\n 5. Display UserList "
             << "\n 6. Logout "
             << "\n\n Enter Your Choice : ";
        cin >> choose;
        
        switch(choose)
        {
            case 1: {mine_block(); PressEnter();}
            break;
            
            case 2: {display_Blockchain(); PressEnter();}
            break;
            
            case 3: {display_Ledger(); PressEnter();}
            break;
            
            case 4: {display_Mempool(); PressEnter();}
            break;
            
            case 5: {display_UserList(); PressEnter();}
            break;
            
            case 6: main_menu();
            break;
            
            default: cout << "\n !!Invalid Input!! ";
        }
        
    goto ADMIN;
}

void user_menu()
{
    USER:
        
        int choose;
        
        ClearOS();
        Title();
        
        cout << "\n\n Welcome " << UserList[Logged_User_ID - 1].get_User_Name() << " !! \n Please select one of the following operations :- "
             << "\n\n 1. Donate Money "
             << "\n 2. Create Post "
             << "\n 3. Logout "
             << "\n\n Enter Your Choice : ";
        cin >> choose;
        
        switch(choose)
        {
            case 1: post_list_menu();
            break;
            
            case 2: org_list_menu();
            break;
            
            case 3: main_menu();
            break;
            
            default: cout << "\n !!Invalid Input!! ";
        }
        
    goto USER;
}

void org_list_menu()
{
    ORGLISTMENU:
        
        ClearOS();
        
        int choose1;
        
        cout << "\n\n ********** List of Organizations ********** ";
        
        display_OrgList();
        
        cout << "\n\n 1. Select Organizations from above list "
             << "\n 2. Enter your new Organization Details (If your desired Organization is not in the above list) "
             << "\n 3. Return to User Menu "
             << "\n\n Enter Your Choice : ";
        cin >> choose1;
        
        switch(choose1)
        {
            case 1:
            {
                long choose2;
                
                cout << "\n\n Enter the Organization ID you want to link from above list "
                     << "\n Enter Your Choice : ";
                cin >> choose2;
                
                if (choose2 >= 1 && choose2 <= OrgList_size)
                {
                    enter_post_details(choose2);
                }
                else
                {
                    cout << "\n !!Invalid Organization ID!! ";
                    goto ORGLISTMENU;
                }
                
            }
            break;
            
            case 2: create_org();
            break;
            
            case 3: user_menu();
            break;
            
            default: cout << "\n !!Invalid Input!! ";
        }
        
    goto ORGLISTMENU;
}


void post_list_menu()
{
    POSTLISTMENU:
        
        ClearOS();
        
        if(PostList_size == 0)
        {
            cout << "\n\n !! Currently no posts available for donation !! ";
            PressEnter();
            return ;
        }
        
        long choose1;
        
        cout << "\n\n ********** List of Posts ********** ";
        
        display_PostList();
        
        cout << "\n\n Enter the Post ID you want to view and donate "
             << "\n Enter 0 to Return to User Menu "
             << "\n\n Enter Your Choice : ";
        cin >> choose1;
        
        switch(choose1)
        {
            case 0: user_menu();
            break;
            
            default: 
            {
                ClearOS();
                
                display_Post(choose1);
                donate_to_post_menu(choose1);
            }
        }
        
    goto POSTLISTMENU;
}

void donate_to_post_menu(long Post_ID)
{
    int choose2;
    
    cout << "\n\n 1. Donate to this Post "
         << "\n 2. Return to Post list "
         << "\n\n Enter Your Choice : ";
    cin >> choose2;
    
    switch(choose2)
    {
        case 1: donate_money_UI(Post_ID);
        break;
        
        case 2: post_list_menu();
        break;
        
        default: cout << "\n !!Invalid Input!! ";
    }
}
