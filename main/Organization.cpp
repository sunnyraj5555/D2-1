/*
 *  Organization.h
 *
 *  Created on: 06-oct-2021
 *     Authors: Sunny Raj, M Somasekhar, Aryan Mukerji
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

Organization OrgList[N];
long OrgList_size = 0;

    void Organization::set_org_details(string org_name, string org_address, string org_phone_number)
    {
        this->org_name = org_name;
        this->org_address = org_address;
        this->org_phone_number = org_phone_number; 
    }
    
    void Organization::get_org_details()
    {
        cout << "\n\n ********** Organization Details ********** "
             << "\n\n Name : " << org_name
             << "\n Address : " << org_address
             << "\n Phone Number : " << org_phone_number;
    }
    
    void Organization::set_Org_ID()
    {
        this->Org_ID = OrgList_size + 1;
    }
    
    long Organization::get_Org_ID()
    {
        return Org_ID;
    }
    
    string Organization::get_org_name()
    {
        return org_name;
    }
    
    string Organization::get_org_address()
    {
        return org_address;
    }
    
    string Organization::get_org_phone_number()
    {
        return org_phone_number;
    }
    
    void Organization::set_registration_number(long registration_number)
    {
        this->registration_number = registration_number;
    }
    
    long Organization::get_registration_number()
    {
        return registration_number;
    }

void display_OrgList()
{
    if(OrgList_size == 0)
    {
        cout << "\n !!No Organization Found!! ";
        return ;
    }
    
    for(int i=0; i<OrgList_size; i++)
    {
        cout << "\n " << OrgList[i].get_Org_ID() << " : " << OrgList[i].get_org_name() << " | " << OrgList[i].get_org_address();
    }
}

void add_org_to_list(Organization &o)
{
    OrgList[OrgList_size] = o;
    OrgList_size++;
    
    cout << "\n !!Organization Added successfully!! ";
}

bool verify_org(long Org_ID)
{
    // for(in the predefined array of govt. ID's){
    //     if(Org_ID == ID){
    //         return true;
    //     }
    // }
    // return false;
    
    return true;    // just returning true for now
}

void create_org()
{
    ClearOS();
    
    long registration_number;
    
    cout << "\n\n Enter the Organization Registration Number : ";
    cin >> registration_number;                                      //////////// !!! gives error if given character input !!!
    
    if(verify_org(registration_number))
    {
        enter_org_details(registration_number);
    }
    else
    {
        cout << "\n !!Verification Failed, Organization not valid!! ";
    }
}

void intitialise_OrgList()
{
    Organization org1, org2, org3, org4;
    
    org1.set_Org_ID();
    org1.set_registration_number(2101);
    org1.set_org_details("Nazareth Hospital", "Prayagraj, Uttar Pradesh", "7393254831");
    
    add_org_to_list(org1);
    
    org2.set_Org_ID();
    org2.set_registration_number(1002);
    org2.set_org_details("Medanta Medicity", "Gurugram, Haryana", "8527690666");

    add_org_to_list(org2);
    
    org3.set_Org_ID();
    org3.set_registration_number(2103);
    org3.set_org_details("Priti Hospital", "Prayagraj, Uttar Pradesh", "6393283820");
    
    add_org_to_list(org3);
    
    org4.set_Org_ID();
    org4.set_registration_number(2103);
    org4.set_org_details("Lalitha Hospital", "New Delhi, Delhi", "9811898880");
    
    add_org_to_list(org4);

    post_init();
}
