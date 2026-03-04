#include <iostream>
#include "Fila.h"
using namespace std;

int main()
{
    Fila<int, 3> listaFila;
    cria(listaFila);
    insereFila(listaFila, 10);
    insereFila(listaFila, 20);
    cout<<listaFila.elementos[1];
    cout<<listaFila.elementos[2];
    removeFila(listaFila);
    cout<<listaFila.i;
    return 0;
}
