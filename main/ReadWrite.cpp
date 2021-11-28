#include <iostream>
#include <fstream>
#include <cstring>
#include "ReadWrite.h"
#include "Transaction.h"
#include "main.h"
#include "Menu.h"
#include "Person.h"
#include "Post.h"
#include "Block.h"

using namespace std;


bool Is_empty(ifstream& pFile)
{
    return pFile.peek() == ifstream::traits_type::eof();
}

void Check_UserList()
{
    ofstream f2;
    ifstream f1("UserList.txt");
    string temp = "1~Somasekhar~9773526288~sekhar@gmail.com~sekhar~575~177229151~943690563~100000~\n";
    string temp1 = "2~Aryan Mukerji~7379587258~aryan@gmail.com~aryan~871~785414831~943690563~100000~\n";
    string temp2 = "3~Sunny Raj~8107706727~sunny@gmail.com~sunny~87~824277767~943690563~100000~\n";
    string temp3 = "4~Tanishka Vaswani~8130112876~tanishkavaswani1@gmail.com~tanishka21~341~572789717~943690563~100000~\n";
    if(Is_empty(f1) == true)
    {
        f2.open("UserList.txt");
        f2 << temp;   // int i = -1;
        f2 << temp1;   // int i = -1;
        f2 << temp2;   // int i = -1;
        f2 << temp3;   // int i = -1;
    }
    
    f2.close();
    f1.close();
}

void Check_UserList_size()
{
    ofstream f2;
    ifstream f1("UserList_size.txt");
    
    if(Is_empty(f1) == true)
    {
        f2.open("UserList_size.txt");
        f2 << 4;
    }
    
    f2.close();
    f1.close();
}

void Check_Transaction_Ids()
{
    ofstream f2;
    ifstream f1("Transaction_Ids.txt");
    
    if(Is_empty(f1) == true)
    {
        f2.open("Transaction_Ids.txt");
        f2 << 0;
    }
    
    f2.close();
    f1.close();
}

void Check_PostList_size()
{
    ofstream f2;
    ifstream f1("PostList_size.txt");
    
    if(Is_empty(f1) == true)
    {
        f2.open("PostList_size.txt");
        f2 << 2;
    }
    
    f2.close();
    f1.close();
}

void Check_PostList()
{
    ofstream f2;
    ifstream f1("PostList.txt");
    
    string temp = "1~5000~0~5000~Suffering from Covid-19!~Please Donate! Need Help!~2~Aryan~Surya~1~Nazareth Hospital~Prayagraj, Uttar Pradesh~7393254831\n";
    string temp1 = "2~100000~0~100000~Cancer Patient~Please Donate as much as you can, my brother is taking cancer treatment! Need Help!~1~Somasekhar~Ramesh~1~Nazareth Hospital~Prayagraj, Uttar Pradesh~7393254831\n";
    
    if(Is_empty(f1) == true)
    {
        f2.open("PostList.txt");
        f2 << temp;   // int i = -1;
        f2 << temp1;   // int i = -1;
    }
    
    f2.close();
    f1.close();
}

void Check_OrgList_size()
{
    ofstream f2;
    ifstream f1("OrgList_size.txt");
    
    if(Is_empty(f1) == true)
    {
        f2.open("OrgList_size.txt");
        f2 << 4;
    }
    
    f2.close();
    f1.close();
}

void Check_OrgList()
{
    ofstream f2;
    ifstream f1("OrgList.txt");
    string temp = "1~1~Nazareth Hospital~Prayagraj, Uttar Pradesh~7393254831\n";
    string temp1 = "2~2~Medanta Medicity~Gurugram, Haryana~8527690666\n";
    string temp2 = "3~3~Priti Hospital~Prayagraj, Uttar Pradesh~6393283820\n";
    string temp3 = "4~4~Lalitha Hospital~New Delhi, Delhi~9811898880\n";
    if(Is_empty(f1) == true)
    {
        f2.open("OrgList.txt");
        f2 << temp;   // int i = -1;
        f2 << temp1;   // int i = -1;
        f2 << temp2;   // int i = -1;
        f2 << temp3;   // int i = -1;
    }
    
    f2.close();
    f1.close();
}

