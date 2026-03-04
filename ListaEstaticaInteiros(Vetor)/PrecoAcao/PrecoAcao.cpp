#include <iostream>
#include "PrecoAcao.h"
#include <time.h>
using namespace std;

int main(){
    ListaEstaticaInteiros listaPrecoAcao;
    int ultimoPrecoAcao, minutos;

    srand(time(NULL));

    listaPrecoAcao = criaLista();

    InsereLista(listaPrecoAcao,1, rand()%3 + 5);
    Relatorio(listaPrecoAcao);
    cout << endl;

    minutos = 0;

    while (minutos < 360){
        minutos = minutos + 20;
        ultimoPrecoAcao = RecuperaElemento(listaPrecoAcao, recuperaCardinalidade(listaPrecoAcao));
        InsereLista(listaPrecoAcao, ultimoPrecoAcao + rand()%7 - 3, recuperaCardinalidade(listaPrecoAcao) + 1);
        Relatorio(listaPrecoAcao);
        cout << endl;
    }
    return 0;
}
