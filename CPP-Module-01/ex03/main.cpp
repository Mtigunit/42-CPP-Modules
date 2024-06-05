#include "HumanA.hpp"
#include "HumanB.hpp"

int main( void ) {
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();

		club = Weapon("crude spiked club");
		HumanB jim("jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();

		HumanB mimoun("mimoun");
		mimoun.attack();
		Weapon *test = new Weapon("Sword");
		if (!test) {
			std::cout << "Allocation Error!" << std::endl;
			return (1);
		}
		mimoun.setWeapon(*test);
		mimoun.attack();
		delete (test);

	return 0;
}
