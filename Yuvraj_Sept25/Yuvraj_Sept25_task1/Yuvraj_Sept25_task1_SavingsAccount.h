#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount {
public:
    SavingsAccount(double initialBalance = 0.0);

    void calculateMonthlyInterest();
    double getBalance() const;

    static void modifyInterestRate(double newRate);

private:
    double savingsBalance;
    static double annualInterestRate;
};

#endif
