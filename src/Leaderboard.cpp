#include "Leaderboard.hpp"

MenuCarregar::MenuCarregar(GerenciadorGrafico *gg):
Menu(gg),
linhas(3),
pf(vector2D<float>(1920.0f, 1080.0f) , "assets/PlanoFundo.png")

{
    auto largura = gg->getJanela()->getSize().x;
    auto altura = gg->getJanela()->getSize().y;

    gg->centralizar( vector2D<float>(float(largura)/2.0f , float(altura)/2.0f ) );

    texto[0].setFont(fonte);
    texto[0].setColor(sf::Color::Red);
    texto[0].setString("Carregar Fase 1");
    texto[0].setOrigin(sf::Vector2f(texto[0].getLocalBounds().width/2 , texto[0].getLocalBounds().height));
    texto[0].setPosition(sf::Vector2f(largura / 2 , altura / ( linhas + 1) * 1.5));

    texto[1].setFont(fonte);
    texto[1].setColor(sf::Color::Black);
    texto[1].setString("Carregar Fase 2");
    texto[1].setOrigin(sf::Vector2f(texto[1].getLocalBounds().width/2 , texto[1].getLocalBounds().height));
    texto[1].setPosition(sf::Vector2f(largura / 2 , altura / ( linhas + 1) * 2));

    texto[2].setFont(fonte);
    texto[2].setColor(sf::Color::Black);
    texto[2].setString("Menu Fase");
    texto[2].setOrigin(sf::Vector2f(texto[2].getLocalBounds().width/2 , texto[2].getLocalBounds().height));
    texto[2].setPosition(sf::Vector2f(largura / 2 , altura / ( linhas + 1) * 2.5));

}
MenuCarregar::~MenuCarregar()
{

}
int MenuCarregar::executar()
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
                    if(texto[selectedItemIndex].getString() == "Carregar Fase 1")
                        return 8;
                    if(texto[selectedItemIndex].getString() == "Carregar Fase 2")
                        return 12;
                    if(texto[selectedItemIndex].getString() == "Menu Fase")
                        return 9;
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

        /* plano de fundo */
        pf.setPosicao(vector2D<float>(1920.0/2.0f ,975/2.0f ));
        pf.desenhar(GG);

        GG->desenhaMenus(texto, linhas);

        GG->getJanela()->display();
    }

    return 0;
}
