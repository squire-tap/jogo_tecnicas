#include "DadosFase.hpp"

DadosFase::DadosFase(int f):
fase(f), jog1(NULL), jog2(NULL)
{
}

DadosFase::~DadosFase()
{
}

int DadosFase::getFase()
{
	return fase;
}

void DadosFase::incluirJogador1(Heroi* jog)
{
	jog1 = jog;
}

void DadosFase::incluirJogador2(Heroi* jog)
{
	jog2 = jog;
}


void DadosFase::incluirInimigo(Inimigo* ini)
{
	inimigos.push_back(ini);
}

void DadosFase::incluirTile(Tile* tl)
{
	tiles.push_back(tl);
}

void DadosFase::registrarEntidades(GerenciadorColisoes* gC, ListaDesenhaveis* Ld)
{
	/*
	for (unsigned i = 0; i < jogadores.size(); i++)
	{
		Ld->inserir(jogadores[i]);
		gC->adicionarColidivel(jogadores[i]);
	}
	*/
	for (unsigned i = 0; i < inimigos.size(); i++)
	{
		/* setando para o atirador "inimigo" , a lista para que ele possa incluir a municao na lista desenhaveis */
		inimigos[i]->setListaDesenhaveis(Ld);
		inimigos[i]->setGerenciadorColisao(gC);
		Ld->inserir(inimigos[i]);
		gC->adicionarColidivel(inimigos[i]);
	}

	for (unsigned i = 0; i < tiles.size(); i++)
	{
		Ld->inserir(tiles[i]);
		gC->adicionarColidivel(tiles[i]);
	}
}

Heroi* DadosFase::getJogador1()
{
	return jog1;
}

Heroi* DadosFase::getJogador2()
{
	return jog2;
}
