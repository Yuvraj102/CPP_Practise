/*

(Account Class) Create an Account class that a bank might use to represent customers’ bank accounts. Include a data member of type int to represent the account balance. [Note: In subsequent chapters, we’ll use numbers that contain decimal points (e.g., 2.75)—called floating-point values— to represent dollar amounts.] Provide a constructor that receives an initial balance and uses it to ini- tialize the data member. The constructor should validate the initial balance to ensure that it’s greater than or equal to 0. If not, set the balance to 0 and display an error message indicating that the initial balance was invalid. Provide three member functions. Member function credit should add an amount to the current balance. Member function debit should withdraw money from the Account and ensure that the debit amount does not exceed the Account’s balance. If it does, the balance should be left unchanged and the function should print a message indicating "Debit amount exceed- ed account balance." Member function getBalance should return the current balance. Create a program that creates two Account objects and tests the member functions of class Account.
*/

#include <iostream>
using namespace std;

class Account {
private:
    int balance;

public:
    // constructor with validation
    Account(int initialBalance) {
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
            cout << "Error: Initial balance was invalid. Balance set to 0." << endl;
        }
    }

    // add money
    void credit(int amount) {
        balance += amount;
    }

    // withdraw money with check
    void debit(int amount) {
        if (amount > balance) {
            cout << "Debit amount exceeded account balance." << endl;
        } else {
            balance -= amount;
        }
    }

    // return balance
    int getBalance() const {
        return balance;
    }
};

int main() {
    Account account1(50);    // valid balance
    Account account2(-7);    // invalid balance

    cout << "account1 balance: " << account1.getBalance() << endl;
    cout << "account2 balance: " << account2.getBalance() << endl;

    cout << "\nAdding 40 to account1." << endl;
    account1.credit(40);
    cout << "account1 balance: " << account1.getBalance() << endl;

    cout << "\nTrying to withdraw 100 from account1." << endl;
    account1.debit(100);
    cout << "account1 balance: " << account1.getBalance() << endl;

    cout << "\nWithdrawing 30 from account1." << endl;
    account1.debit(30);
    cout << "account1 balance: " << account1.getBalance() << endl;

    return 0;
}
