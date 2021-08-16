#ifndef GERENCIADORESTADO_HPP
#define GERENCIADORESTADO_HPP
#include "Estado.hpp"
#include "stdafx.hpp"
#include "Fase1.hpp"
#include "Fase2.hpp"
#include "MenuFase.hpp"
#include "MenuPause.hpp"
#include "MenuCarregar.hpp"


class GerenciadorEstado{
    private:
        stack<Estado*> pilhaEstados;
        Fase1* fase1;
        Fase2* fase2;
        MenuFase* menu_fase;
        MenuPause* menu_pause;
        MenuCarregar* menu_carregar;
        GerenciadorGrafico* gg;
        GerenciadorEventos* ge;

        
    
    public:
        GerenciadorEstado( GerenciadorGrafico* GG = nullptr , GerenciadorEventos* GE = nullptr);

        ~GerenciadorEstado();
        bool executar();
        /* void inicializar();  */
        void pushEstado(Estado* p);
        void popEstado();
        void esvaziarPilha();
        bool processarCodigo(int codigoRetorno);
};


#endif