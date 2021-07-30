#include "Heroi.hpp"

Heroi::Heroi(vector2D<float> pos) : Desenhavel(pos , vector2D<float>() , vector2D<float>(0.5f,0.5f), "assets/pngegg.png")
{
    
}
Heroi::~Heroi()
{

}
void Heroi::inicializar(GerenciadorGrafico &gg, GerenciadorEventos &ge)
{
    gg.carregarTextura(caminho);
                                    
    chaveOuvinte = ge.adicionarOuvinteTeclado([this] (const sf::Event& e) {tratarEvento(e);});
}
void Heroi::atualizar(float t)
{
    posicao += velocidade * t;

}
/* void Heroi::desenhar(GerenciadorGrafico &gg)
{
    gg.desenhar(caminho, posicao , dimensao);

} */
void Heroi::tratarEvento(const sf::Event &e)
{
    if(e.type == sf::Event::KeyPressed)
    {
        switch (e.key.code)
        {
        case sf::Keyboard::Right:
            velocidade.x += 100;
            break;
        
        case sf::Keyboard::Left:
            velocidade.x += -100;
            break;
        case sf::Keyboard::Up:
            velocidade.y += -100;
            break;
        case sf::Keyboard::Down:
            velocidade.y += 100;
            break;
        default:
            break;
        }
    }
    else if(e.type == sf::Event::KeyReleased)
    {
        switch (e.key.code)
        {
        case sf::Keyboard::Right:
            velocidade.x += -100;
            break;
        
        case sf::Keyboard::Left:
            velocidade.x += 100;
            break;
        case sf::Keyboard::Up:
            velocidade.y += 100;
            break;
        case sf::Keyboard::Down:
            velocidade.y += -100;
            break;
        default:
            break;
        }

    }

}