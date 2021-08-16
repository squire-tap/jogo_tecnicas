#ifndef MENUCARREGAR_HPP
#define MENUCARREGAR_HPP
#include "stdafx.hpp"
#include "Menu.hpp"
#include "PlanoFundo.hpp"

class MenuCarregar : public Menu::Menu{

    private:
        int linhas;
        PlanoFundo pf;

    public:
        MenuCarregar(GerenciadorGrafico* gg);
        ~MenuCarregar();
        int executar();

};

#endif
