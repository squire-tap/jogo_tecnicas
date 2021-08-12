#ifndef GERENCIADORESTADO_HPP
#define GERENCIADORESTADO_HPP
#include "Estado.hpp"
#include "stdafx.hpp"
#include "Fase1.hpp"
#include "Fase2.hpp"
#include "MenuFase.hpp"
#include "MenuPause.hpp"
#include "MenuTransicao.hpp"

class GerenciadorEstado{
    private:
        stack<Estado*> pilhaEstados;
        Fase1* fase1;
        Fase2* fase2;
        MenuFase* menu_fase;
        MenuPause* menu_pause;
        MenuTransicao* menu_transicao;
        
    
    public:
        GerenciadorEstado(Fase1* fase1 = nullptr, 
                          Fase2* fase2 = nullptr , 
                          MenuFase* menu_fase = nullptr, 
                          MenuPause* menu_pause = nullptr, 
                          MenuTransicao* menu_transicao = nullptr);

        ~GerenciadorEstado();
        bool executar();
        /* void inicializar();  */
        void pushEstado(Estado* p);
        void popEstado();
        void esvaziarPilha();
        int processarCodigo(int codigoRetorno);
};


#endif