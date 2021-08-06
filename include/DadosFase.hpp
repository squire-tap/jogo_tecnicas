#pragma once

#include "stdafx.hpp"
#include "Heroi.hpp"
#include "Inimigo.hpp"
#include "Tile.hpp"
#include "ListaDesenhaveis.hpp"
#include "GerenciadorColisoes.hpp"
#include "TileMap.hpp"

class DadosFase
{
private:
	int fase;
	vector<Heroi*> jogadores;
	vector<Inimigo*> inimigos;
	vector<Tile*> tiles;

public:
	DadosFase(int f = 0);
	~DadosFase();

	int getFase();

	void incluirJogador(Heroi* jog);
	void incluirInimigo(Inimigo* ini);
	void incluirTile(Tile* tl);

	void registrarEntidades(GerenciadorColisoes* gC, ListaDesenhaveis* Ld);
	Heroi* getJogador();
};