void Check_Mempool_size()
{
    ofstream f2;
    ifstream f1("Mempool_size.txt");
    
    if(Is_empty(f1) == true)
    {
        f2.open("Mempool_size.txt");
        f2 << 0;
    }
    
    f2.close();
    f1.close();
}

void Check_Ledger_size()
{
    ofstream f2;
    ifstream f1("Ledger_size.txt");
    
    if(Is_empty(f1) == true)
    {
        f2.open("Ledger_size.txt");
        f2 << 0;
    }
    
    f2.close();
    f1.close();
}

void Check_BlockChain_size()
{
    ofstream f2;
    ifstream f1("BlockChain_size.txt");
    
    if(Is_empty(f1) == true)
    {
        f2.open("BlockChain_size.txt");
        f2 << 1;
    }
    
    f2.close();
    f1.close();
}

void file_init(){
    Check_UserList_size();
    Check_UserList();
    Check_Transaction_Ids();
    Check_PostList_size();
    Check_PostList();
    
    Check_OrgList_size();
    Check_OrgList();
    
    Check_Mempool_size();
    Check_Ledger_size();
    Check_BlockChain_size();
}

void read_all(){
    read_Transaction_Ids();

    read_Mempool_size();
    if(Mempool_size > 0)
        read_Mempool();
        
    read_Ledger_size();
    if(Ledger_size > 0)
        read_Ledger();
    
    read_BlockChain_size();
    if(BlockChain_size > 1)
        read_BlockChain();

    read_OrgList_size();
    if(OrgList_size > 0)
        read_OrgList();
    
    read_PostList_size();
    if(PostList_size > 0)
        read_PostList();
    
    read_UserList_size();
    if(UserList_size > 0)
        read_UserList();
}

void write_all(){
    write_Transaction_Ids();
    write_Mempool_size();
    write_Mempool();
    write_Ledger_size();
    write_Ledger();
    write_BlockChain_size();
    write_BlockChain();
    write_OrgList_size();
    write_OrgList();
    write_PostList_size();
    write_PostList();
    write_UserList_size();
    write_UserList();

    //cout<<"Write Successful"<<endl;
}
//-------------------FILE HANDELING MODULES / FUNCTIONS-------------------------------------------------

// ------------------Transaction_Ids--------------------------------------------------------------------

void read_Transaction_Ids(){
    ifstream fin;

	fin.open("Transaction_Ids.txt");
	
	fin >> Transaction_Ids;
	  
	fin.close();
    //cout<<"reading size"<<endl;
    //cout<<Transaction_Ids<<endl;
}

void write_Transaction_Ids(){
    ofstream fout;
	fout.open("Transaction_Ids.txt");
    
    fout << Transaction_Ids;
    
	fout.close();
	// cout<<"written size"<<endl;
}

//-------------------- CSV Generation of Transactions --------------------------------------------------

string create_Transaction_string(Transaction &t){
    string s = "";
    s += to_string(t.get_Transaction_ID());
    s += ",";
    s += t.get_sender();
    s += ",";
    s += t.get_reciever();
    s += ",";
    s += to_string(t.get_amount());
    //cout<<s<<endl;
    return s;
}

void extract_Transaction(string s, Transaction &t){ //later obejct will also be passed as Transaction &Transaction
    string t_id = "", sender = "", reciever = "", amt = "";
    long long amount =0;
    long Transaction_ID;
    int index =0;
    for(int i =0;i<s.length();i++){
        if(s[i] == ','){
            index = i+1;
            break;
        }
        t_id = t_id + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == ','){
            index = i+1;
            break;
        }
        sender = sender + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == ','){
            index = i+1;
            break;
        }
        reciever = reciever + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == ','){
            index = i+1;
            break;
        }
        amt = amt + s[i];
    }
    // cout<<sender<<endl;
    // cout<<reciever<<endl;

    stringstream ss(t_id);
    ss >> Transaction_ID;
    //cout<<Transaction_ID<<endl;


    stringstream ss1(amt);
    ss1 >> amount;
    //cout<<amount<<endl;
    
    t.set_Transaction(sender,reciever,amount,Transaction_ID);
    
}

