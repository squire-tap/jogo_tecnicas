#include "DiretorMapa.hpp"

DiretorMapa::DiretorMapa(MapaBuilder* bd):
builder(bd)
{
}

DiretorMapa::~DiretorMapa()
{
}

DadosFase* DiretorMapa::criarMapa(Heroi* jog)
{
	builder->buildFase();
	builder->buildJogadores(jog);
	builder->buildInimigos();

	return builder->getMapa();
}

DadosFase* DiretorMapa::criarMapa(Heroi* jog1, Heroi* jog2)
{
	builder->buildFase();
	builder->buildJogadores(jog1, jog2);
	builder->buildInimigos();

	return builder->getMapa();
}