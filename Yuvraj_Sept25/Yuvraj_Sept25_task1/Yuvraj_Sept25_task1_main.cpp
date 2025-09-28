/*
(SavingsAccount Class) Create a SavingsAccount class. Use a static data member annual- InterestRate to store the annual interest rate for each of the savers. Each member of the class con- tains a private data member savingsBalance indicating the amount the saver currently has on deposit. Provide member function calculateMonthlyInterest that calculates the monthly interest by multiplying the balance by annualInterestRate divided by 12; this interest should be added to savingsBalance. Provide a static member function modifyInterestRate that sets the static an- nualInterestRate to a new value. Write a driver program to test class SavingsAccount. Instantiate two different objects of class SavingsAccount, saver1 and saver2, with balances of $2000.00 and $3000.00, respectively. Set the annualInterestRate to 3 percent. Then calculate the monthly in- terest and print the new balances for each of the savers. Then set the annualInterestRate to 4 per- cent, calculate the next month’s interest and print the new balances for each of the savers.
*/

#include <iostream>
#include <iomanip>
#include "Yuvraj_Sept25_task1_SavingsAccount.h"

int main() {
    // two accounts
    SavingsAccount saver1(2000.0);
    SavingsAccount saver2(3000.0);

    // set interest rate to 3%
    SavingsAccount::modifyInterestRate(0.03);

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Balances after 1 month at 3% annual interest:\n";
    std::cout << "Saver1: $" << saver1.getBalance() << "\n";
    std::cout << "Saver2: $" << saver2.getBalance() << "\n";

    // set interest rate to 4%
    SavingsAccount::modifyInterestRate(0.04);

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    std::cout << "\nBalances after next month at 4% annual interest:\n";
    std::cout << "Saver1: $" << saver1.getBalance() << "\n";
    std::cout << "Saver2: $" << saver2.getBalance() << "\n";

    return 0;
}

//g++ *.cpp -o savings_program