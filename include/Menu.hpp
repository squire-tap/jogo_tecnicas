#ifndef MENU_HPP
#define MENU_HPP
#include "stdafx.hpp"
#include "Estado.hpp"

class Menu : public Estado {

    public:
        virtual int executar();
};

#endif