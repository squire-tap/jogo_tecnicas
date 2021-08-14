#pragma once

#include "MapaBuilder.hpp"

#include "Areia.hpp"
#include "AreiaTopo.hpp"
#include "Cacto.hpp"
#include "Caixote.hpp"

#include "Inimigo1.hpp"
#include "Inimigo2.hpp"
#include "Chefe.hpp"

class Fase1Builder : public MapaBuilder
{
private:
	TileMap tilemap;

public:
	Fase1Builder();
	~Fase1Builder();
	
	void buildFase();
	void buildJogadores(Heroi* jog);
	void buildJogadores(Heroi* jog1, Heroi* jog2);
	void buildInimigos();
};

