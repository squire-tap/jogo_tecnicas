#include "Fase1Builder.hpp"

Fase1Builder::Fase1Builder():
tilemap("assets/Fase1v2.json")
{
}

Fase1Builder::~Fase1Builder()
{
}

void Fase1Builder::buildFase()
{
	vector2D<unsigned> dimensoes = tilemap.getDimensoesMapa();
	DadosFase* m = NULL;
	m = new DadosFase(1);

	Tile* t_aux;

	unsigned short i;
	unsigned short j;

	for (i = 0; i < dimensoes.y; i++)
	{
		for (j = 0; j < dimensoes.x; j++)
		{
			if (tilemap[i][j] == 2)
			{
				t_aux = new Tile(vector2D<float>(150.0f * j, 150.0f * i), "assets/areia.png");
				m->incluirTile(t_aux);
			}
			if (tilemap[i][j] == 1)
			{
				t_aux = new Tile(vector2D<float>(150.0f * j, 150.0f * i), "assets/areia_topo.png");
				m->incluirTile(t_aux);
			}
		}
	}
	dados = m;

}

void Fase1Builder::buildJogadores(Heroi* jog)
{
	dados->incluirJogador(jog);
}

void Fase1Builder::buildInimigos(int ini)
{
	Inimigo* i_aux = NULL;
	for (int i = 2; i < ini + 2 ; i++)
	{
		i_aux = new Inimigo(vector2D<float>(2000.0f, 1925.0f), vector2D<float>(0.0f, 0.0f), vector2D<float>(200.0f, 200.f), "assets/inimigo.png" , i ,dados->getJogador());
		dados->incluirInimigo(i_aux);
	}
}
