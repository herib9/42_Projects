#pragma once
#include "ClapTrap.hpp"

class	FragTrap	:	virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &player);
		FragTrap &operator=(const FragTrap &player);
		virtual ~FragTrap();

		//virtual void	attack(const std::string &target);
		void	highFivesGuys(void);
};



/*fragtrap hereda attack de claptrap, no deberia de declarar ni hacerse la funcion, la deberia coger automaticamente
hay que revisar todos los constructores de copia, 

*/