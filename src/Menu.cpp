#include "Menu.hpp"


Menu::Menu(GerenciadorGrafico* gg): 
GG(gg),
selectedItemIndex(0)
{
    if(!fonte.loadFromFile("Fontes/stocky.ttf"))
    {
        cerr << "ERROR! fonte não carregada!" <<endl;
        exit(120);
    }

}

Menu::~Menu()
{

}

void Menu::moveUp()
{
    if(selectedItemIndex - 1 >= 0)
    {
        texto[selectedItemIndex].setColor(sf::Color::Black);
        selectedItemIndex--;
        texto[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::moveDown()
{
    if(selectedItemIndex + 1 < MAXIMO_NUMERO_DE_ITENS)
    {
        texto[selectedItemIndex].setColor(sf::Color::Black);
        selectedItemIndex++;
        texto[selectedItemIndex].setColor(sf::Color::Red);
    }
}