#include "Zombie.hpp"

int main() {
	int numberOfZombies;
	std::string	str;
	std::cout << "Please enter the number of Zombies: ";
	std::cin >> str;
	for (int i = 1; str[i]; i++) {
		if (str[0] != '-' && str[0] != '+' && !std::isdigit(str[i])) {
			std::cout << "Incorect character!\n";
			return (1);
		}
	}
	numberOfZombies = std::atoi(str.c_str());
	Zombie* Horde = zombieHorde(numberOfZombies, "heapZombies");
	for (int i = 0; i < numberOfZombies; i++) {
		Horde[i].announce();
	}
	delete[] Horde;
	return (0);
}
