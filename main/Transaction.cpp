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
#include<string>
#include <sstream>


#include "main.h"
#include "Menu.h"
#include "Person.h"
#include "Transaction.h"
#include "Post.h"
#include "Block.h"

using namespace std;

Transaction Ledger[N];
Transaction Mempool[N];

long Ledger_size = 0;
long Mempool_size = 0;
long Transaction_Ids = 0;

// Future goals:
// -----Try to design this stack template of our own Transaction class,
// -----to directly store the objects of transaction happened till time.
// -----then to get the id of a transaction we would do --> List_of_Transactions.top().get_Transaction_ID();

    void Transaction::set_Transaction(string sender, string reciever, long long amount, long Transaction_ID)
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
    void Transaction::set_Transaction_ID(long id){
        Transaction_ID = id;
    }
    
    long Transaction::get_Transaction_ID()
    {
        return Transaction_ID;
    }

    string Transaction::get_sender(){
        return sender;
    }
    string Transaction::get_reciever(){
        return reciever;
    }
    long long Transaction::get_amount(){
        return amount;
    }

    string Transaction::get_transaction_msg()
    {
        return transaction_msg;
    }

void send_transaction_from_client_to_server(Transaction t, long user_priv_key ,long admin_pub_key )
{
    // entire socket programming will be done in this function
    // first extract t.get_transaction_msg()
    string final_buffer = prepare_transmission_buffer(t, user_priv_key, admin_pub_key);
    
    // send this final buffer via socket of client 
    //for now just for implementation process passing this string 
    //via calling the function recieve_transaction_from_client() directly
    recieve_transaction_from_client(final_buffer, t);    //ideally only buffer will be sent
}

string prepare_transmission_buffer(Transaction &t, long user_priv_key ,long admin_pub_key)
{
    // first extract t.get_transaction_msg()
    // hash this message --> h1
    // write the file1 with hash of transaction msg
    // digital sign here : 
    // cypher1 = encode(user.get_User_Private_Key(), user.get_User_EDFactor());
    // write this encoded msg ( cypher1 )again in another file2
    // encrypt this with admin public key:  
    // cypher2 = encode(Admin.get_User_Public_Key(), Admin.get_User_EDFactor())
    // final string = append this cypher2 with t.get_transaction_msg()
    // return final string
    return "";
}

// ideally only bufer will be recieved
void recieve_transaction_from_client(string recived_buffer, Transaction &t)
{ 
    //call verify function here 
    //ideally verify_transaction(recived_buffer) will return a message, if msg is NULL then the Transaction is fake.
    // if message != NULL then we create an object of transaction class 
    // t.set_transaction_msg(message);
    // t.set_Transaction_ID();
    // Mempool++;
    // then add this transaction object into Mempool[ Mempool_size -1 ]
    
    if(verify_transaction(recived_buffer))
    { 
        Mempool_size++;
        Mempool[Mempool_size -1] = t;
        
        cout << "\n !!Verfication Successsfull, Transaction Added to Mempool!! ";
    }
    else
    {
        cout << "\n !!Transaction Discarded, Verfication Failed!! ";
    }
    
}

bool verify_transaction(string buffer)
{
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

void donate_money_UI(long Post_ID) 	
{
    string sender, reciever;
    long amount;
    
    sender = UserList[Logged_User_ID - 1].get_User_Name();
    reciever = PostList[Post_ID - 1].get_org_name();

    cout << "\n\n Your Current Balance : " << UserList[Logged_User_ID - 1].get_User_Balance();
	
	if (UserList[Logged_User_ID - 1].get_User_Balance() <= 0)
	{
		cout << "\n Sorry you cannot donate as your balance is " << UserList[Logged_User_ID - 1].get_User_Balance();
		return ;
	}
	
    while(1)
    {
        cout << "\n Enter the amount : "; cin >> amount;
        
        if(amount <= 0 || amount > PostList[Post_ID - 1].get_amount_left() )
        {
            cout << "\n !!Invalid Amount!! \n Entered Amount is either less than 1 or more than the amount required ";
        }
        else if(amount > UserList[Logged_User_ID - 1].get_User_Balance())
        {
            cout << "\n Entered Amount is more than yours current balance ";
        }
        else
        {
            break;
        }
    }
    
    //Mempool[Mempool_size -1] = NewTransaction(sender, reciever, amount);
    PostList[Post_ID - 1].deduct_money(amount);

    UserList[Logged_User_ID - 1].deduct_User_Balance(amount);

    // now this function will just go to the server
    send_transaction_from_client_to_server(NewTransaction(sender, reciever, amount), 
                                           UserList[Logged_User_ID -1].get_User_Private_Key(), 
                                           Admin.get_User_Public_Key()); 
}
