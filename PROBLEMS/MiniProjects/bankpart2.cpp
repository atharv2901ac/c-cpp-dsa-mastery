#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Address {
    string landmark;
    string city;
    string state;
    string country;
    string pincode;
};

class Account;
class Customer;
class Bank;

class User {
protected:
    int id;
    string name;
    string contact;
    string email;
    Address address;

public:
    int GetId() {
        return id;
    }

    void SetId(int id) {
        this->id = id;
    }

    string GetName() {
        return name;
    }

    void SetName(string name) {
        this->name = name;
    }

    string GetContact() {
        return contact;
    }

    void SetContact(string contact) {
        this->contact = contact;
    }

    string GetEmail() {
        return email;
    }

    void SetEmail(string email) {
        this->email = email;
    }
};

class Transaction {
    string type;
    double amount;

public:
    void SetType(string type) {
        this->type = type;
    }

    string GetType() {
        return type;
    }

    void SetAmount(double amount) {
        this->amount = amount;
    }

    double GetAmount() {
        return amount;
    }
};

class Account {
    int accNo;
    double balance;
    vector<Transaction> transactions;
    Customer* customer;

public:
    Account() {
        balance = 0;
        customer = NULL;
    }

    void SetAccNo(int accNo) {
        this->accNo = accNo;
    }

    int GetAccNo() {
        return accNo;
    }

    void SetCustomer(Customer* customer) {
        this->customer = customer;
    }

    Customer* GetCustomer() {
        return customer;
    }

    double GetBalance() {
        return balance;
    }

    void Deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount" << endl;
            return;
        }

        balance = balance + amount;

        Transaction t;
        t.SetType("DEPOSIT");
        t.SetAmount(amount);

        transactions.push_back(t);

        cout << "Amount deposited successfully" << endl;
    }

    void Withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount" << endl;
            return;
        }

        if (amount > balance) {
            cout << "Insufficient balance" << endl;
            return;
        }

        balance = balance - amount;

        Transaction t;
        t.SetType("WITHDRAWAL");
        t.SetAmount(amount);

        transactions.push_back(t);

        cout << "Amount withdrawn successfully" << endl;
    }

    void CheckBalance() {
        cout << "Current Balance: " << balance << endl;
    }

    void ShowTransactions() {
        cout << "Transactions:" << endl;

        for (int i = 0; i < transactions.size(); i++) {
            cout << transactions[i].GetType()
                 << " : "
                 << transactions[i].GetAmount()
                 << endl;
        }
    }
};

class Customer : public User {
    Account* account;

public:
    Customer() {
        account = NULL;
    }

    void SetAccount(Account* account) {
        this->account = account;
    }

    Account* GetAccount() {
        return account;
    }

    void ViewAccount() {
        if (account == NULL) {
            cout << "No account found" << endl;
            return;
        }

        cout << "Account Number: " << account->GetAccNo() << endl;
        cout << "Balance: " << account->GetBalance() << endl;
    }

    void DepositMoney(double amount) {
        if (account == NULL) {
            cout << "No account found" << endl;
            return;
        }

        account->Deposit(amount);
    }

    void WithdrawMoney(double amount) {
        if (account == NULL) {
            cout << "No account found" << endl;
            return;
        }

        account->Withdraw(amount);
    }
};

class Employee : public User {
    Bank* bank;

public:
    Employee() {
        bank = NULL;
    }

    void SetBank(Bank* bank) {
        this->bank = bank;
    }

    Bank* GetBank() {
        return bank;
    }
};

class Bank {
private:
    int id;
    string name;
    string contact;
    string email;
    Address address;
    vector<Account*> accounts;
    vector<Customer*> customers;

public:
    int GetId() {
        return id;
    }

    void SetId(int id) {
        this->id = id;
    }

    string GetName() {
        return name;
    }

    void SetName(string name) {
        this->name = name;
    }

    string GetContact() {
        return contact;
    }

    void SetContact(string contact) {
        this->contact = contact;
    }

    string GetEmail() {
        return email;
    }

    void SetEmail(string email) {
        this->email = email;
    }

    void AddCustomer(Customer* customer) {
        customers.push_back(customer);
    }

    void CreateAccount(Customer* customer, int accNo) {
        Account* account = new Account();

        account->SetAccNo(accNo);
        account->SetCustomer(customer);

        customer->SetAccount(account);

        accounts.push_back(account);

        cout << "Account created successfully" << endl;
    }

    Account* GetAccountByAccountNo(int accNo) {
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i]->GetAccNo() == accNo) {
                return accounts[i];
            }
        }

        return NULL;
    }

    void GetAccountList() {
        cout << "Account List:" << endl;

        for (int i = 0; i < accounts.size(); i++) {
            cout << accounts[i]->GetAccNo() << endl;
        }
    }

    void GetCustomerList() {
        cout << "Customer List:" << endl;

        for (int i = 0; i < customers.size(); i++) {
            cout << customers[i]->GetName() << endl;
        }
    }
};

int main() {
    Bank* bank = new Bank();

    bank->SetId(1);
    bank->SetName("HDFC");
    bank->SetContact("9999999999");
    bank->SetEmail("support@hdfc.com");

    Customer* customer = new Customer();

    customer->SetId(101);
    customer->SetName("Rahul");
    customer->SetContact("9876543210");
    customer->SetEmail("rahul@gmail.com");

    bank->AddCustomer(customer);

    bank->CreateAccount(customer, 1001);

    customer->ViewAccount();

    customer->DepositMoney(5000);
    customer->WithdrawMoney(1500);

    customer->ViewAccount();

    Account* account = customer->GetAccount();
    account->ShowTransactions();

    return 0;
}