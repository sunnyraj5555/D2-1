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


void Organization::set_org_details(string org_name, string org_address, string org_phone_number ){
        this->org_name = org_name;
        this->org_address=org_address;
        this->org_phone_number=org_phone_number; 
    }
    void Organization::get_org_details(){
        cout<< "-----ORGANIZATION DETAILS------ "<<"\n";
        cout<<"Name:"<< org_name <<endl;
        cout<<"Address:"<<org_address <<endl;
        cout<<"Phone Number:"<<org_phone_number <<endl;
    }
    
    void Organization::set_Org_ID(){
        this->Org_ID = OrgList_size + 1;
    }
    long Organization::get_Org_ID(){
        return Org_ID;
    }
    
    string Organization::get_org_name(){
        return org_name;
    }
    
    string Organization::get_org_address(){
        return org_address;
    }
    string Organization::get_org_phone_number(){
        return org_phone_number;
    }
    void Organization::set_registration_number(long registration_number){
        this->registration_number=registration_number;
    }
    long Organization::get_registration_number(){
        return registration_number;
    }

void display_OrgList(){
    if(OrgList_size == 0){
        cout<<"No Org Found. "<<endl;
        return ;
    }
    for(int i =0;i<OrgList_size;i++){
        cout<<"\t"<<OrgList[i].get_Org_ID()<<" : "<<OrgList[i].get_org_name()<<" | "<<OrgList[i].get_org_address();
        cout<<endl;
    }
}

void add_org_to_list(Organization &o){
    OrgList[OrgList_size] = o;
    OrgList_size++;
    
    //cout<<"Organization Added successfully."<<endl;
}

bool verify_org(long Org_ID){
    // for(in the predefined array of govt. ID's){
    //     if(Org_ID == ID){
    //         return true;
    //     }
    // }
    // return false;
    
    return true;    //just returning true for now
}

 
void create_org(){
    long registration_number;
    
    cout<<"Enter the Organization Registration Num: ";
    cin>>registration_number;
    
    if(verify_org(registration_number)){
        enter_org_details(registration_number);
    }
    else{
        cout<<"Verification Failed. Org not valid."<<endl;
    }
}
