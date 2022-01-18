#include "DiamondTrap.hpp"

int main(void)
{

	srand(time(NULL)); // for rand()

	DiamondTrap d("Jojo");
	d.attack("one bad guy");
	d.takeDamage(2);
	d.beRepaired(3);
	d.highFivesGuys();
	d.guardGate();
	d.whoAmI();


	return (0);
}