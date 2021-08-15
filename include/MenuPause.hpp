#ifndef MENUPAUSE_HPP
#define MENUPAUSE_HPP
#include "stdafx.hpp"
#include "Menu.hpp"
#include "PlanoFundo.hpp"

class MenuPause : public Menu{

    private:
        int linhas;
        PlanoFundo pf;
        PlanoFundo pause;

    public:
        MenuPause(GerenciadorGrafico* gg);
        ~MenuPause();
        int executar();

};

#endif