//-------------------------------- MEMPOOL --------------------------------------------------------


void write_Mempool_size(){
    ofstream fout;
	fout.open("Mempool_size.txt");
    
    fout << Mempool_size;
    
	fout.close();
	//cout<<"written size"<<endl;
}

void read_Mempool_size(){
    ifstream fin;

	fin.open("Mempool_size.txt");
	
	fin >> Mempool_size;
	  
	fin.close();
    //cout<<"reading size"<<endl;
    //cout<<Mempool_size<<endl;
}


void write_Mempool(){
    string *s = new string[Mempool_size];

    for(int i =0;i<Mempool_size;i++){
        s[i] = create_Transaction_string(Mempool[i]);
    }

    ofstream fout;
	fout.open("Mempool.txt");

	for(int i =0;i<Mempool_size;i++)
		fout << s[i] << endl;

	fout.close();
  
}

void read_Mempool(){

    string *s = new string[Mempool_size];
 	ifstream fin;

	fin.open("Mempool.txt");
	
	for(int i =0;i<Mempool_size;i++)
	    getline(fin, s[i]);
	  
	fin.close();

    for(int i=0;i<Mempool_size;i++){
        extract_Transaction(s[i], Mempool[i]);
    }

}

//------------------------------------ LEDGER ----------------------------------------------------------

void write_Ledger_size(){
    ofstream fout;
	fout.open("Ledger_size.txt");
    
    fout << Ledger_size;
    
	fout.close();
	//cout<<"written size"<<endl;
}

void read_Ledger_size(){
    ifstream fin;
	fin.open("Ledger_size.txt");
	fin >> Ledger_size;
	  
	fin.close();
    //cout<<"reading size"<<endl;
    //cout<<Ledger_size<<endl;
}

void write_Ledger(){
    string *s = new string[Ledger_size];

    for(int i =0;i<Ledger_size;i++){
        s[i] = create_Transaction_string(Ledger[i]);
    }

    ofstream fout;
	fout.open("Ledger.txt");

	for(int i =0;i<Ledger_size;i++)
		fout << s[i] << endl;

	fout.close();
}

void read_Ledger(){
    string *s = new string[Ledger_size];
 	ifstream fin;

	fin.open("Ledger.txt");
	
	for(int i =0;i<Ledger_size;i++)
	    getline(fin, s[i]);
	  
	fin.close();

    for(int i=0;i<Ledger_size;i++){
        extract_Transaction(s[i], Ledger[i]);
    }
}

//------------------------- CSV Generation of BLOCKS ------------------------------------

string create_Block_string(Block &b){
    string s = "";

    s += to_string(b.get_BlockNumber());
    s += ",";
    s += b.get_Previous_Hash();
    s += ",";
    s += b.get_Block_Hash();
    s += ",";
    s += to_string(b.get_No_of_Transactions_in_Block());

    for(int i =0;i<b.get_No_of_Transactions_in_Block();i++){
        Transaction t =b.get_Transactions_in_the_Block(i);
        string trans_string = create_Transaction_string(t);
        s += "#";
        s += trans_string;
    }
    return s;
}

