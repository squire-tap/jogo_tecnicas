#pragma once

#include "DadosFase.hpp"

class MapaBuilder
{
protected:
	DadosFase* mapa;

public:
	MapaBuilder();
	~MapaBuilder();
	
	virtual void buildFase() = 0;
	virtual void buildJogadores(int jog) = 0;
	virtual void buildInimigos(int ini) = 0;

	DadosFase* getMapa();
};

