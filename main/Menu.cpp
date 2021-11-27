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
#include <cstdlib>

#include "main.h"
#include "Menu.h"
#include "Person.h"
#include "Transaction.h"
#include "Post.h"
#include "Block.h"
#include "ReadWrite.h"

using namespace std;

void main_menu()
{
    MAIN:
        
        char choose;
        
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
            case '1': user_login();
            break;
            
            case '2': {create_user(); PressEnter();}
            break;
            
            case '3': admin_login();
            break;
            
            case '4': {write_all(); exit(0);}
            
            default: cout << "\n !!Invalid Input!! ";
        }
        
    goto MAIN;    
}

void admin_main_menu()
{
    ADMIN:
        
        char choose;
        
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
            case '1': {mine_block(); PressEnter();}
            break;
            
            case '2': {display_Blockchain(); PressEnter();}
            break;
            
            case '3': {display_Ledger(); PressEnter();}
            break;
            
            case '4': {display_Mempool(); PressEnter();}
            break;
            
            case '5': {display_UserList(); PressEnter();}
            break;
            
            case '6': main_menu();
            break;
            
            default: cout << "\n !!Invalid Input!! ";
        }
        
    goto ADMIN;
}

void user_menu()
{
    USER:
        
        char choose;
        
        ClearOS();
        Title();
        
        cout << "\n\n Welcome " << UserList[Logged_User_ID - 1].get_User_Name() 
			 << " !! \n Your Public Key : " << UserList[Logged_User_ID - 1].get_User_Public_Key() 
			 << "\n Your Balance : " << UserList[Logged_User_ID - 1].get_User_Balance()
             << "\n\n Please select one of the following operations :- "
             << "\n\n 1. Donate Money "
             << "\n 2. Create Post "
			 << "\n 3. Display BlockChain "
             << "\n 4. Logout "
             << "\n\n Enter Your Choice : ";
        cin >> choose;
        
        switch(choose)
        {
            case '1': post_list_menu();
            break;
            
            case '2': org_list_menu();
            break;
			
			case '3': {display_Blockchain(); PressEnter();}
            break;
            
            case '4': main_menu();
            break;
            
            default: cout << "\n !!Invalid Input!! ";
        }
        
    goto USER;
}

// To check the string ia a number
bool Is_Number(string line)
{
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

void org_list_menu()
{
    ORGLISTMENU:
        
        ClearOS();
        
        char choose1;
        
        cout << "\n\n ********** List of Organizations ********** ";
        
        display_OrgList();
        
        cout << "\n\n 1. Select Organizations from above list "
             << "\n 2. Enter your new Organization Details (If your desired Organization is not in the above list) "
             << "\n 3. Return to User Menu "
             << "\n\n Enter Your Choice : ";
        cin >> choose1;
        
        switch(choose1)
        {
            case '1':
            {
                string choose2a;
                long choose2b;
                
                cout << "\n\n Enter the Organization ID you want to link from above list "
                     << "\n Enter Your Choice : ";
                cin >> choose2a;
                
                if(Is_Number(choose2a))
                {
                    choose2b = stoi(choose2a);
                    
                    if (choose2b >= 1 && choose2b <= OrgList_size)
                    {
                        enter_post_details(choose2b);
                    }
                    else
                    {
                        cout << "\n !!Invalid Organization ID!! ";
                        goto ORGLISTMENU;
                    }
                }
                else
                {
                    cout << "\n !!Invalid Organization ID!! ";
                    goto ORGLISTMENU;
                }                
            }
            break;
            
            case '2': create_org();
            break;
            
            case '3': user_menu();
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
        
        string choose1;
        int choose1b = 0;
        
        cout << "\n\n ********** List of Posts ********** ";
        
        display_PostList();
        
        cout << "\n\n Enter the Post ID you want to view and donate "
             << "\n Enter 0 to Return to User Menu "
             << "\n\n Enter Your Choice : ";
        cin >> choose1;
        
        if(Is_Number(choose1) == 1)
		{
            stringstream ss1(choose1);
            ss1 >> choose1b;
        }
        else
		{
            cout << "\n !!Invalid Input!! ";
            PressEnter();
			
            goto POSTLISTMENU;
        }
        
        switch(choose1b)
        {
            case 0: user_menu();
            break;
            
            default: 
            {
                ClearOS();
                int count = 0;
				
                for(int i=0; i<PostList_size; i++)
                {
                    if(PostList[i].get_Post_ID() == choose1b)
                    {
                        count = -1;
                        break;
                    }
                    else
                    {
                        count++;
                    }
                }
				
                if(count == -1)
				{
                    display_Post(choose1b);
                    donate_to_post_menu(choose1b);
                    PressEnter();
                }
                else
				{
                    cout << "\n !!Post Not Available!! ";
                    PressEnter();
                }
            }
        }
        
    goto POSTLISTMENU;
}

void donate_to_post_menu(long Post_ID)
{
    char choose2;
    
    cout << "\n\n 1. Donate to this Post "
         << "\n 2. Return to Post list "
         << "\n\n Enter Your Choice : ";
    cin >> choose2;
    
    switch(choose2)
    {
        case '1': donate_money_UI(Post_ID);
        break;
        
        case '2': post_list_menu();
        break;
        
        default: cout << "\n !!Invalid Input!! ";
    }
}
