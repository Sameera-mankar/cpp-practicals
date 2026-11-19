#include <iostream>
#include <exception>
using namespace std;

class InvalidAmount : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid amount! Amount must be greater than zero.";
    }
};

class InsufficientFunds : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Insufficient funds! Balance is too low.";
    }
};

class BankAccount
{
    double balance;

public:
    BankAccount(double balance)
    {
        this->balance = balance;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            throw InvalidAmount();
        }
        else if (amount > balance)
        {
            throw InsufficientFunds();
        }
        else
        {
            balance -= amount;
            cout << "Amount successfully withdrawn: " << amount << "\n";
        }
    }

    void showBalance()
    {
        cout << "Balance: " << balance << "\n";
    }
};

int main()
{
    cout << "Student name: SAMEERA MANKAR\n";
    cout << "URN: E25B000297\n\n";

    BankAccount account(1500);

    cout << "Initial ";
    account.showBalance();

    try
    {
        account.withdraw(300);
    }
    catch (const InvalidAmount &e)
    {
        cout << e.what() << "\n";
    }
    catch (const InsufficientFunds &e)
    {
        cout << e.what() << "\n";
    }

    account.showBalance();

    try
    {
        account.withdraw(1800);
    }
    catch (const InvalidAmount &e)
    {
        cout << e.what() << "\n";
    }
    catch (const InsufficientFunds &e)
    {
        cout << e.what() << "\n";
    }

    account.showBalance();

    try
    {
        account.withdraw(-100);
    }
    catch (const InvalidAmount &e)
    {
        cout << e.what() << "\n";
    }
    catch (const InsufficientFunds &e)
    {
        cout << e.what() << "\n";
    }

    account.showBalance();

    return 0;
}

