#include "DadosFase.hpp"

DadosFase::DadosFase(int f):
fase(f)
{
}

DadosFase::~DadosFase()
{
	inimigos.clear();
	tiles.clear();
}

int DadosFase::getFase()
{
	return fase;
}

void DadosFase::setInicio(vector2D<float> inc)
{
	inicio = inc;
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
	for (unsigned i = 0; i < inimigos.size(); i++)
	{
		Ld->inserir(inimigos[i]);
		gC->adicionarColidivel(inimigos[i]);
	}

	for (unsigned i = 0; i < tiles.size(); i++)
	{
		Ld->inserir(tiles[i]);
		gC->adicionarColidivel(tiles[i]);
	}
}

vector2D<float> DadosFase::getPosicaoInicial()
{
	return inicio;
}
