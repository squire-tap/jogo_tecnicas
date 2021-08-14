#include "MenuFase.hpp"

MenuFase::MenuFase(GerenciadorGrafico *gg) :
Menu(gg),
linhas(3),
pf()
{


    auto altura = gg->getJanela()->getSize().y;
    auto largura = gg->getJanela()->getSize().x;

    gg->centralizar( vector2D<float>(float(largura)/2.0f , float(altura)/2.0f ) );

    cout << altura << endl;
    cout << largura << endl;

    texto[0].setFont(fonte);
    texto[0].setColor(sf::Color::Red);
    texto[0].setString("Fase 1");
    texto[0].setPosition(sf::Vector2f(largura / 2, altura / (linhas + 1) * 1));

    texto[1].setFont(fonte);
    texto[1].setColor(sf::Color::Black);
    texto[1].setString("Fase 2");
    texto[1].setPosition(sf::Vector2f(largura / 2, altura / (linhas + 1) * 2));

    texto[2].setFont(fonte);
    texto[2].setColor(sf::Color::Black);
    texto[2].setString("Sair");
    texto[2].setPosition(sf::Vector2f(largura / 2, altura / (linhas + 1) * 3));
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

        pf.setPosicao(vector2D<float>(1980.0/2.f ,1080/2.f ));
        pf.desenhar(GG);

        GG->desenhaMenus(texto, linhas);

        GG->getJanela()->display();
    }

    return 0;
}
