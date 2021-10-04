//============================================================================
// Name         : main.cpp
// Authors      : Aryan Mukerji, M Somasekhar, Sunny Raj, Tanishka Vaswani
// Version      : 1.0
// Copyright    : MIT License
// Description  : D2: Blockchain Based Secure Donation System
//============================================================================

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

void Title()
{
    cout << "\n\n ========================================================= "
         << "\n        D2: Blockchain Based Secure Donation System "
         << "\n ========================================================= ";
}

void PressEnter()
{
    cout << "\n\n\n Press ENTER to continue ... ";
    cin.get(); //(expected for Enter, need #include <iostream>).
    cin.get();
}

void ClearOS()
{
    // Source: https://iq.opengenus.org/detect-operating-system-in-c/
    
	#ifdef _WIN32
		system("cls"); // Windows Operating System
	#endif
	
	#ifdef __linux__
		system("clear"); // Linux Operating System
	#endif
	
	#ifdef __unix__
		system("clear"); // Unix Operating System
	#endif
}

int main()
{
    ClearOS();
        
    create_Genesis_Block();
    intitialise_OrgList();
    admin_init();
    
    ClearOS();
    
    main_menu();
    
    return 0;
}