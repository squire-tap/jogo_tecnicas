#pragma once

#include "MapaBuilder.hpp"

class Fase1Builder : public MapaBuilder
{
private:
	TileMap tilemap;
public:
	Fase1Builder();
	~Fase1Builder();
	
	void buildFase();
	void buildJogadores(int jog);
	void buildInimigos(int ini);
};

