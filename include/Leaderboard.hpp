#ifndef MENUCARREGAR_HPP
#define MENUCARREGAR_HPP
#include "stdafx.hpp"
#include "Menu.hpp"
#include "PlanoFundo.hpp"

class Leaderbaord : public Menu::Menu{

    private:
        int linhas;
        PlanoFundo pf;

    public:
        Leaderbaord(GerenciadorGrafico* gg);
        ~Leaderbaord();
        int executar();

};

#endif