void extract_Block(string s, Block &b){

    string block_num = "", num_trans_in_block = "", Previous_Hash = "" , Block_Hash = "";
    Transaction Transactions_in_the_Block[N];
    long No_of_Transactions_in_Block;
    long BlockNumber;
    
    int index = 0;
    for(int i =0;i<s.length();i++){
        if(s[i] == ','){
            index = i+1;
            break;
        }
        block_num = block_num + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == ','){
            index = i+1;
            break;
        }
        Previous_Hash = Previous_Hash + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == ','){
            index = i+1;
            break;
        }
        Block_Hash = Block_Hash + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '#'){
            index = i+1;
            break;
        }
        num_trans_in_block = num_trans_in_block + s[i];
    }
   

    stringstream ss(block_num);
    ss >> BlockNumber;
    b.set_BlockNumber(BlockNumber);

    b.set_Previous_Hash(Previous_Hash);
    b.set_Block_Hash(Block_Hash);

    stringstream ss1(num_trans_in_block);
    ss1 >> No_of_Transactions_in_Block;

    b.set_No_of_Transactions_in_Block(No_of_Transactions_in_Block);

    for(int j =0;j<No_of_Transactions_in_Block;j++){
        string trans = "";
        for(int i =index;i<s.length();i++){
            if(s[i] == '#'){
                index = i+1;
                break;
            }
            trans = trans + s[i];
        }
        extract_Transaction(trans, Transactions_in_the_Block[j]);
    }
 
    for(int i =0; i<No_of_Transactions_in_Block;i++){
        b.fill_transactions_in_the_block(Transactions_in_the_Block[i],i);
    }
    
}

//--------------------------------------- BLOCK ------------------------------------------------

void write_BlockChain_size(){
    ofstream fout;
	fout.open("BlockChain_size.txt");
    
    fout << BlockChain_size;
    
	fout.close();
	//cout<<"written size"<<endl;
}

void read_BlockChain_size(){

    ifstream fin;

	fin.open("BlockChain_size.txt");
	
	fin >> BlockChain_size;
	  
	fin.close();
    //cout<<"reading size"<<endl;
    //cout<<BlockChain_size<<endl;
}

void write_BlockChain(){
    string *s = new string[BlockChain_size];

    for(int i =0;i<BlockChain_size;i++){
        s[i] = create_Block_string(BlockChain[i+1]);
    }

    ofstream fout;
	fout.open("BlockChain.txt");

	for(int i =0;i<BlockChain_size-1;i++)
		fout << s[i] << endl;

	fout.close();
}

void read_BlockChain(){

    string *s = new string[BlockChain_size];
 	ifstream fin;

	fin.open("BlockChain.txt");
	
	for(int i =0;i<BlockChain_size;i++)
	    getline(fin, s[i]);
	  
	fin.close();

    for(int i=0;i<BlockChain_size;i++){
        extract_Block(s[i], BlockChain[i+1]);
    }

}

//------------------------- CSV Generation of Organizations ------------------------------------
string create_Organization_string(Organization &o){

    string s = "";

    s += to_string(o.get_Org_ID());
    s += "~";
    s += to_string(o.get_registration_number());
    s += "~";
    s += o.get_org_name();
    s += "~";
    s += o.get_org_address();
    s += "~";
    s += o.get_org_phone_number();
    //cout<<s<<endl;
    return s;
}

void extract_Organization(string s, Organization &o){
    string org_id = "", reg_num = "", org_name = "", org_address = "", org_phone_number = "";
    long registration_number; 
    long Org_ID;

    int index =0;
    for(int i =0;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        org_id = org_id + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        reg_num = reg_num + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        org_name = org_name + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        org_address = org_address + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        org_phone_number = org_phone_number + s[i];
    }

    stringstream ss(org_id);
    ss >> Org_ID;
    //cout<<Transaction_ID<<endl;


    stringstream ss1(reg_num);
    ss1 >> registration_number;

    o.set_Org_ID(Org_ID);
    o.set_registration_number(registration_number);
    o.set_org_details(org_name, org_address, org_phone_number);

}

//--------------------------- ORGANIZATIONS ---------------------------------------
void write_OrgList_size(){
    ofstream fout;
	fout.open("OrgList_size.txt");
    
    fout << OrgList_size;
    
	fout.close();
	//cout<<"written size"<<endl;
}

