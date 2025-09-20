#include <iostream>
#include <vector>
#include "account.h"
#include "transaction.h"
#include "utils.h"

int main() {
    srand(time(0));

    std::vector<Account> account_list;
    int choice;
    bool running = true;

    while (running) {
        std::cout << "\n===== Welcome to Magadha Bank =====\n";
        std::cout << "1. Open Account\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Funds Transfer\n";
        std::cout << "5. Check Balance\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        long long acc_num, acc_num2;
        int idx, idx2;

        switch (choice) {
        case 1: {
            Account acc;
            acc.open_account();
            account_list.push_back(acc);
            break;
        }
        case 2:
            std::cout << "Enter Account Number: ";
            std::cin >> acc_num;
            idx = Account::find_account(acc_num, account_list);
            if (idx != -1) Transaction::deposit_money(account_list[idx]);
            else std::cout << "Account Not Found!\n";
            break;
        case 3:
            std::cout << "Enter Account Number: ";
            std::cin >> acc_num;
            idx = Account::find_account(acc_num, account_list);
            if (idx != -1) Transaction::withdraw_money(account_list[idx]);
            else std::cout << "Account Not Found!\n";
            break;
        case 4:
            std::cout << "Enter Your Account Number: ";
            std::cin >> acc_num;
            idx = Account::find_account(acc_num, account_list);
            if (idx == -1) { std::cout << "Account Not Found!\n"; break; }

            std::cout << "Enter Recipient Account Number: ";
            std::cin >> acc_num2;
            idx2 = Account::find_account(acc_num2, account_list);
            if (idx2 == -1) { std::cout << "Recipient Not Found!\n"; break; }

            Transaction::funds_transfer(account_list[idx], account_list[idx2]);
            break;
        case 5:
            std::cout << "Enter Account Number: ";
            std::cin >> acc_num;
            idx = Account::find_account(acc_num, account_list);
            if (idx != -1) account_list[idx].check_balance();
            else std::cout << "Account Not Found!\n";
            break;
        case 6:
            running = false;
            break;
        default:
            std::cout << "Invalid Option!\n";
        }
    }

    return 0;
}
