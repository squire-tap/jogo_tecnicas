#include "Heroi.hpp"

Heroi::Heroi(vector2D<float> pos) : Colidivel(pos , vector2D<float>() , vector2D<float>(200.0f,200.0f), "assets/heroi.png", 1)
{
}
Heroi::~Heroi()
{

}
void Heroi::inicializar(GerenciadorGrafico &gg, GerenciadorEventos &ge)
{
    gg.carregarTextura(caminho);

    chaveOuvinte = ge.adicionarOuvinteTeclado( [this] (const sf::Event& e) {tratarEvento(e);} );
}
void Heroi::atualizar(float t)
{
    posicao += (velocidade + correcaoColisao) * t;
    correcaoColisao = vector2D<float>(0.0f , 0.0f);

}
void Heroi::desenhar(GerenciadorGrafico &gg)
{
    gg.desenhar(caminho, posicao , dimensao);

}  
//Abstrata "virtual pura"
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

void Heroi::colidir(int direcao, int idOutro, vector2D<float> posicaoOutro, vector2D<float> dimensoesOutro)
{
    if (idOutro == 2)
    {
        if (direcao == 1)
            correcaoColisao.y = -100;
        else if (direcao == 2 )
            correcaoColisao.x = 100;
        else if (direcao == 3 )
            correcaoColisao.y = 100;
        else if (direcao == 4 )
            correcaoColisao.x = -100;
    }
}
