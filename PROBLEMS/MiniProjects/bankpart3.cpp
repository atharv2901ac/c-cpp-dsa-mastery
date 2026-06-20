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
    // Getters and Setters
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

    Customer* customer = NULL;
    int choice;

    do {
        cout << endl;
        cout << "===== BANK MENU =====" << endl;
        cout << "1. Create Customer" << endl;
        cout << "2. Create Account" << endl;
        cout << "3. View Account" << endl;
        cout << "4. Deposit Money" << endl;
        cout << "5. Withdraw Money" << endl;
        cout << "6. Show Transactions" << endl;
        cout << "7. View Customer Details" << endl;
        cout << "8. Update Customer Details" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            customer = new Customer();

            int id;
            string name, contact, email;

            cout << "Enter customer id: ";
            cin >> id;

            cout << "Enter name: ";
            cin >> name;

            cout << "Enter contact: ";
            cin >> contact;

            cout << "Enter email: ";
            cin >> email;

            customer->SetId(id);
            customer->SetName(name);
            customer->SetContact(contact);
            customer->SetEmail(email);

            bank->AddCustomer(customer);

            cout << "Customer created successfully" << endl;
        }

        else if (choice == 2) {
            if (customer == NULL) {
                cout << "Create customer first" << endl;
            } else {
                int accNo;

                cout << "Enter account number: ";
                cin >> accNo;

                bank->CreateAccount(customer, accNo);
            }
        }

        else if (choice == 3) {
            if (customer == NULL) {
                cout << "Create customer first" << endl;
            } else {
                customer->ViewAccount();
            }
        }

        else if (choice == 4) {
            if (customer == NULL) {
                cout << "Create customer first" << endl;
            } else {
                double amount;

                cout << "Enter amount: ";
                cin >> amount;

                customer->DepositMoney(amount);
            }
        }

        else if (choice == 5) {
            if (customer == NULL) {
                cout << "Create customer first" << endl;
            } else {
                double amount;

                cout << "Enter amount: ";
                cin >> amount;

                customer->WithdrawMoney(amount);
            }
        }

        else if (choice == 6) {
            if (customer == NULL || customer->GetAccount() == NULL) {
                cout << "No account found" << endl;
            } else {
                customer->GetAccount()->ShowTransactions();
            }
        }

        else if (choice == 7) {
            if (customer == NULL) {
                cout << "Create customer first" << endl;
            } else {
                cout << "Customer Id: " << customer->GetId() << endl;
                cout << "Name: " << customer->GetName() << endl;
                cout << "Contact: " << customer->GetContact() << endl;
                cout << "Email: " << customer->GetEmail() << endl;
            }
        }

        else if (choice == 8) {
            if (customer == NULL) {
                cout << "Create customer first" << endl;
            } else {
                int updateChoice;

                cout << "1. Update Name" << endl;
                cout << "2. Update Contact" << endl;
                cout << "3. Update Email" << endl;
                cout << "Enter choice: ";
                cin >> updateChoice;

                if (updateChoice == 1) {
                    string name;
                    cout << "Enter new name: ";
                    cin >> name;
                    customer->SetName(name);
                }

                else if (updateChoice == 2) {
                    string contact;
                    cout << "Enter new contact: ";
                    cin >> contact;
                    customer->SetContact(contact);
                }

                else if (updateChoice == 3) {
                    string email;
                    cout << "Enter new email: ";
                    cin >> email;
                    customer->SetEmail(email);
                }

                cout << "Customer details updated" << endl;
            }
        }

        else if (choice == 9) {
            cout << "Thank you" << endl;
        }

        else {
            cout << "Invalid choice" << endl;
        }

    } while (choice != 9);

    return 0;
}