#include "Fase1Builder.hpp"

Fase1Builder::Fase1Builder():
tilemap("assets/mapaMaior_teste.json")
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
			if (tilemap[i][j] == 1)
			{
				t_aux = new Tile(vector2D<float>(50.0f * j, 50.0f * i), "assets/areia.png");
				m->incluirTile(t_aux);
			}

		}
	}
	mapa = m;

}

void Fase1Builder::buildJogadores(int jog)
{
	Heroi* jog1 = NULL;
	if (jog == 1)
	{
		jog1 = new Heroi(vector2D<float>(100.0f, 100.0f), vector2D<float>(0.0f, 0.0f), vector2D<float>(200.0f, 200.0f), "assets/heroi.png");
		mapa->incluirJogador(jog1);
	}
	else
	{
		cout << "multiplayer ainda nao implementado! Aguarde próximas atuializacoes!" << endl;
		exit(190);
	}
}

void Fase1Builder::buildInimigos(int ini)
{
	Inimigo* i_aux = NULL;
	for (int i = 0; i < ini; i++)
	{
		i_aux = new Inimigo(vector2D<float>(2000.0f, 1925.0f), vector2D<float>(0.0f, 0.0f), vector2D<float>(200.0f, 200.f), "assets/inimigo.png");
		mapa->incluirInimigo(i_aux);
	}
}
