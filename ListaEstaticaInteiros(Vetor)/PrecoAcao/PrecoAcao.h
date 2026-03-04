#ifndef PRECOACAO_H_INCLUDED
#define PRECOACAO_H_INCLUDED

#define TMAX 100
using namespace std;

typedef struct {
    int cardinalidade;
    int elementos[TMAX];
} ListaEstaticaInteiros;

ListaEstaticaInteiros criaLista(){
    ListaEstaticaInteiros lista;
    lista.cardinalidade = 0;
    return lista;
}

bool ehVazia(ListaEstaticaInteiros lista){
    return lista.cardinalidade == 0;
}

bool temEspaco(ListaEstaticaInteiros lista){
    return lista.cardinalidade < TMAX;
}

int recuperaCardinalidade(ListaEstaticaInteiros lista){
    return lista.cardinalidade;
}

bool elementoEstaNaLista(ListaEstaticaInteiros lista, int elemento){
    for(int i=0; i<lista.cardinalidade; i++){
        return lista.elementos[i]== elemento;
    }
}

bool posicaoValida(ListaEstaticaInteiros lista, int posicao){
    return posicao>=1 and posicao<=lista.cardinalidade;
}

int RecuperaElemento(ListaEstaticaInteiros lista, int posicao){
        return lista.elementos[posicao-1];
}

int RecuperaPosicaoElemento(ListaEstaticaInteiros lista, int elemento){
    for(int i=0; i<lista.cardinalidade; i++){
        if (lista.elementos[i]==elemento)
            return i+1;
    }
}

void InsereLista(ListaEstaticaInteiros &lista, int posicao, int elemento){
    for(int i=lista.cardinalidade; i>=posicao; i--){
        lista.elementos[i]=lista.elementos[i-1];
    }
    lista.elementos[posicao-1]=elemento;
    lista.cardinalidade++;
}

void RetiraLista(ListaEstaticaInteiros &lista, int posicao){
    for (int i = posicao; i < lista.cardinalidade; i++)
    lista.elementos[i - 1] = lista.elementos[i];
    lista.cardinalidade--;
}

void Relatorio(ListaEstaticaInteiros lista){
    for(int i=0; i<lista.cardinalidade;i++){
        cout<<lista.elementos[i]<<" ";
    }

}

#endif // PRECOACAO_H_INCLUDED
