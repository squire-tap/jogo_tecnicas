#include "MenuTransicao.hpp"

int MenuTransicao::executar()
{
    cout<<"executando menu transicao"<<endl;

    cout << "Digite :" << endl
         << "8(Fase1)" << endl
         << "9(Menu Fase)" << endl;

    int i;
    cin >> i;

    return i;
}
