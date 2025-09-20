#pragma once
#include <iostream>
#include <string>
#include "utils.h"

class Account {
protected:
    std::string account_holder_name;
    long long account_number;
    double balance;
    std::string account_opening_date;
    int pin;

public:
    Account() : account_holder_name(""), account_number(0), balance(0),
                account_opening_date(""), pin(0) {}

    void open_account() {
        std::cin.ignore();
        std::cout << "Enter your Name: ";
        getline(std::cin, account_holder_name);

        while (true) {
            std::cout << "Enter Initial Deposit Amount: ";
            if (!(std::cin >> balance)) {
                std::cout << "Invalid input. Try again.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else break;
        }

        account_number = Utils::get_number();
        pin = (rand() % 9000) + 1000;
        account_opening_date = Utils::get_date();

        std::cout << "\nAccount Created Successfully!\n";
        std::cout << "Name: " << account_holder_name << "\n";
        std::cout << "Account Number: " << account_number << "\n";
        std::cout << "Balance: " << balance << "\n";
        std::cout << "Opening Date: " << account_opening_date << "\n";
        std::cout << "Pin: " << pin << "\n\n";
    }

    void check_balance() const {
        std::cout << "\nAccount Holder: " << account_holder_name << "\n";
        std::cout << "Account Number: " << account_number << "\n";
        std::cout << "Balance: " << balance << "\n\n";
    }

    void deposit(double val) { balance += val; }
    void withdraw(double val) { balance -= val; }

    std::string get_name() const { return account_holder_name; }
    long long get_number_val() const { return account_number; }
    double get_balance() const { return balance; }
    int get_pin() const { return pin; }

    static int find_account(long long value, const std::vector<Account>& vec) {
        for (size_t i = 0; i < vec.size(); i++)
            if (vec[i].account_number == value)
                return i;
        return -1;
    }
};
