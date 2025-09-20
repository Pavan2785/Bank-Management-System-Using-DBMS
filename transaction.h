#pragma once
#include <iostream>
#include <string>
#include "account.h"
#include "utils.h"

class Transaction {
public:
    static void deposit_money(Account &acc) {
        double val;
        int entered_pin;
        std::cout << "\nEnter Amount to Deposit: ";
        std::cin >> val;

        std::cout << "Enter Your Pin: ";
        std::cin >> entered_pin;

        if (entered_pin != acc.get_pin()) {
            std::cout << "Invalid Pin. Transaction Failed!\n";
            return;
        }

        acc.deposit(val);
        std::cout << "Amount Deposited Successfully!\n";
        acc.check_balance();
    }

    static void withdraw_money(Account &acc) {
        double val;
        int entered_pin;
        std::cout << "\nEnter Amount to Withdraw: ";
        std::cin >> val;

        if (val > acc.get_balance()) {
            std::cout << "Insufficient Balance!\n";
            return;
        }

        std::cout << "Enter Your Pin: ";
        std::cin >> entered_pin;

        if (entered_pin != acc.get_pin()) {
            std::cout << "Invalid Pin. Transaction Failed!\n";
            return;
        }

        acc.withdraw(val);
        std::cout << "Amount Withdrawn Successfully!\n";
        acc.check_balance();
    }

    static void funds_transfer(Account &sender, Account &receiver) {
        double val;
        int entered_pin;
        std::cout << "\nEnter Amount to Transfer: ";
        std::cin >> val;

        if (val > sender.get_balance()) {
            std::cout << "Insufficient Balance!\n";
            return;
        }

        std::cout << "Enter Your Pin: ";
        std::cin >> entered_pin;

        if (entered_pin != sender.get_pin()) {
            std::cout << "Invalid Pin. Transaction Failed!\n";
            return;
        }

        sender.withdraw(val);
        receiver.deposit(val);

        std::cout << "Fund Transfer Successful!\n";
        sender.check_balance();
        receiver.check_balance();
    }
};