void read_OrgList_size(){
    ifstream fin;

	fin.open("OrgList_size.txt");
	
	fin >> OrgList_size;
	  
	fin.close();
    //cout<<"reading size"<<endl;
    //cout<<OrgList_size<<endl;
}

void write_OrgList(){
    string *s = new string[OrgList_size];

    for(int i =0;i<OrgList_size;i++){
        s[i] = create_Organization_string(OrgList[i]);
    }

    ofstream fout;
	fout.open("OrgList.txt");

	for(int i =0;i<OrgList_size;i++)
		fout << s[i] << endl;

	fout.close();
}


void read_OrgList(){
    string *s = new string[OrgList_size];
 	ifstream fin;

	fin.open("OrgList.txt");
	
	for(int i =0;i<OrgList_size;i++)
	    getline(fin, s[i]);
	  
	fin.close();

    for(int i=0;i<OrgList_size;i++){
        extract_Organization(s[i], OrgList[i]);
    }

}

//------------------------- CSV Generation of POSTS ------------------------------------

string create_Post_string(Post &p){
    string s = "";
    
    s += to_string(p.get_Post_ID());
    s += "~";
    s += to_string(p.get_amount_requested());
    s += "~";
    s += to_string(p.get_amount_collected());
    s += "~";
    s += to_string(p.get_amount_left());
    s += "~";
    s += p.get_Post_Title();
    s += "~";
    s += p.get_Post_Description();
    s += "~";

    s += to_string(p.get_User_ID());
    s += "~";
    s += p.get_user_name();
    s += "~";
    s += p.get_patient_name();
    s += "~";
    
    s += to_string(p.get_Org_ID());
    s += "~";
    s += p.get_org_name();
    s += "~";
    s += p.get_org_address();
    s += "~";
    s += p.get_org_phone_number();

    return s;
}


void extract_Post(string s, Post &p){

    string post_id = "", amt_req = "", amt_col = "", amt_left = "", Post_Title = "", Post_Description = "";
    long Post_ID;
    long amount_requested, amount_collected, amount_left;
    
    string user_id = "", user_name = "", patient_name = "";
    long User_ID;

    string org_id = "", org_name = "", org_address = "", org_phone_number = "";
    long Org_ID;

    int index =0;

    for(int i =0;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        post_id = post_id + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        amt_req = amt_req + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        amt_col = amt_col + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        amt_left = amt_left + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        Post_Title = Post_Title + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        Post_Description = Post_Description + s[i];
    }




    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        user_id = user_id + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        user_name = user_name + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        patient_name = patient_name + s[i];
    }



    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        org_id = org_id + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        org_name = org_name + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        org_address = org_address + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        org_phone_number = org_phone_number + s[i];
    }

    stringstream ss(post_id);
    ss >> Post_ID;

    stringstream ss1(amt_req);
    ss1 >> amount_requested;

    stringstream ss2(amt_col);
    ss2 >> amount_collected;

    stringstream ss3(amt_left);
    ss3 >> amount_left;

    stringstream ss4(user_id);
    ss4 >> User_ID;

    stringstream ss5(org_id);
    ss5 >> Org_ID;

    p.set_Post_ID(Post_ID);
    p.set_amount(amount_requested);
    p.set_amount_collected(amount_collected);
    p.set_amount_left(amount_left);
    p.set_post_details(Post_Title, Post_Description);

    p.set_user_details( User_ID,  user_name,  patient_name);
    p.set_org_details( Org_ID,  org_name,  org_address,  org_phone_number);

}
//----------------------------- POSTS ----------------------------------------
void write_PostList_size(){
    ofstream fout;
	fout.open("PostList_size.txt");
    
    fout << PostList_size;
    
	fout.close();
	//cout<<"written size"<<endl;
}

void read_PostList_size(){
    ifstream fin;

	fin.open("PostList_size.txt");
	
	fin >> PostList_size;
	  
	fin.close();
    //cout<<"reading size"<<endl;
    //cout<<PostList_size<<endl;
}

