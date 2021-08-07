#include "Inimigo.hpp"

Inimigo::Inimigo(vector2D<float> pos, vector2D<float> vel, vector2D<float> dim, const string caminhoText, int id, Heroi *p) : 
Atirador(pos, vel, dim, caminhoText, 2), pHeroi(p)
{
}
Inimigo::~Inimigo()
{

}

void Inimigo::inicializar(GerenciadorGrafico &gg, GerenciadorEventos &ge)
{
       gg.carregarTextura(caminho);
 
       ge.adicionarOuvinteMouse([this](const sf::Event &e)
                                    { tratarEvento(e); });
 }


void Inimigo::colidir(int direcao, int idOutro, vector2D<float> posicaoOutro, vector2D<float> dimensoesOutro)
{
	//if (idOutro == 1)
		//cout << "ai" << endl;
}

void Inimigo::tratarEvento(const sf::Event &e)
{
      /* Caso o jogador atire , o inimigo também atira */
       if (e.type == sf::Event::MouseButtonPressed)
       {
               switch (e.mouseButton.button)
               {
               case sf::Mouse::Left:
                       atirar();
                       break;

               default:
                       break;
               }
       }
 }


void Inimigo::atirar()
{
	/* Cria a munição */
    Municao *p = NULL;
    vector2D<float> correcaoSaidaBala(85.0f, 12.5f);
	/* Se o jogador estiver atras do inimigo a bala sai em direção ao jogador */
	if ( pHeroi->getPosicao().x /* jogador */ <  posicao.x /* inimigo */) /* - */
	{
		orientacao = false;
		p = new Municao(posicao + correcaoSaidaBala, vector2D<float>(-350.0f, 0.0f), vector2D<float>(100.0f, 100.0f), "assets/bala.png", -2);
	}

	/* Caso contrario ela sai para frente em direção ao jogador */
	else
	{
		orientacao = true; 															/* + */
		p = new Municao(posicao + correcaoSaidaBala, vector2D<float>(350.0f, 0.0f), vector2D<float>(100.0f, 100.0f), "assets/bala.png", -2);
	}
	
	lista->inserir(p);
	gc->adicionarColidivel(p); 
	
}

void Inimigo::desenhar(GerenciadorGrafico& gg)
{
	gg.desenhar(caminho , posicao , dimensao , orientacao);
}
