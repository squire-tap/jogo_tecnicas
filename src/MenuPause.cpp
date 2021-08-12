#include "MenuPause.hpp"

int MenuPause::executar()
{
    int i;

    cout << "executando menu pause" << endl;

    cout << "Digite" << endl
         << "4(continuar)" << endl
         << "5(menu fase)" << endl;

    cin >> i;

    return i;
}
