#include "MapaBuilder.hpp"

MapaBuilder::MapaBuilder()
{
	dados = NULL;
}

MapaBuilder::~MapaBuilder()
{
}

DadosFase* MapaBuilder::getMapa()
{
	return dados;
}
