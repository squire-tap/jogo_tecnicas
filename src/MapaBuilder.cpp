#include "MapaBuilder.hpp"

MapaBuilder::MapaBuilder()
{
	mapa = NULL;
}

MapaBuilder::~MapaBuilder()
{
}

DadosFase* MapaBuilder::getMapa()
{
	return mapa;
}
