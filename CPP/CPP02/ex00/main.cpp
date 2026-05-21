#include "Fixed.hpp"
#include <iostream>

int	main( void )
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	return 0;
}
/*
Fixed a;			// constructor por defecto
Fixed b(a);			// constructor de COPIA — b se crea
Fixed c = a;		// constructor de COPIA — c se crea (no asignación)
Fixed d;			// constructor por defecto — d se crea
d = a;				// operador de ASIGNACIÓN — d ya existía
					// al salir del scope:
					// d, c, b, a destruidos (orden inverso)
*/