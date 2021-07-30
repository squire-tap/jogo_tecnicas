#ifndef HEROI_HPP
#define HEROI_HPP
#include "Desenhavel.hpp"


class Heroi : public Desenhavel
{
private:
    unsigned int chaveOuvinte;
    
    
public:
    Heroi(vector2D<float> pos);
    ~Heroi();
    void inicializar(GerenciadorGrafico &gg , GerenciadorEventos &ge);
    void atualizar(float t);
    // void desenhar(GerenciadorGrafico &gg);
    void tratarEvento(const sf::Event &e);

};

#endif
