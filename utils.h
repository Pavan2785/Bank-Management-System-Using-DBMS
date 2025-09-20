#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <string>

class Utils {
private:
    static std::unordered_map<long long, int> numbers;

public:
    // Get current date as string
    static std::string get_date() {
        time_t now = time(0);
        tm* p = localtime(&now);
        return std::to_string(p->tm_mday) + "-" + 
               std::to_string(p->tm_mon + 1) + "-" + 
               std::to_string(p->tm_year + 1900);
    }

    // Generate unique 10-digit account number
    static long long get_number() {
        long long account_number = 0;
        do {
            account_number = 0;
            for (int i = 0; i < 10; i++)
                account_number = account_number * 10 + (rand() % 10);
        } while (numbers.find(account_number) != numbers.end());

        numbers[account_number] = 1;
        return account_number;
    }
};

// Initialize static member
std::unordered_map<long long, int> Utils::numbers;