void write_PostList(){
    string *s = new string[PostList_size];

    for(int i =0;i<PostList_size;i++){
        s[i] = create_Post_string(PostList[i]);
    }

    ofstream fout;
	fout.open("PostList.txt");

	for(int i =0;i<PostList_size;i++)
		fout << s[i] << endl;

	fout.close();

}
void read_PostList(){
    string *s = new string[PostList_size];
 	ifstream fin;

	fin.open("PostList.txt");
	
	for(int i =0;i<PostList_size;i++)
	    getline(fin, s[i]);
	  
	fin.close();

    for(int i=0;i<PostList_size;i++){
        extract_Post(s[i], PostList[i]);
    }
}


//------------------------- CSV Generation of USERS ------------------------------------


string create_User_string(User &u){
    string s = "";
    s += to_string(u.get_User_ID());
    s += "~";
    s += u.get_User_Name();
    s += "~";
    s += u.get_User_Phone_No();
    s += "~";
    s += u.get_User_Email();
    s += "~";
    s += u.get_User_Password();
    s += "~";

    s += to_string(u.get_User_Public_Key());
    s += "~";
    s += to_string(u.get_User_Private_Key());
    s += "~";
    s += to_string(u.get_User_EDFactor());
    s += "~";
    s += to_string(u.get_User_Balance());
    s += "~";

    return s;

}
void extract_User(string s, User &u){
    
    string user_id = "", Name = "", Phone_No = "", Email_ID = "", Password = "" ;
    long User_ID;

    string pub_key = "", priv_key = "",ed_factor = "", user_bal = "";
    int Public_Key, Private_Key, EDFactor;
    long User_Balance;

    int index =0;

    for(int i =0;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        user_id = user_id + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        Name = Name + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        Phone_No = Phone_No + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        Email_ID = Email_ID + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        Password = Password + s[i];
    }


    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        pub_key = pub_key + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        priv_key = priv_key + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        ed_factor = ed_factor + s[i];
    }
    for(int i =index;i<s.length();i++){
        if(s[i] == '~'){
            index = i+1;
            break;
        }
        user_bal = user_bal + s[i];
    }

    stringstream ss(user_id);
    ss >> User_ID;

    stringstream ss1(pub_key);
    ss1 >> Public_Key;

    stringstream ss2(priv_key);
    ss2 >> Private_Key;

    stringstream ss3(ed_factor);
    ss3 >> EDFactor;

    stringstream ss4(user_bal);
    ss4 >> User_Balance;

    u.set_User_ID(User_ID);
    u.set_user_details(Name, Phone_No, Email_ID, Password);
    u.set_user_public_key(Public_Key);
    u.set_user_private_key(Private_Key);
    u.set_user_EDFactor(EDFactor);
    u.set_User_Balance(User_Balance);

}


//----------------------------- USERS --------------------------------------------------

void write_UserList_size(){
    ofstream fout;
	fout.open("UserList_size.txt");
    
    fout << UserList_size;
    
	fout.close();
	//cout<<"written size"<<endl;

}
void read_UserList_size(){
    ifstream fin;

	fin.open("UserList_size.txt");
	
	fin >> UserList_size;
	  
	fin.close();
    //cout<<"reading size"<<endl;
    //cout<<UserList_size<<endl;

}
void write_UserList(){
    string *s = new string[UserList_size];

    for(int i =0;i<UserList_size;i++){
        s[i] = create_User_string(UserList[i]);
    }

    ofstream fout;
	fout.open("UserList.txt");

	for(int i =0;i<UserList_size;i++)
		fout << s[i] << endl;

	fout.close();

}
void read_UserList(){

    string *s = new string[UserList_size];
 	ifstream fin;

	fin.open("UserList.txt");
	
	for(int i =0;i<UserList_size;i++)
	    getline(fin, s[i]);
	  
	fin.close();

    for(int i=0;i<UserList_size;i++){
        extract_User(s[i], UserList[i]);
    }


}
