#include<iostream>
#include<vector>
using namespace std;

class Address{
    string landmark;
    string city;
    string state;
    string country;
    string pincode;
};

class User{
    protected:
        int id;
        string name;
        string contact;
        string email;
        Address address;
};

class Transaction{
    enum type { DEPOSIT , WITHDRAWAL};
    double amount;
};

class Account{
        int accNo;
        double balance;
        vector<Transaction> transactions;
        Customer* customer;

    public:
        // deposit
        // withdraw
        // check balance
};

class Bank{
    private:
        int Id;
        string name;
        string contact;
        string email;
        Address address;
        vector<Account> accounts;

    public:
        // getAccountList
        // getAccountByccountNo
        // Create Account
        // Close Account
        // get Customer list
        // Getters and Setters:
        int GetId(){
            return Id;
        }
        int SetId(int Id){
            this->Id = Id;
        }
        string GetName(){
            return name;
        }
        string SetName(string name){
            this->name = name;
        }
        string GetContact(){
            return contact;
        }
        string SetContact(string contact){
            this->contact = contact;
        }
        string GetEmail(){
            return name;
        }
        string SetEmail(string email){
            this->email = email;
        }

};

class Customer: public User{
    Account* account = NULL;
    public:
        // view account
        // initiate transactions
        // Getters and Setters
        int GetId(){
            return id;
        } 
        int SetId(int id){
            this->id = id;
        }
        string GetName(){
            return name;
        }
        string SetName(string name){
            this->name = name;
        }
        string GetContact(){
            return contact;
        }
        string SetContact(string contact){
            this->contact = contact;
        }
        string GetEmail(){
            return name;
        }
        string SetEmail(string email){
            this->email = email;
        }

};

class Employee: public User{
    Bank* bank= NULL;
    public:
        //Getters and Setters 
        int GetId(){
            return id;
        } 
        int SetId(int id){
            this->id = id;
        }
        string GetName(){
            return name;
        }
        string SetName(string name){
            this->name = name;
        }
        string GetContact(){
            return contact;
        }
        string SetContact(string contact){
            this->contact = contact;
        }
        string GetEmail(){
            return name;
        }
        string SetEmail(string email){
            this->email = email;
        }
};


int main(int argc, char const *argv[])
{
    Bank* b = new Bank();
    b->SetName("HDFC");
    cout << b->GetEmail() << endl;
    return 0;
}