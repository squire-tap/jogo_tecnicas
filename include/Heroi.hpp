#ifndef HEROI_HPP
#define HEROI_HPP
#include "Colidivel.hpp"
#include "Atirador.hpp"


class Heroi : public Atirador
{
private:
    unsigned int chaveOuvinte;
    bool noChao;
    
public:
    Heroi(vector2D<float> pos = (0.0f ,0.0f), vector2D<float> vel = (0.0f , 0.0f), vector2D<float> dim = (0.0f , 0.0f), const string caminhoText = " ", int id = 0);
    ~Heroi();
    void inicializar(GerenciadorGrafico &gg , GerenciadorEventos &ge);
    void atualizar(float t);
    void desenhar(GerenciadorGrafico &gg);
    void tratarEvento(const sf::Event &e);
    void colidir(int direcao, int idOutro, vector2D<float> posicaoOutro, vector2D<float> dimensoesOutro);
    void atirar();
};

#endif
