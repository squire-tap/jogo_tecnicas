#ifndef MENU_HPP
#define MENU_HPP
#define MAXIMO_NUMERO_DE_ITENS 5
#include "stdafx.hpp"
#include "Estado.hpp"
#include "GerenciadorGrafico.hpp"

namespace Menu{

class Menu : public Estado {

    protected:

        GerenciadorGrafico* GG;
        int selectedItemIndex;
        sf::Font fonte;
        sf::Text texto[MAXIMO_NUMERO_DE_ITENS];

    public:

        Menu(GerenciadorGrafico* gg);
       ~Menu(); 

        
        void moveUp();
        void moveDown(); 
        virtual int executar() = 0;

};

}

#endif