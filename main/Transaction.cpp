/*
 *  Transaction.cpp
 *
 *  Created on: 29-Sep-2021
 *     Authors: M Somasekhar, Aryan Mukerji
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
#define N 100


Transaction Ledger[N];
Transaction Mempool[N];

long Ledger_size =0;
long Mempool_size =0;
long Transaction_Ids =0;


//using a stack to store number of trans happend till now
//currently just storing the trans as int type denoting no.of.trans happended till a point = size of stack;
//currently this can also be substituted by a simple int varialble total_trans and we keep doing +1 every time new transaction happens.
//stack<int> List_of_Transaction_ID;

// Future goals:
// -----Try to design this stack template of our own Transaction class,
// -----to directly store the objects of transaction happened till time.
// -----then to get the id of a transaction we would do --> List_of_Transactions.top().get_Transaction_ID();

    void Transaction::set_Transaction(string sender, string reciever, long amount, long Transaction_ID)
    {
        this->Transaction_ID = Transaction_ID;
        this->sender  = sender;
        this->reciever = reciever;
        this->amount = amount;

        transaction_msg = sender + " sent " + reciever + " amount " + to_string(amount) + " Rs.";
    }
    
    void Transaction::set_transaction_msg(string message)
    {
        transaction_msg = message;
    }

    void Transaction::set_Transaction_ID()
    {
        Transaction_ID = Transaction_Ids + 1;
    }
    
    long Transaction::get_Transaction_ID()
    {
        return Transaction_ID;
    }

    string Transaction::get_transaction_msg()
    {
        return transaction_msg;
    }

// having an array to save the trantransaction till time. (Max transactions hardcoded as N = 100 in the macro)
// this array will be using 1 based indexing
//Transaction Transaction_Array[N];



void send_transaction_from_client_to_server(Transaction t, long user_priv_key ,long admin_pub_key ){
    
    // entire socket programming will be done in this function
    // first extract t.get_transaction_msg()
    string final_buffer = prepare_transmission_buffer(t ,user_priv_key, admin_pub_key);
    
    // send this final buffer via socket of client 
    //for now just for implementation process passing this string 
    //via calling the function recieve_transaction_from_client() directly
    recieve_transaction_from_client(final_buffer,t);    //ideally only buffer will be sent
}

string prepare_transmission_buffer(Transaction &t, long user_priv_key ,long admin_pub_key){
    
    //first extract t.get_transaction_msg()
    // hash this message
    // digital sign here
    // encrypt this with admin public key
    // append this double cypher with t.get_transaction_msg()
    // return final string
    return "";
}

void recieve_transaction_from_client(string recived_buffer, Transaction &t){ // ideally only bufer will be recieved
    
    //call verify function here 
    //ideally verify_transaction(recived_buffer) will return a message, if msg is NULL then the Transaction is fake.
    // if message != NULL then we create an object of transaction class 
    // t.set_transaction_msg(message);
    // t.set_Transaction_ID();
    // Mempool++;
    // then add this transaction object into Mempool[ Mempool_size -1 ]
    if(verify_transaction(recived_buffer)){ 
        Mempool_size++;
        Mempool[Mempool_size -1] = t;
        cout<<"Verfication Successsfull. Transaction Added to Mempool. "<<endl;
    }
    else{
        cout<<"Transaction Discarded. Verfication Failed"<<endl;
    }
    
}


bool verify_transaction(string buffer){
    // first divide the buffer into cypher and message
    // decrypt the cypher with admin private key
    // decrypt using users public key
    // this decryption will give a hash, store it
    
    // if(hash_func(message) == hash ){
    //     return true;
    // }
    // else{
    //     return false;
    // }
    return true; //just returning true for now
}

// to create new transaction and return the object with given details
Transaction NewTransaction(string sender, string reciever, long amount)
{
    Transaction t;
    //t.set_Transaction(sender, reciever, amount, List_of_Transaction_ID.size() + 1);
    
    t.set_Transaction(sender, reciever, amount, ++Transaction_Ids ); //  remember to update the Mempool_size after this Transaction is verified.

    //List_of_Transaction_ID.push(List_of_Transaction_ID.size() + 1)
    
    

    return t;
}

// currently demostrated in the main()
void donate_money_UI(long Post_ID)    //this will have more parameter as username, recivername
{
    string sender, reciever;
    long amount;
    
    sender = UserList[Logged_User_ID - 1].get_User_Name();
    reciever = PostList[Post_ID - 1].get_org_name();

    cout<<"\nYour Current Balance: "<<UserList[Logged_User_ID - 1].get_User_Balance()<<endl;
    while(1){
        cout << "Enter the amount : "; cin >> amount;
    
        if(amount > 0 && amount > PostList[Post_ID - 1].get_amount_left() ){
            cout<<"Invalid Amount. \nEntered Amount is either less than 1 rs or more than left amount"<<endl;
            cout<<endl;
        }
        else if(amount > UserList[Logged_User_ID - 1].get_User_Balance()){
            cout<<"Entered Amount is more than current balance."<<endl;
            cout<<endl;
        }
        else
            break;
    }
    
    
    //Mempool[Mempool_size -1] = NewTransaction( sender,  reciever,  amount );
    PostList[Post_ID - 1].deduct_money(amount);

    UserList[Logged_User_ID - 1].deduct_User_Balance(amount);

    // now this function will just go to the server
    send_transaction_from_client_to_server(NewTransaction( sender,  reciever,  amount ), 
                                            UserList[Logged_User_ID -1].get_User_Private_Key(), 
                                            Admin.get_User_Public_Key());
    
    



    
}

void write_Mempool_size(){

    fstream fp;
    
    fp.open("Mempool_size.txt", ios::out );
    
    if (!fp) 
    {
        cout << "\n\n !! Unable to open file !! ";
        exit(1); // terminate with error
    }
    
    // writing to file 
    fp << Mempool_size;
    
    fp.close();

    // Mempool_size >> fp
}

void read_Mempool_size(){
    fstream fp;
    long temp;
    
    fp.open("Mempool_size.txt", ios::in);
    
    if (!fp) 
    {
        cout << "\n\n !! Unable to open file !! ";
        exit(1); // terminate with error
    }
    
    // reading from temp
    fp >> temp;
    
    fp.close();

    Mempool_size = temp;
}

void write_Mempool(){

    cout<<"Write 1"<<endl;
    Transaction *temp = new Transaction[Mempool_size];
    for(int i =0 ;i<Mempool_size;i++){
        temp[i] = Mempool[i];
    }
    cout<<"Write 2"<<endl;
    ofstream fstream_ob;

    fstream_ob.open("Mempool.bat", ios::out );

    cout<<"Write 3"<<endl;

    fstream_ob.write( (char *) &temp, sizeof(temp));

    cout<<"Congrats! Your array of objects is successfully written to the file \n";

    fstream_ob.close();

    cout<<"Write 4"<<endl;
}

void read_Mempool(){

    if(Mempool_size == 0){
        return ;
    }
    cout<<Mempool_size<<endl;
    Transaction *temp = new Transaction[Mempool_size];
    // for(int i =0 ;i<Mempool_size;i++){
    //     temp[i] = Mempool[i];
    // }

    cout<<"Read 1"<<endl;

    for(int i = 0;i<Mempool_size;i++)
    {
        cout<<"hi"<<endl;
        cout<<"\t"<<temp[i].get_Transaction_ID()<<" : "<<temp[i].get_transaction_msg();
        cout<<"Bye"<<endl;
        cout<<endl;
    }
    
    //Creating an intput stream
    ifstream ifstream_ob;

    //Calling the open function to read and write an object to/from a file
    ifstream_ob.open("Mempool.bat", ios::in);
    if(ifstream_ob.is_open()){
        cout<<"File is Open to Read"<<endl;
    }
    cout<<"\nReading an array of objects from a file : \n";
    
    //Calling the read() function to read an array of objects from a file and transfer its content to an empty object
    ifstream_ob.read( (char *) &temp, sizeof(temp));

    cout<<"Read 2"<<endl;

    //Closing the input stream
    ifstream_ob.close();

    cout<<"Read 3"<<endl;

    cout<<"Mempool: --------->"<<endl;
    cout<<Mempool_size<<endl;
    for(int i = 0;i<Mempool_size;i++)
    {
        cout<<"hi"<<endl;
        cout<<"\t"<<temp[i].get_Transaction_ID()<<" : "<<temp[i].get_transaction_msg();
        cout<<"Bye"<<endl;
        cout<<endl;
    }
    cout<<"Read 4"<<endl;
}

void write_Ledger_size(){
    // Ledger_size >> fp
}

void read_Ledger_size(){
    int temp;
    Ledger_size = temp;
}


void write_Ledger(){

    cout<<"Write 1"<<endl;
    Transaction *temp = new Transaction[Ledger_size];
    for(int i =0 ;i<Ledger_size;i++){
        temp[i] = Ledger[i];
    }
    cout<<"Write 2"<<endl;
    ofstream fstream_ob;

    fstream_ob.open("Ledger.txt", ios::out);

    cout<<"Write 3"<<endl;

    fstream_ob.write( (char *) &temp, sizeof(temp));

    cout<<"Congrats! Your array of objects is successfully written to the file \n";

    fstream_ob.close();

    cout<<"Write 4"<<endl;
}


void read_Ledger(){
    Transaction *temp = new Transaction[Ledger_size];
    // for(int i =0 ;i<Mempool_size;i++){
    //     temp[i] = Mempool[i];
    // }

    cout<<"Read 1"<<endl;
    //Creating an intput stream
    ifstream ifstream_ob;

    //Calling the open function to read and write an object to/from a file
    ifstream_ob.open("Ledger.txt", ios::in | ios::binary);

    cout<<"\nReading an array of objects from a file : \n";

    //Calling the read() function to read an array of objects from a file and transfer its content to an empty object
    ifstream_ob.read( (char *) &temp, sizeof(temp));

    cout<<"Read 2"<<endl;

    //Closing the input stream
    ifstream_ob.close();

    cout<<"Read 3"<<endl;

    cout<<"Ledger: --------->"<<endl;

    for(int i = 0;i<Ledger_size;i++)
    {
        cout<<"\t"<<temp[i].get_Transaction_ID()<<" : "<<temp[i].get_transaction_msg();
        cout<<endl;
    }
    cout<<"Read 4"<<endl;
}

void write_BLockChain_size(){
    // BlockChain_size >> fp
}

void read_BlockChain_size(){
    int temp;
    BlockChain_size = temp;
}


void write_BlockChain(){

    cout<<"Write 1"<<endl;
    cout<<"gew"<<endl;
    Block *temp = new Block[BlockChain_size];
    cout<<"0"<<endl;

    cout<<BlockChain_size<<endl;

    for(int i =0 ;i<BlockChain_size;i++){
        cout<<"1"<<endl;
        temp[i] = BlockChain[i];
    }
    cout<<"Write 2"<<endl;
    ofstream fstream_ob;

    fstream_ob.open("BlockChain.txt", ios::out);

    cout<<"Write 3"<<endl;

    fstream_ob.write( (char *) &temp, sizeof(temp));

    cout<<"Congrats! Your array of objects is successfully written to the file \n";

    fstream_ob.close();

    cout<<"Write 4"<<endl;
}


void read_BlockChain(){
    Block *temp = new Block[BlockChain_size];
    // for(int i =0 ;i<Mempool_size;i++){
    //     temp[i] = Mempool[i];
    // }

    cout<<"Read 1"<<endl;
    //Creating an intput stream
    ifstream ifstream_ob;

    //Calling the open function to read and write an object to/from a file
    ifstream_ob.open("BlockChain.txt", ios::in | ios::binary);

    cout<<"\nReading an array of objects from a file : \n";

    //Calling the read() function to read an array of objects from a file and transfer its content to an empty object
    ifstream_ob.read( (char *) &temp, sizeof(temp));

    cout<<"Read 2"<<endl;

    //Closing the input stream
    ifstream_ob.close();

    cout<<"Read 3"<<endl;

    cout<<"BlockChain: --------->"<<endl;

    // for(int i = 1;i<BlockChain_size;i++)
    // {
    //     cout<<"\t"<<temp[i].get_BlockNumber()<<" : "<<temp[i].get_No_of_Transactions_in_Block()<<" b "<<temp[i].get_Block_Hash();
    //     cout<<endl;
    // }

    for(int i = 0; i < BlockChain_size; i++){
    
            cout<<" ---------------------"<<endl;
            cout<<"Block ID: " << temp[i].get_BlockNumber()<<endl;
            cout<<"Previous Block hash: "<<temp[i].get_Previous_Hash()<<endl;
            cout<<"Current Block hash: "<<temp[i].get_Block_Hash()<<endl;
            cout<<"Transactions inside the Block: "<<endl;
            cout<<"{"<<endl;
    
            for(int j =0;j<temp[i].get_No_of_Transactions_in_Block();j++){
                cout<<"\t Transaction No: "<<j+1<<endl;
                cout<<"\t Transaction ID: "<<temp[i].get_transaction_ID_from_block(j)<<endl;
                cout<<"\t Transaction Message: "<<temp[i].get_transaction_msg_from_block(j)<<endl;
                cout<<endl;
            }
            cout<<"}"<<endl;
            cout<<endl;
    }


    cout<<"Read 4"<<endl;
}



