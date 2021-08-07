#pragma once

#include "MapaBuilder.hpp"

class DiretorMapa
{
private:
	MapaBuilder* builder;

public:
	DiretorMapa(MapaBuilder* bd);
	~DiretorMapa();

	DadosFase* criarMapa(Heroi* jog, int ini);
};

