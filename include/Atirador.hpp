#ifndef ATIRADOR_HPP
#define ATIRADOR_HPP
#include "Colidivel.hpp"
#include "ListaDesenhaveis.hpp"
#include "Municao.hpp"
#include "GerenciadorColisoes.hpp"

class Atirador : public Colidivel
{
protected:
    bool podeAtirar;
    ListaDesenhaveis* lista;
    GerenciadorColisoes *gc; //copia da principal
    bool orientacao;
    int vida;
    

public:
    Atirador(vector2D<float> pos = (0.0f ,0.0f), vector2D<float> vel = (0.0f , 0.0f), vector2D<float> dim = (0.0f , 0.0f), const string caminhoText = " ", int id = 0);
    ~Atirador();
    bool getPodeAtirar();
    void setPodeAtirar(bool pode);
    virtual void atirar(bool dir) = 0;
    void setListaDesenhaveis(ListaDesenhaveis* l);
    void setGerenciadorColisao(GerenciadorColisoes *g);
};


#endif