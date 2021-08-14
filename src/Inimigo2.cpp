#include "Inimigo2.hpp"

Inimigo2::Inimigo2(vector2D<float> pos, Heroi* pH) : Inimigo(pos, vector2D<float>(0.0f, 0.0f), vector2D<float>(200.0f, 200.0f), "assets/inimigo_atirador.png", 2, pH)
{
}

Inimigo2::~Inimigo2()
{
}

void Inimigo2::atualizar(float t)
{
	posicao += (velocidade + correcaoColisao) * t;
	correcaoColisao = vector2D<float>(0.0f, 0.0f);

	velocidade.y = velocidade.y + 2000 * t;

	if (abs(pJog1->getPosicao().x - posicao.x) < 600.0f && esperaTiro < 0)
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
	}
}
