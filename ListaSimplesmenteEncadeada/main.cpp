#include <iostream>
#include "ListaSimplesmenteEncadeada.h"

int main()
{
    ListaEncadeada<int> lista;
    criaLista(lista);
    insere(lista, 1, 10);
    insere(lista, 2, 20);
    insere(lista, 3, 30);
    insere(lista, 4, 40);
    mostraLista(lista);
    cout<<endl;
    retira(lista, 2);
    mostraLista(lista);
    inverte(lista);
    cout<<endl;
    mostraLista(lista);
    destroiLista(lista);

    return 0;
}
