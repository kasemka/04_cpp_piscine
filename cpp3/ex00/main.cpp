#include "ClapTrap.hpp"

void ft_simulation(ClapTrap &t1, ClapTrap &t2)
{
	unsigned int damage_before;
	unsigned int new_damage;
	int reapair;
	srand(time(NULL));

	std::cout << std::endl;

	damage_before = t1.getDamages();
	t1.attack(t2.getName());
	new_damage = t1.getDamages() - damage_before;
	t2.takeDamage(new_damage);

	reapair = std::rand() % 4;
	if (t1.getDamages() > damage_before && reapair != 0)
		t2.beRepaired(reapair);
	else if (t1.getDamages() > damage_before)
		std::cout << "Sorry, refuse to repair him :^(" << std::endl;
	std::cout << std::endl;
}

int main(void)
{

	ClapTrap t1("SuperTrap");
	ClapTrap t2(t1);
	t2.setName("PuperTrap");
	srand(time(NULL)); // for rand()

	int turn = std::rand() % 2;
	if (turn)
		ft_simulation(t1, t2);
	else
		ft_simulation(t2, t1);

	return (0);
}