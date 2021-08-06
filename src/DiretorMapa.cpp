#include "DiretorMapa.hpp"

DiretorMapa::DiretorMapa(MapaBuilder* bd):
builder(bd)
{
}

DiretorMapa::~DiretorMapa()
{
}

DadosFase* DiretorMapa::criarMapa(int jog, int ini)
{
	builder->buildFase();
	builder->buildJogadores(jog);
	builder->buildInimigos(ini);

	return builder->getMapa();
}
