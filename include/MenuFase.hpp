#ifndef MENUFASE_HPP
#define MENUFASE_HPP
#include "Menu.hpp"
#include "stdafx.hpp"
#include "PlanoFundo.hpp"


class MenuFase : public Menu{

    private:
        int linhas;
        PlanoFundo pf;

    public:
        MenuFase(GerenciadorGrafico* gg);
        ~MenuFase();
        int executar();
};

#endif
