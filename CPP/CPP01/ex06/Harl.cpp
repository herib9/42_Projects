#include "Harl.hpp"

void    Harl::debug() {
    std::cout << "\nAre using [DEBUG] without using pointers" << std::endl;
}

void    Harl::info() {
    std::cout << "\nAre using [INFO] without using pointers" << std::endl;
}

void    Harl::warning() {
    std::cout << "\nAre reporting [WARNING] without using pointers" << std::endl;
}

void    Harl::error() {
    std::cout << "\nAre reporting [ERROR] without using pointers" << std::endl;
}

void    Harl::complain(std::string level)
{
    std::string  funcPtr[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;

    while(i < 4 && funcPtr[i] != level)
        i++;
    
    switch (i)
    {
        case 0:
            this->debug();
            // FALLTHROUGH
        case 1:
            this->info();
            // FALLTHROUGH
        case 2:
            this->warning();
            // FALLTHROUGH
        case 3:
            this->error();
            break;
        default:
            std::cout << "\nProbably complaining about insignificant problems" << std::endl;
    }
}