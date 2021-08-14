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

	srand(time(NULL));

	for (unsigned short i = 0; i < dimensoes.y; i++)
	{
		for (unsigned short j = 0; j < dimensoes.x; j++)
		{
			if (tilemap[i][j] == 2)
			{
				t_aux = new Areia(vector2D<float>(200.0f * j, 200.0f * i));
				m->incluirTile(t_aux);
			}
			if (tilemap[i][j] == 1)
			{
				t_aux = new AreiaTopo(vector2D<float>(200.0f * j, 200.0f * i));
				m->incluirTile(t_aux);
			}
			if (tilemap[i][j] == 4)
			{
				if (i == 3 && j == 10 || i == 9 && j == 7 || i == 12 && j == 20)
				{
					t_aux = new Cacto(vector2D<float>(200.0f * j, 200.0f * i));
					m->incluirTile(t_aux);
				}
				else if(rand() % 2 == 1)
				{
					t_aux = new Cacto(vector2D<float>(200.0f * j, 200.0f * i));
					m->incluirTile(t_aux);
				}
			}
			if (tilemap[i][j] == 5)
			{
				if (i == 3 && j == 11 || i == 9 && j == 12 || i == 12 && j == 21)
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

void Fase1Builder::buildJogadores(Heroi* jog)
{
	dados->incluirJogador1(jog);
}

void Fase1Builder::buildJogadores(Heroi* jog1, Heroi* jog2)
{
	dados->incluirJogador1(jog1);
	dados->incluirJogador2(jog2);
}

void Fase1Builder::buildInimigos()
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
				if (i == 7 && j == 3 || i == 12 && j == 19 || i == 16 && j == 10)
				{
					i_aux = new Inimigo1(vector2D<float>(200.0f * j, 200.0f * i), dados->getJogador1());
					if (dados->getJogador2())
						i_aux->setJogador2(dados->getJogador2());
					dados->incluirInimigo(i_aux);
				}
				else if (rand() % 2 == 1)
				{
					i_aux = new Inimigo1(vector2D<float>(200.0f * j, 200.0f * i), dados->getJogador1());
					if (dados->getJogador2())
						i_aux->setJogador2(dados->getJogador2());
					dados->incluirInimigo(i_aux);
				}
			}
			if (tilemap[i][j] == 7)
			{
				if (i == 9 && j == 13 || i == 12 && j == 26 || i == 18 && j == 26)
				{
					i_aux = new Inimigo2(vector2D<float>(200.0f * j, 200.0f * i), dados->getJogador1());
					if (dados->getJogador2())
						i_aux->setJogador2(dados->getJogador2());
					dados->incluirInimigo(i_aux);
				}
				else if (rand() % 2 == 1)
				{
					i_aux = new Inimigo2(vector2D<float>(200.0f * j, 200.0f * i), dados->getJogador1());
					if (dados->getJogador2())
						i_aux->setJogador2(dados->getJogador2());
					dados->incluirInimigo(i_aux);
				}
			}
			if (tilemap[i][j] == 8)
			{
				i_aux = new Chefe(vector2D<float>(200.0f * j, 200.0f * i), dados->getJogador1());
				if (dados->getJogador2())
					i_aux->setJogador2(dados->getJogador2());
				dados->incluirInimigo(i_aux);
			}
		}
	}
}