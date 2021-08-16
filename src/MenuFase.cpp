#include "MenuFase.hpp"

MenuFase::MenuFase(GerenciadorGrafico *gg) :
Menu(gg),
linhas(4),
pf(vector2D<float>(1920.0f, 1080.0f) , "assets/PlanoFundo.png"),
titulo(vector2D<float>(1000.0f , 200.0f) , "assets/dangerous_west.png"),
revolver(vector2D<float>(500.0f , 500.0f) , "assets/revolver.png"),
revolver2(vector2D<float>(500.0f , 500.0f) , "assets/revolver2.png")
{


    auto altura = gg->getJanela()->getSize().y;
    auto largura = gg->getJanela()->getSize().x;

    gg->centralizar( vector2D<float>(float(largura)/2.0f , float(altura)/2.0f ) );

    /* Titulo */
    
    texto[0].setFont(fonte);
    texto[0].setColor(sf::Color::Red);
    texto[0].setString("Fase 1");
    texto[0].setOrigin(sf::Vector2f(texto[0].getLocalBounds().width/2 , texto[0].getLocalBounds().height));
    texto[0].setPosition(sf::Vector2f(largura / 2, altura / (linhas + 1) * 1.5));

    texto[1].setFont(fonte);
    texto[1].setColor(sf::Color::Black);
    texto[1].setString("Fase 2");
    texto[1].setOrigin(sf::Vector2f(texto[1].getLocalBounds().width/2 , texto[1].getLocalBounds().height));
    texto[1].setPosition(sf::Vector2f(largura / 2, altura / (linhas + 1) * 2.0));

    texto[2].setFont(fonte);
    texto[2].setColor(sf::Color::Black);
    texto[2].setString("Carregar Fases");
    texto[2].setOrigin(sf::Vector2f(texto[2].getLocalBounds().width/2 , texto[2].getLocalBounds().height));
    texto[2].setPosition(sf::Vector2f(largura / 2, altura / (linhas + 1) * 2.5));


    texto[3].setFont(fonte);
    texto[3].setColor(sf::Color::Black);
    texto[3].setString("Leaderboard");
    texto[3].setOrigin(sf::Vector2f(texto[3].getLocalBounds().width/2 , texto[3].getLocalBounds().height));
    texto[3].setPosition(sf::Vector2f(largura / 2, altura / (linhas + 1) * 3.0));

    texto[4].setFont(fonte);
    texto[4].setColor(sf::Color::Black);
    texto[4].setString("Sair");
    texto[4].setOrigin(sf::Vector2f(texto[4].getLocalBounds().width/2 , texto[4].getLocalBounds().height));
    texto[4].setPosition(sf::Vector2f(largura / 2, altura / (linhas + 1) * 3.5));
}

MenuFase::~MenuFase()
{
}

int MenuFase::executar()
{
    while (GG->getJanela()->isOpen())
    {

        sf::Event evento;
        
        while (GG->getJanela()->pollEvent(evento))
        {
            switch (evento.type)
            {

            case sf::Event::KeyReleased:
                switch (evento.key.code)
                {
                case sf::Keyboard::Up:
                    moveUp();
                    break;

                case sf::Keyboard::Down:
                    moveDown();
                    break;

                case sf::Keyboard::Enter:
                    if(texto[selectedItemIndex].getString() == "Fase 1")
                        return 6;
                    if(texto[selectedItemIndex].getString() == "Fase 2")
                        return 7;
                    if(texto[selectedItemIndex].getString() == "Carregar Fases")
                        return 13;
                    if(texto[selectedItemIndex].getString() == "Leaderboard")
                        return 11;
                    if(texto[selectedItemIndex].getString() == "Sair")
                        return 10;
                    break;

                default:
                    break;
                }
                break;

            case sf::Event::Closed:
                GG->getJanela()->close();
                return 10;
                break;

            default:
                break;
            }
        }

        GG->getJanela()->clear();

        pf.setPosicao(vector2D<float>(1920.0/2.0f ,975/2.0f ));
        pf.desenhar(GG);

        /* Titulo */
        titulo.setPosicao(vector2D<float>(1920.0/2.0f , 100.0f));
        titulo.desenhar(GG);

        /* revolver */
        revolver.setPosicao(vector2D<float>(500.0f , 975.0/2.0f));
        revolver.desenhar(GG);

        revolver2.setPosicao(vector2D<float>( 1420.0f ,975.0/2.0f));
        revolver2.desenhar(GG); 

        GG->desenhaMenus(texto, linhas);

        GG->getJanela()->display();
    }

    return 0;
}
