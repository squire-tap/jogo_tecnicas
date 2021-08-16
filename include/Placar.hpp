#ifndef MENUCARREGAR_HPP
#define MENUCARREGAR_HPP
#include "stdafx.hpp"
#include "Menu.hpp"
#include "PlanoFundo.hpp"

class Placar : public Menu::Menu{

    private:
        int linhas;
        PlanoFundo pf;

    public:
        Placar(GerenciadorGrafico* gg);
        ~Placar();
        int executar();

};

#endif
