#include "Heroi.hpp"

Heroi::Heroi(vector2D<float> pos , vector2D<float> vel , vector2D<float> dim , const string caminhoText, int id ) :
Atirador(pos, vel, dim , caminhoText, 1)  , noChao(false)
{
    noChao = false;
    vida = 30;
}

Heroi::~Heroi()
{
}
void Heroi::inicializar(GerenciadorGrafico &gg, GerenciadorEventos &ge)
{
    gg.carregarTextura(caminho);

    /* Heroi passa a ser um ouvinte do teclado , que após um evento é chamada a tratar evento do heroi */
     chaveOuvinte = ge.adicionarOuvinteTeclado([this](const sf::Event &e) { tratarEvento(e); });

     chaveOuvinte = ge.adicionarOuvinteMouse( [this] (const sf::Event &e) {tratarEvento(e); });

}
void Heroi::atualizar(float t)
{
    posicao += (velocidade + correcaoColisao) * t;
    correcaoColisao = vector2D<float>(0.0f, 0.0f);
    
    velocidade.y = velocidade.y + 2000 * t;

}
void Heroi::desenhar(GerenciadorGrafico &gg)
{
    gg.desenhar(caminho, posicao, dimensao , orientacao);
}
//Abstrata "virtual pura"
void Heroi::tratarEvento(const sf::Event &e)
{
    if (e.type == sf::Event::KeyPressed)
    {
        switch (e.key.code)
        {
        case sf::Keyboard::Right:
            velocidade.x += 500;
            orientacao = true;
            break;
        case sf::Keyboard::Left:
            velocidade.x += -500;
            orientacao = false;
            break;
        case sf::Keyboard::Up:
            if (noChao)
            {
                velocidade.y = -1450;
                noChao = false;
            }
            break;
        case sf::Keyboard::Down:
            velocidade.y += 100;
            break;
        default:
            break;
        }

    }
    else if (e.type == sf::Event::KeyReleased)
    {
        switch (e.key.code)
        {
        case sf::Keyboard::Right:
            velocidade.x += -500;
            break;
        case sf::Keyboard::Left:
            velocidade.x += 500;
            break;
        //case sf::Keyboard::Up:
            //velocidade.y += 100;
            //break;
        case sf::Keyboard::Down:
            velocidade.y += -100;
            break;
        default:
            break;
        }
    }
    else if (e.type == sf::Event::MouseButtonPressed)
        {
            switch (e.mouseButton.button)
            {
            case sf::Mouse::Left:
                atirar() ;
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
            correcaoColisao.y = -500;
        else if (direcao == 2)
            correcaoColisao.x = 500;
        else if (direcao == 3)
            correcaoColisao.y = 500;
        else if (direcao == 4)
            correcaoColisao.x = -500;
    }

    /*mudar id da tile*/
    if (idOutro == 3)
    {
        if (direcao == 1)
        {
            if (velocidade.y < 0)
                velocidade.y = 0;
        }
        else if (direcao == 2)
        {
            correcaoColisao.x = 500;
        }
        else if (direcao == 3)
        {
            if (velocidade.y > 0)
            {
                velocidade.y = 0;
                noChao = true;
                posicao += vector2D<float>(0.0f, (fabs(posicao.y - posicaoOutro.y) - ((dimensao.y + dimensoesOutro.y) / 2.0)));
            }
        }
        else if (direcao == 4)
        {
            correcaoColisao.x = -500;
        }
    }
    
    if(idOutro == -2)
    {
        //Se a colisao for com a bala do inimigo , decresce a vida em uma unidade
        vida -= 1;
        //Jogador deixa de existir
        if (vida <= 0)
        {
            existe = false;
        }
    }
}

void Heroi::atirar()
{
    /* Cria a munição */
    Municao *p = NULL;
    float correcaoSaidaBalaX = 85.0f;
    float correcaoSaidaBalaY = 12.5f;
    /* Se for o heroi que disparou */
    if(orientacao)
        p = new Municao(posicao + vector2D(correcaoSaidaBalaX , correcaoSaidaBalaY) , vector2D<float>(350.0f, 0.0f), vector2D<float>(100.0f, 100.0f), "assets/bala.png", -1);
    else 
        p = new Municao(posicao + vector2D(-correcaoSaidaBalaX , correcaoSaidaBalaY), vector2D<float>(-350.0f, 0.0f), vector2D<float>(100.0f, 100.0f), "assets/bala.png", -1);

    /* Adiciona a municao à lista */
    lista->inserir(p);
    gc->adicionarColidivel(p); 
}