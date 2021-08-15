#include "MenuPause.hpp"

MenuPause::MenuPause(GerenciadorGrafico *gg):
Menu(gg),
linhas(2),
pf(vector2D<float>(1920.0f, 1080.0f) , "assets/PlanoFundo.png"),
pause(vector2D<float>(500.0f, 500.0f) , "assets/pause.png")

{
    auto largura = gg->getJanela()->getSize().x;
    auto altura = gg->getJanela()->getSize().y;

    gg->centralizar( vector2D<float>(float(largura)/2.0f , float(altura)/2.0f ) );

    texto[0].setFont(fonte);
    texto[0].setColor(sf::Color::Red);
    texto[0].setString("Continuar");
    texto[0].setPosition(sf::Vector2f(largura / 2 , altura / ( linhas + 1) * 1));

    texto[1].setFont(fonte);
    texto[1].setColor(sf::Color::Black);
    texto[1].setString("Menu Fase");
    texto[1].setPosition(sf::Vector2f(largura / 2 , altura / ( linhas + 1) * 2));

}

MenuPause::~MenuPause()
{

}

int MenuPause::executar()
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
                    if(texto[selectedItemIndex].getString() == "Continuar")
                        return 4;
                    if(texto[selectedItemIndex].getString() == "Menu Fase")
                        return 5;
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

        /* icone pause */
        pause.setPosicao(vector2D<float>(500.0f , 975/2.0f));
        pause.desenhar(GG);



        GG->desenhaMenus(texto, linhas);

        GG->getJanela()->display();
    }

    return 0;
}
