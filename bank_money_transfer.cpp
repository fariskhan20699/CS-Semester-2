#include <iostream>
using namespace std;

// Base class
class Account {
protected:
    string name;
    double balance;

public:
    Account(string n, double b) {
        name = n;
        balance = b;
    }

    void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient balance\n";
        }
    }

    virtual void showInfo() {
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Derived class
class SavingsAccount : public Account {
public:
    SavingsAccount(string n, double b) : Account(n, b) {}

    void withdraw(double amount) override {
        cout << "Savings account withdrawal\n";
        Account::withdraw(amount);
    }

    void showInfo() override {
        cout << "Savings Account\n";
        Account::showInfo();
    }
};

// Derived class
class CurrentAccount : public Account {
public:
    CurrentAccount(string n, double b) : Account(n, b) {}

    void withdraw(double amount) override {
        cout << "Current account withdrawal\n";
        Account::withdraw(amount);
    }

    void showInfo() override {
        cout << "Current Account\n";
        Account::showInfo();
    }
};

int main() {
    Account* a1 = new SavingsAccount("Ali", 5000);
    Account* a2 = new CurrentAccount("Sara", 8000);

    a1->deposit(1000);
    a1->withdraw(2000);
    a1->showInfo();

    cout << "-----------------\n";

    a2->withdraw(3000);
    a2->showInfo();

    delete a1;
    delete a2;

    return 0;
}
