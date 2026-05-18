#include "Harl.hpp"

void    Harl::debug() {
    std::cout << "Are using [DEBUG] without using pointers\n" << std::endl;
}

void    Harl::info() {
    std::cout << "Are using [INFO] without using pointers\n" << std::endl;
}

void    Harl::warning() {
    std::cout << "Are reporting [WARNING] without using pointers\n" << std::endl;
}

void    Harl::error() {
    std::cout << "Are reporting [ERROR] without using pointers\n" << std::endl;
}

void    Harl::complain(std::string level)
{
    void (Harl::*funcPtr[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    std::string numLevel[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int i = 0;
    while (i < 4)
    {
        if(numLevel[i] == level)
        {
            (this->*funcPtr[i])();
            return ;
        }
        i++;
    }
    std::cout << "[UNKNOWN]" << std::endl;

}