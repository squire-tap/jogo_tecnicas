#include "Inimigo.hpp"

Inimigo::Inimigo(vector2D<float> pos, vector2D<float> vel, vector2D<float> dim, const string caminhoText, int id, Heroi *p) : 
Atirador(pos, vel, dim, caminhoText, id), pJog1(p), pJog2(NULL)
{
    //adição vida do inimigo
    vida = 10;
	esperaTiro = 0;
}

Inimigo::~Inimigo()
{

}

void Inimigo::atualizar(float t)
{
    /*posicao += (velocidade + correcaoColisao) * t;
    correcaoColisao = vector2D<float>(0.0f, 0.0f);

    velocidade.y = velocidade.y + 2000 * t;
    
    if(abs(pJog1->getPosicao().x - posicao.x)  < 600.0f && esperaTiro < 0)
	{
		atirar(pJog1);
		esperaTiro = 1;
	}
	if (abs(pJog2->getPosicao().x - posicao.x) < 600.0f && esperaTiro < 0)
	{
		atirar(pJog2);
		esperaTiro = 1;
	}
	else
	{
		esperaTiro -= 1 * t;
	}*/
}

void Inimigo::setJogador2(Heroi* jog2)
{
	pJog2 = jog2;
}

void Inimigo::inicializar(GerenciadorGrafico* gg, GerenciadorEventos* ge)
{
       gg->carregarTextura(caminho);
 
       //ge.adicionarOuvinteMouse([this](const sf::Event &e) { tratarEvento(e); } , id);
 }


void Inimigo::colidir(int direcao, int idOutro, vector2D<float> posicaoOutro, vector2D<float> dimensoesOutro)
{
    //Se a colisao for com a bala do jogador , decresce a vida
	if (idOutro == 31)
	{
	    vida -= 2;
	    //Inimigo deixa de existir
	    if(vida <= 0)
	    {	   
			existe = false;
		}
	}
    
    if (idOutro == 21 || idOutro == 22 || idOutro == 23 || idOutro == 24)
    {
        if (direcao == 1)
        {
            if (velocidade.y < 0)
                velocidade.y = 0;
        }
        else if (direcao == 2)
        {
            correcaoColisao.x = 500;
        }
        else if (direcao == 3)
        {
            if (velocidade.y > 0)
            {
                velocidade.y = 0;
                posicao += vector2D<float>(0.0f, (fabs(posicao.y - posicaoOutro.y) - ((dimensao.y + dimensoesOutro.y) / 2.0)));
            }
        }

        else if (direcao == 4)
        {
            correcaoColisao.x = -500;
        }
    }

	/*Adicionar colisão com a tile*/
}


void Inimigo::atirar(bool dir)
{
	/* Cria a munição */
    Municao *p = NULL;
    float correcaoSaidaBalaX = 45.0f;
    float correcaoSaidaBalaY = 8.0f;
	/* Se o jogador estiver atras do inimigo a bala sai em direção ao jogador */
	if (!dir) /* - */
	{
		orientacao = false;
		p = new Municao(posicao + vector2D<float>(-correcaoSaidaBalaX, -correcaoSaidaBalaY), vector2D<float>(-500.0f, 0.0f), vector2D<float>(100.0f, 100.0f), "assets/bala.png", 32);
	}

	/* Caso contrario ela sai para frente em direção ao jogador */
	else
	{
		orientacao = true; 															/* + */
		p = new Municao(posicao + vector2D<float>(correcaoSaidaBalaX, -correcaoSaidaBalaY), vector2D<float>(500.0f, 0.0f), vector2D<float>(100.0f, 100.0f), "assets/bala.png", 32);
	}
	
	lista->inserir(p);
	gc->adicionarColidivel(p); 
	
}

void Inimigo::desenhar(GerenciadorGrafico* gg)
{
	gg->desenhar(caminho , posicao , dimensao , orientacao);
}
