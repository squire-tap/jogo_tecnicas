#include "GerenciadorColisoes.hpp"

#include "Jogador1.hpp"
#include "Jogador2.hpp"

#include "Inimigo1.hpp"
#include "Inimigo2.hpp"
#include "Chefe.hpp"

#include "Areia.hpp"
#include "AreiaTopo.hpp"
#include "Pedra.hpp"
#include "Caixote.hpp"
#include "Cacto.hpp"

#include "Municao.hpp"

GerenciadorColisoes::GerenciadorColisoes():
pontuacao(0)
{
}

GerenciadorColisoes::~GerenciadorColisoes()
{
	colidiveis.clear();
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

		if (fabs(distancia.x) < fabs(distancia.y) && distancia.y > 0)
			return 1;
		else if (fabs(distancia.y) < fabs(distancia.x) && distancia.x > 0)
			return 2;
		else if (fabs(distancia.x) < fabs(distancia.y) && distancia.y < 0)
			return 3;
		else if ((fabs(distancia.y) < fabs(distancia.x) && distancia.x < 0))
			return 4;
		else
			return -1;
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

void GerenciadorColisoes:: setListaDesenhaveis(ListaDesenhaveis* l)
{
	lista = l;
}

int GerenciadorColisoes::getPontuacao()
{
	return pontuacao;
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
			if (pAux->getId() == 11)
				pontuacao += 100;
			else if (pAux->getId() == 12)
				pontuacao += 150;
			else if (pAux->getId() == 13)
				pontuacao += 200;

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

void GerenciadorColisoes::salvar(int i)
{
	ofstream GravadorJog1("salvamento/jogador1.txt", ios::out);
	ofstream GravadorJog2("salvamento/jogador2.txt", ios::out);
	ofstream GravadorBand("salvamento/bandido.txt", ios::out);
	ofstream GravadorBandV("salvamento/bandido_veterano.txt", ios::out);
	ofstream GravadorCh("salvamento/chefe.txt", ios::out);
	ofstream GravadorAr("salvamento/areia.txt", ios::out);
	ofstream GravadorArT("salvamento/areia_topo.txt", ios::out);
	ofstream GravadorPed("salvamento/pedra.txt", ios::out);
	ofstream GravadorCaix("salvamento/caixote.txt", ios::out);
	ofstream GravadorCac("salvamento/cacto.txt", ios::out);
	ofstream GravadorBalAl("salvamento/bala_al.txt", ios::out);
	ofstream GravadorBalIn("salvamento/bala_in.txt", ios::out);
	
	for (auto it = colidiveis.begin(); it != colidiveis.end(); it++)
	{
		if ((*it)->getId() == 1)
		{
			GravadorJog1 << (*it)->getPosicao().x << " " << (*it)->getPosicao().y << " "
				<< (*it)->getVelocidade().x << " " << (*it)->getVelocidade().y << " "
				<< (*it)->getVida() << endl;
		}
		
		else if ((*it)->getId() == 2)
		{

			GravadorJog2 << (*it)->getPosicao().x << " " << (*it)->getPosicao().y << " "
				<< (*it)->getVelocidade().x << " " << (*it)->getVelocidade().y << " "
				<< (*it)->getVida() << endl;

		}

		else if ((*it)->getId() == 11)
		{

			GravadorBand << (*it)->getPosicao().x << " " << (*it)->getPosicao().y << " " <<
				(*it)->getVida() << endl;

		}
		
		else if ((*it)->getId() == 12)
		{

			GravadorBandV << (*it)->getPosicao().x << " " << (*it)->getPosicao().y << " " <<
				(*it)->getVida() << endl;

		}
		
		else if ((*it)->getId() == 13)
		{

			GravadorCh << (*it)->getPosicao().x << " " << (*it)->getPosicao().y << " " <<
				(*it)->getVida() << endl;

		}

		else if ((*it)->getId() == 21)
		{

			GravadorAr << (*it)->getPosicao().x << " " << (*it)->getPosicao().y << endl;

		}

		else if ((*it)->getId() == 22)
		{

			GravadorArT << (*it)->getPosicao().x << " " << (*it)->getPosicao().y << endl;

		}

		else if ((*it)->getId() == 23)
		{

			GravadorPed << (*it)->getPosicao().x << " " << (*it)->getPosicao().y << endl;

		}

		else if ((*it)->getId() == 24)
		{

			GravadorCaix << (*it)->getPosicao().x << " " << (*it)->getPosicao().y << endl;

		}

		else if ((*it)->getId() == 25)
		{

			GravadorCac << (*it)->getPosicao().x << " " << (*it)->getPosicao().y << endl;

		}

		else if ((*it)->getId() == 31)
		{

			GravadorBalAl << (*it)->getPosicao().x << " " << (*it)->getPosicao().y << " " <<
				(*it)->getVelocidade().x << " " << (*it)->getVelocidade().y << endl;

		}
		
		else if ((*it)->getId() == 32)
		{

			GravadorBalIn << (*it)->getPosicao().x << " " << (*it)->getPosicao().y << " " <<
				(*it)->getVelocidade().x << " " << (*it)->getVelocidade().y << endl;

		}
	}
	GravadorJog1.close();
	GravadorJog2.close();
	GravadorBand.close();
	GravadorBandV.close();
	GravadorCh.close();
	GravadorAr.close();
	GravadorArT.close();
	GravadorPed.close();
	GravadorCaix.close();
	GravadorCac.close();
	GravadorBalAl.close();
	GravadorBalIn.close();

	ofstream GravadorPont("salvamento/pontuacao_temp.txt", ios::out);

	GravadorPont << pontuacao << endl;


	GravadorPont.close();

	ofstream GravadorFase("salvamento/fase.txt" , ios::out);

	GravadorFase << i << endl;

	GravadorFase.close();
}

void GerenciadorColisoes::recuperar(Heroi* j1, Heroi* j2)
{
	//removerTodos();
	//lista->destruirDesenhavel();
	
	recuperarJogadores(j1, j2);
	recuperarInimigos(j1, j2);
	recuperarTiles();
	recuperarMunicao();
	recuperarPontuacao();
}

void GerenciadorColisoes::recuperarJogadores(Heroi* j1, Heroi* j2)
{

	vector2D<float> auxVel;
	vector2D<float> auxPos;
	int vida;

	ifstream Recuperarjog1("salvamento/jogador1.txt", ios::in);
	
	Recuperarjog1 >> auxPos.x >> auxPos.y >> auxVel.x >> auxVel.y >> vida;
	j1->setPosicao(auxPos);
	j1->setVelocidade(auxVel);
	j1->setVida(vida);
	
	Recuperarjog1.close();

	ifstream Recuperarjog2("salvamento/jogador2.txt", ios::in);
	
	Recuperarjog2 >> auxPos.x >> auxPos.y >> auxVel.x >> auxVel.y >> vida;
	j2->setPosicao(auxPos);
	j2->setVelocidade(auxVel);
	j2->setVida(vida);
	
	Recuperarjog2.close();
}

void GerenciadorColisoes::recuperarInimigos(Heroi* j1, Heroi* j2)
{
	vector2D<float> pos;
	int vida;

	Inimigo1* in1 = NULL;
	Inimigo2* in2 = NULL;
	Chefe* ch = NULL;

	ifstream RecuperarBandido("salvamento/bandido.txt", ios::in);

	while (!RecuperarBandido.eof())
	{
		RecuperarBandido >> pos.x >> pos.y >> vida;
		in1 = new Inimigo1(pos, j1);
		in1->setGerenciadorColisao(this);
		in1->setListaDesenhaveis(lista);
		if (j2)
			in1->setJogador2(j2);
		adicionarColidivel(in1);
		lista->inserir(in1);

	}

	RecuperarBandido.close();

	ifstream RecuperarBandidoVeterano("salvamento/bandido_veterano.txt", ios::in);

	while (!RecuperarBandidoVeterano.eof())
	{
		RecuperarBandidoVeterano >> pos.x >> pos.y >> vida;
		in2 = new Inimigo2(pos, j1);
		in2->setGerenciadorColisao(this);
		in2->setListaDesenhaveis(lista);
		if (j2)
			in2->setJogador2(j2);
		adicionarColidivel(in2);
		lista->inserir(in2);

	}

	RecuperarBandidoVeterano.close();

	ifstream RecuperarChefe("salvamento/chefe.txt", ios::in);

	while (!RecuperarChefe.eof())
	{
		RecuperarChefe >> pos.x >> pos.y >> vida;
		ch = new Chefe(pos, j1);
		ch->setGerenciadorColisao(this);
		ch->setListaDesenhaveis(lista);
		if (j2)
			in1->setJogador2(j2);
		adicionarColidivel(in1);
		lista->inserir(in1);

	}

	RecuperarChefe.close();
}



void GerenciadorColisoes::recuperarTiles()
{
	vector2D<float> pos;

	Areia* ar = NULL;
	AreiaTopo* at = NULL;
	Pedra* pd = NULL;
	Caixote* cx = NULL;
	Cacto* ct = NULL;


	ifstream RecuperarAreia("salvamento/areia.txt", ios::in);

	while (!RecuperarAreia.eof())
	{
		RecuperarAreia >> pos.x >> pos.y;
		ar = new Areia(pos);
		adicionarColidivel(ar);
		lista->inserir(ar);
	}

	RecuperarAreia.close();


	ifstream RecuperarAreiaTopo("salvamento/areia_topo.txt", ios::in);

	while (!RecuperarAreiaTopo.eof())
	{
		RecuperarAreiaTopo >> pos.x >> pos.y;
		at = new AreiaTopo(pos);
		adicionarColidivel(at);
		lista->inserir(at);
	}

	RecuperarAreiaTopo.close();


	ifstream RecuperarPedra("salvamento/pedra.txt", ios::in);

	while (!RecuperarPedra.eof())
	{
		RecuperarPedra >> pos.x >> pos.y;
		pd = new Pedra(pos);
		adicionarColidivel(pd);
		lista->inserir(pd);
	}

	RecuperarPedra.close();


	ifstream RecuperarCaixote("salvamento/caixote.txt", ios::in);

	while (!RecuperarCaixote.eof())
	{
		RecuperarCaixote >> pos.x >> pos.y;
		cx = new Caixote(pos);
		adicionarColidivel(cx);
		lista->inserir(cx);
	}

	RecuperarCaixote.close();

	ifstream RecuperarCacto("salvamento/cacto.txt", ios::in);

	while (!RecuperarCacto.eof())
	{
		RecuperarCacto >> pos.x >> pos.y;
		ct = new Cacto(pos);
		adicionarColidivel(ct);
		lista->inserir(ct);
	}

	RecuperarCacto.close();
}

void GerenciadorColisoes::recuperarMunicao()
{
	vector2D<float> pos;
	vector2D<float> vel;

	Municao* m = NULL;

	ifstream RecuperarBalaAl("salvamento/bala_al.txt", ios::in);

	while (!RecuperarBalaAl.eof())
	{
		RecuperarBalaAl >> pos.x >> pos.y >> vel.x >> vel.y;
		m = new Municao(pos, vel, vector2D<float>(100.0f, 100.0f), "assets/bala.png", 31);
		adicionarColidivel(m);
		lista->inserir(m);
	}

	RecuperarBalaAl.close();

	ifstream RecuperarBalaIn("salvamento/bala_in.txt", ios::in);

	while (!RecuperarBalaIn.eof())
	{
		RecuperarBalaIn >> pos.x >> pos.y >> vel.x >> vel.y;
		m = new Municao(pos, vel, vector2D<float>(100.0f, 100.0f), "assets/bala.png", 32);
		adicionarColidivel(m);
		lista->inserir(m);
	}

	RecuperarBalaAl.close();
}

void GerenciadorColisoes::recuperarPontuacao()
{
	int pont;

	ifstream RecuperarPont("salvamento/pontuacao_temp.txt", ios::in);

	RecuperarPont >> pont;

	pontuacao = pont;
}

