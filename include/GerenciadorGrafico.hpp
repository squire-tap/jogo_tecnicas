#ifndef _GERENCIADORGRAFICO_HPP_
#define _GERENCIADORGRAFICO_HPP_
#include "stdafx.hpp"


class GerenciadorGrafico    
{
private:
    sf::RenderWindow *janela;
    sf::Event evento;
    sf::View camera;
    /* mapa de texturas */
    map<const std::string , sf::Texture*> textures;

public:
    GerenciadorGrafico();
    ~GerenciadorGrafico();
    void desenhar(const string caminho , const vector2D<float> posicao , const vector2D<float> dimensao , bool ori);
    void limpar(int r = 0 , int g = 0 , int b = 0);
    bool carregarTextura(const string); 
    void centralizar(const vector2D<float> centro);
    void mostrar();
    /* O const no final significa que se esse metodo for chamado não ira alterar nenhum atributo da classe */
    sf::RenderWindow* getJanela() const; 
};

#endif