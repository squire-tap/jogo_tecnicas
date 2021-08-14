#ifndef MENUTRANSICAO_HPP
#define MENUTRANSICAO_HPP
#include "stdafx.hpp"
#include "Menu.hpp"

class MenuTransicao : public Menu
{

public:
    MenuTransicao(GerenciadorGrafico *gg);
    ~MenuTransicao();
    int executar();
};

#endif
