#ifndef MUNICAO_HPP
#define MUNICAO_HPP
#include "Projetil.hpp"

class Municao: public Projetil
{
private:
    unsigned int chaveOuvinte;
    bool existe;
public:
    Municao(vector2D<float> pos = (0.0f , 0.0f));
    ~Municao();
    void atualizar(float t);
    void desenhar(GerenciadorGrafico& gg);
    void inicializar(GerenciadorGrafico& gg , GerenciadorEventos& ge);
    void colidir(int direcao , int idOutro , vector2D<float> posicaoOutro , vector2D<float> dimensoesOutro);
};




#endif