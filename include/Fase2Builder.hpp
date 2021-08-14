#pragma once

#include "MapaBuilder.hpp"

#include "Pedra.hpp"
#include "Cacto.hpp"
#include "Caixote.hpp"

#include "Inimigo1.hpp"
#include "Inimigo2.hpp"
#include "Chefe.hpp"

class Fase2Builder: public MapaBuilder
{
private:
	TileMap tilemap;

public:
	Fase2Builder();
	~Fase2Builder();

	void buildFase();
	void buildJogadores(Heroi* jog);
	void buildJogadores(Heroi* jog1, Heroi* jog2);
	void buildInimigos();
};

