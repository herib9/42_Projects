#pragma once

#include <string>

class	Weapon
{
	private:
		std::string	_type;
	
	public:
		Weapon(const std::string &type);

		Weapon();
		~Weapon();
		
		const std::string	&getType(void) const;
		void		setType(const std::string &newType);
};
