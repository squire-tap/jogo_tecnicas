#include "Fase2Builder.hpp"

Fase2Builder::Fase2Builder():
tilemap("assets/Fase2.json")
{
}

Fase2Builder::~Fase2Builder()
{
}

void Fase2Builder::buildFase()
{
	vector2D<unsigned> dimensoes = tilemap.getDimensoesMapa();
	DadosFase* m = NULL;
	m = new DadosFase(1);

	Tile* t_aux;

	srand(time(NULL));

	for (unsigned short i = 0; i < dimensoes.y; i++)
	{
		for (unsigned short j = 0; j < dimensoes.x; j++)
		{
			if (tilemap[i][j] == 9)
			{
				t_aux = new Pedra(vector2D<float>(200.0f * j, 200.0f * i));
				m->incluirTile(t_aux);
			}
			if (tilemap[i][j] == 4)
			{
				if (i == 2 && j == 22 || i == 15 && j == 8 || i == 8 && j == 2)
				{
					t_aux = new Cacto(vector2D<float>(200.0f * j, 200.0f * i));
					m->incluirTile(t_aux);
				}
				else if (rand() % 2 == 1)
				{
					t_aux = new Cacto(vector2D<float>(200.0f * j, 200.0f * i));
					m->incluirTile(t_aux);
				}
			}
			if (tilemap[i][j] == 5)
			{
				if (i == 1 && j == 17 || i == 15 && j == 2 || i == 10 && j == 17)
				{
					t_aux = new Caixote(vector2D<float>(200.0f * j, 200.0f * i));
					m->incluirTile(t_aux);
				}
				else if (rand() % 2 == 1)
				{
					t_aux = new Caixote(vector2D<float>(200.0f * j, 200.0f * i));
					m->incluirTile(t_aux);
				}
			}
		}
	}
	dados = m;
}

void Fase2Builder::buildJogadores(Heroi* jog)
{
	dados->incluirJogador(jog);
}

void Fase2Builder::buildInimigos(int ini)
{
	Inimigo* i_aux = NULL;
	vector2D<unsigned> dimensoes = tilemap.getDimensoesMapa();

	srand(time(NULL));

	for (unsigned short i = 0; i < dimensoes.y; i++)
	{
		for (unsigned short j = 0; j < dimensoes.x; j++)
		{
			if (tilemap[i][j] == 6)
			{
				if (i == 7 && j == 15 || i == 8 && j == 3 || i == 18 && j == 2)
				{
					i_aux = new Inimigo1(vector2D<float>(200.0f * j, 200.0f * i), dados->getJogador());
					dados->incluirInimigo(i_aux);
				}
				else if (rand() % 2 == 1)
				{
					i_aux = new Inimigo1(vector2D<float>(200.0f * j, 200.0f * i), dados->getJogador());
					dados->incluirInimigo(i_aux);
				}
			}
			if (tilemap[i][j] == 7)
			{
				if (i == 3 && j == 9 || i == 10 && j == 18 || i == 18 && j == 24)
				{
					i_aux = new Inimigo2(vector2D<float>(200.0f * j, 200.0f * i), dados->getJogador());
					dados->incluirInimigo(i_aux);
				}
				else if (rand() % 2 == 1)
				{
					i_aux = new Inimigo2(vector2D<float>(200.0f * j, 200.0f * i), dados->getJogador());
					dados->incluirInimigo(i_aux);
				}
			}
			if (tilemap[i][j] == 8)
			{
				i_aux = new Chefe(vector2D<float>(200.0f * j, 200.0f * i), dados->getJogador());
				dados->incluirInimigo(i_aux);
			}
		}
	}
}
