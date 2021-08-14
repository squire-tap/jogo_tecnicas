#pragma once

#include "DadosFase.hpp"

class MapaBuilder
{
protected:
	DadosFase* dados;

public:
	MapaBuilder();
	~MapaBuilder();
	
	virtual void buildFase() = 0;
	virtual void buildJogadores(Heroi* jog) = 0;
	virtual void buildJogadores(Heroi* jog, Heroi* jog2) = 0;
	virtual void buildInimigos() = 0;

	DadosFase* getMapa();
};

