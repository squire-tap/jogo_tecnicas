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
    Desenhavel(vector2D<float> pos = (0.0f , 0.0f) , vector2D<float> vel = (0.0f , 0.0f) , vector2D<float> dim = (0.0f , 0.0f),  const string caminho = " ");
    virtual ~Desenhavel();
    virtual void inicializar(GerenciadorGrafico* gg , GerenciadorEventos *ge);
    virtual void atualizar(float t);
    virtual void desenhar(GerenciadorGrafico* gg);

    vector2D<float> getPosicao();
    vector2D<float> getDimensao();
    void setVelocidade(vector2D<float> velo);

};

#endif