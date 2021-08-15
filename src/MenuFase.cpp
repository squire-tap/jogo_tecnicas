#include "MenuFase.hpp"

int MenuFase::executar()
{
    int i;

    cout << "executando menu fase" << endl;

    cout << "Digite :" << endl
         << "6(Fase1)" << endl
         << "7(Fase2)" << endl;

    cin >> i;

    return i;
}
