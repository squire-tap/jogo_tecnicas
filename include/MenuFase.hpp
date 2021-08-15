#ifndef MENUFASE_HPP
#define MENUFASE_HPP
#include "Menu.hpp"
#include "stdafx.hpp"
#include "PlanoFundo.hpp"


class MenuFase : public Menu::Menu{

    private:
        int linhas;
        PlanoFundo pf;
        PlanoFundo titulo;
        PlanoFundo revolver;
        PlanoFundo revolver2;

    public:
        MenuFase(GerenciadorGrafico* gg);
        ~MenuFase();
        int executar();
};

#endif
