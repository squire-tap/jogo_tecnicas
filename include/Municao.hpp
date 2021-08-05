#ifndef MUNICAO_HPP
#define MUNICAO_HPP
#include "Projetil.hpp"

class Municao: public Projetil
{
private:
    unsigned int chaveOuvinte;
    
public:
    Municao(vector2D<float> pos = (0.0f , 0.0f), vector2D<float> vel = (100.0f , 0.0f), vector2D<float> dim = (0.0f , 0.0f), const string caminhoText = " ", int id = 0);
    ~Municao();
    void atualizar(float t);
    void desenhar(GerenciadorGrafico& gg);
    void inicializar(GerenciadorGrafico& gg , GerenciadorEventos& ge);
    void colidir(int direcao , int idOutro , vector2D<float> posicaoOutro , vector2D<float> dimensoesOutro);
};




#endif