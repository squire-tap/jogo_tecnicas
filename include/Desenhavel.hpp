#ifndef _DESENHAVEL_HPP_
#define _DESENHAVEL_HPP_ 
#include "GerenciadorGrafico.hpp"
#include "GerenciadorEventos.hpp"


class Desenhavel
{
protected:
    vector2D<float> posicao;
    vector2D<float> velocidade;
    vector2D<float> dimensao;
    const string caminho;
    
    
public:
    Desenhavel(vector2D<float> pos , vector2D<float> vel , vector2D<float> dim,  const string caminho = NULL);
    virtual ~Desenhavel();
    virtual void inicializar(GerenciadorGrafico &gg , GerenciadorEventos &ge);
    virtual void atualizar(float t);
    virtual void desenhar(GerenciadorGrafico &gg);

};

#endif