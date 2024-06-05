#include <iostream>
#include "Harl.hpp"

int main() {
    Harl   harl;

    std::cout << "debug level: ";
    harl.complain("DEBUG");
    std::cout << "=====================\n";
    std::cout << "info level: ";
    harl.complain("INFO");
    std::cout << "=====================\n";
    std::cout << "warning level: ";
    harl.complain("WARNING");
    std::cout << "=====================\n";
    std::cout << "error level: ";
    harl.complain("ERROR");
    std::cout << "=====================\n";
    std::cout << "invalid level: ";
    harl.complain("none");
    return 0;
}
