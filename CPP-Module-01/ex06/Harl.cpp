#include "Harl.hpp"

void Harl::debug( void ) {
	std::cout << "I love having extra bacon for my " 
			  << "7XL-double-cheese-triple-pickle-specialketchup burger. "
			  << "I really do!" << std::endl;
}

void Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money."
			  << " You didn’t put enough bacon in my burger! If you did, "
			  << "I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free."
			  << " I’ve been coming for years whereas "
			  << "you started working here since last month." << std::endl;
}

void Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." 
			  << std::endl;
}

void Harl::complain( std::string level ) {
	typedef void (Harl::*functionPtr)();
	if (!level.empty()) {
		functionPtr complainFunction[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
		int	i = (level == "DEBUG") ? 0 :
				(level == "INFO") ? 1 :
				(level == "WARNING") ? 2 :
				(level == "ERROR") ? 3 : -1;
		switch (i)
		{
			case (0):
				std::cout << "[ DEBUG ]" << std::endl;
				(this->*complainFunction[0])();
				std::cout << std::endl;
			case (1):
				std::cout << "[ INFO ]" << std::endl;
				(this->*complainFunction[1])();
				std::cout << std::endl;
			case (2):
				std::cout << "[ WARNING ]" << std::endl;
				(this->*complainFunction[2])();
				std::cout << std::endl;
			case (3):
				std::cout << "[ ERROR ]" << std::endl;
				(this->*complainFunction[3])();
				return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
