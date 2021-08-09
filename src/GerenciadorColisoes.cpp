#include "GerenciadorColisoes.hpp"

GerenciadorColisoes::GerenciadorColisoes()
{
}

GerenciadorColisoes::~GerenciadorColisoes()
{
	set<Colidivel*>::iterator it;
	Colidivel* c_aux = NULL;
	for (it = colidiveis.begin(); it != colidiveis.end(); it++) //limpando vector de colidiveis
	{
		if (*it)
		{
			delete* it;
		}
	}
}

int GerenciadorColisoes::estadoColidindo(Colidivel* p1, Colidivel* p2)
{
	vector2D<float> pos1 = p1->getPosicao();
	vector2D<float> dimen1 = p1->getDimensao();

	vector2D<float> pos2 = p2->getPosicao();
	vector2D<float> dimen2 = p2->getDimensao();

	vector2D<float> distancia = pos1 - pos2;

	if ((fabs(distancia.x) < ((dimen1.x + dimen2.x) / 2.0)) && (fabs(distancia.y) < ((dimen1.y + dimen2.y) / 2.0)))
	{
		//cout << distancia.x << "  " << distancia.y << endl;
		if (fabs(distancia.x) < fabs(distancia.y) && distancia.y > 0)
			return 1;
		else if (fabs(distancia.y) < fabs(distancia.x) && distancia.x > 0)
			return 2;
		else if (fabs(distancia.x) < fabs(distancia.y) && distancia.y < 0)
			return 3;
		else if ((fabs(distancia.y) < fabs(distancia.x) && distancia.x < 0))
			return 4;
	}
	else
		return 0;
}

void GerenciadorColisoes::adicionarColidivel(Colidivel* pC)
{
	colidiveis.insert(pC);
}

void GerenciadorColisoes::removerColidivel(Colidivel* pC)
{
	colidiveis.erase(pC);
}

void GerenciadorColisoes::removerTodos()
{
	colidiveis.clear();
}

void GerenciadorColisoes::setListaDesenhaveis(ListaDesenhaveis* l)
{
	lista = l;
}

void GerenciadorColisoes::verificarColisoes()
{
	for (auto it1 = colidiveis.begin(); it1 != colidiveis.end(); it1++)
	{
		auto it2 = it1;
		it2++;

		for (; it2 != colidiveis.end(); it2++)
		{
			if (estadoColidindo(*it1, *it2))
			{
				int dir12 = estadoColidindo(*it1, *it2);
				int dir21 = estadoColidindo(*it2, *it1);
				(*it1)->colidir(dir12, (*it2)->getId(), (*it2)->getPosicao(), (*it2)->getDimensao());
				(*it2)->colidir(dir21, (*it1)->getId(), (*it1)->getPosicao(), (*it1)->getDimensao());
			}
		}

	}

	/* Limpa colidiveis com o valor booleano de existe = false */
	
	limpaDesenhaveis();
}

void GerenciadorColisoes::limpaDesenhaveis()
{
	Colidivel* pAux;
    set<Colidivel*> limpeza;

    for (auto iterador = colidiveis.begin(); iterador != colidiveis.end(); iterador++)
    {
        pAux = *iterador;

        /* Caso existe for false */
        if (!pAux->getExiste())
        {
            limpeza.insert(pAux);
        }

    }

     for (auto iterador = limpeza.begin(); iterador != limpeza.end(); iterador++)
    {
        pAux = *iterador;

        removerColidivel(pAux);
        lista->removerDestruir(pAux);
	}



    limpeza.clear();

}
