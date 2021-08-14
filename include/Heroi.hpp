#ifndef HEROI_HPP
#define HEROI_HPP
#include "Colidivel.hpp"
#include "Atirador.hpp"


class Heroi : public Atirador
{
protected:
    unsigned int chaveOuvinte;
    bool noChao;
    float recarga;
    bool derrotado;
    
public:
    Heroi(vector2D<float> pos = (0.0f ,0.0f), vector2D<float> vel = (0.0f , 0.0f), vector2D<float> dim = (0.0f , 0.0f), const string caminhoText = " ", int id = 0);
    ~Heroi();
    void inicializar(GerenciadorGrafico* gg , GerenciadorEventos* ge);
    void atualizar(float t);
    bool getDerrotado();
    void desenhar(GerenciadorGrafico *gg);
    virtual void tratarEvento(const sf::Event &e);
    void colidir(int direcao, int idOutro, vector2D<float> posicaoOutro, vector2D<float> dimensoesOutro);
    void atirar(bool dir);
};

#endif
