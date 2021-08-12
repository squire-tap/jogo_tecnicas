#include "Principal.hpp"

#include "Fase1.hpp"
#include "Fase2.hpp"
/*
int main()
{
	Principal principal;

	principal.executar();

	return 0;
}
*/

int main()
{
	Fase1 fase1;

	int i = fase1.executar();

	Fase2 fase2;
	i = fase2.executar();

	return 0;
}