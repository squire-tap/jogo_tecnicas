#include "MenuTransicao.hpp"


MenuTransicao::MenuTransicao(GerenciadorGrafico* gg):
Menu(gg)
{
    auto altura = gg->getJanela()->getSize().x;
    auto largura = gg->getJanela()->getSize().y;

    texto[0].setFont(fonte);
    texto[0].setColor(sf::Color::Green);
    texto[0].setString(" Ir Fase 2");
    texto[0].setPosition(sf::Vector2f(largura / 2 , altura / ( MAXIMO_NUMERO_DE_ITENS + 1) * 1));

    texto[1].setFont(fonte);
    texto[1].setColor(sf::Color::Green);
    texto[1].setString("Voltar Menu Fase");
    texto[1].setPosition(sf::Vector2f(largura / 2 , altura / ( MAXIMO_NUMERO_DE_ITENS + 1) * 2));

}

MenuTransicao::~MenuTransicao()
{
    
}

int MenuTransicao::executar()
{
    while (GG->getJanela()->isOpen())
    {

    sf::Event evento;

        while(GG->getJanela()->pollEvent(evento))
        {
            switch (evento.type)
            {
            case sf::Event::Closed:
                GG->getJanela()->close();
                break;
            
            default:
                break;
            }
        }

        GG->getJanela()->clear();

        GG->desenhaMenus(texto , 3);   

        GG->getJanela()->display();
    
    
    }

    return 0;
}
