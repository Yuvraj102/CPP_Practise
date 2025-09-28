#include "Yuvraj_Sept25_task1_SavingsAccount.h"

// initialize static member
double SavingsAccount::annualInterestRate = 0.0;

// constructor
SavingsAccount::SavingsAccount(double initialBalance) {
    savingsBalance = (initialBalance >= 0.0) ? initialBalance : 0.0;
}

// calculate and add monthly interest
void SavingsAccount::calculateMonthlyInterest() {
    double monthlyInterest = (savingsBalance * annualInterestRate) / 12.0;
    savingsBalance += monthlyInterest;
}

// return current balance
double SavingsAccount::getBalance() const {
    return savingsBalance;
}

// static function to set annual interest rate
void SavingsAccount::modifyInterestRate(double newRate) {
    annualInterestRate = newRate;
}
