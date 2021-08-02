#ifndef HEROI_HPP
#define HEROI_HPP
#include "Colidivel.hpp"


class Heroi : public Colidivel
{
private:
    unsigned int chaveOuvinte;
    
    
public:
    Heroi(vector2D<float> pos);
    ~Heroi();
    void inicializar(GerenciadorGrafico &gg , GerenciadorEventos &ge);
    void atualizar(float t);
    void desenhar(GerenciadorGrafico &gg);
    void tratarEvento(const sf::Event &e);

    void colidir(int direcao, int idOutro, vector2D<float> posicaoOutro, vector2D<float> dimensoesOutro);

};

#endif
