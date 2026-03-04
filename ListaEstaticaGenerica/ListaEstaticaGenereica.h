#ifndef LISTAESTATICAGENEREICA_H_INCLUDED
#define LISTAESTATICAGENEREICA_H_INCLUDED
using namespace std;
/*Elabore uma unidade sintática para representar uma estrutura de lista estática e operações e relações
para criar uma lista, verificar se uma lista está vazia, recuperar o número de elementos da lista, verificar
se um determinado elemento está na lista, verificar se uma posição qualquer é válida, recuperar um
elemento da lista, recuperar a posição de um elemento da lista, inserir um elemento, retirar um
elemento e exibir os elementos da lista.
Admita que os elementos da referida estrutura de dados sejam de quaisquer tipos.
Utilize uma variável indexada unidimensional para representar a estrutura de dados.
Desenvolva um programa para testar a implementação de lista*/

template <typename T, int MAX>
struct ListaEstaticaGenerica{
    int cardinalidade;
    T elementos[MAX];
};

template <typename T, int MAX>
void cria(ListaEstaticaGenerica<T, MAX> &lista){
    lista.cardinalidade =0;
}
template <typename T, int MAX>
bool ehVazia(ListaEstaticaGenerica<T, MAX> lista){
    return lista.cardinalidade == 0;
}
template <typename T, int MAX>
bool temEspaco(ListaEstaticaGenerica<T, MAX> lista){
    return lista.cardinalidade < MAX;
}
template <typename T, int MAX>
int recuperaCardinalidade(ListaEstaticaGenerica<T, MAX> lista){
    return lista.cardinalidade;
}
template <typename T, int MAX>
bool elementoEstaNaLista(ListaEstaticaGenerica<T, MAX> lista, T elemento){
    for(int i=0; i<lista.cardinalidade; i++){
        return lista.elementos[i]== elemento;
    }
}
template <typename T, int MAX>
bool posicaoValida(ListaEstaticaGenerica<T, MAX> lista, int posicao){
    return posicao>=1 and posicao<=lista.cardinalidade;
}
template <typename T, int MAX>
int RecuperaElemento(ListaEstaticaGenerica<T, MAX> lista, int posicao){
        return lista.elementos[posicao-1];
}
template <typename T, int MAX>
int RecuperaPosicaoElemento(ListaEstaticaGenerica<T, MAX> lista, T elemento){
    for(int i=0; i<lista.cardinalidade; i++){
        if (lista.elementos[i]==elemento)
            return i+1;
    }
}
template <typename T, int MAX>
void InsereLista(ListaEstaticaGenerica<T, MAX> &lista, int posicao, T elemento){
    for(int i=lista.cardinalidade; i>=posicao; i--){
        lista.elementos[i]=lista.elementos[i-1];
    }
    lista.elementos[posicao-1]=elemento;
    lista.cardinalidade++;
}
template <typename T, int MAX>
void RetiraLista(ListaEstaticaGenerica<T, MAX> &lista, int posicao){
    for (int i = posicao; i < lista.cardinalidade; i++)
        lista.elementos[i - 1] = lista.elementos[i];
    lista.cardinalidade--;
}
template <typename T, int MAX>
void Relatorio(ListaEstaticaGenerica<T, MAX> lista){
    for(int i=0; i<lista.cardinalidade;i++){
        cout<<lista.elementos[i]<<" ";
    }
}
template <typename T, int MAX>
void ordenaLista(ListaEstaticaGenerica<T, MAX> &lista){
    T menor;
    int posMenor;
    for(int i=1; i<lista.cardinalidade;i++){
        menor = lista.elementos[i-1];
        posMenor = i-1;
        for(int j=i+1; j<lista.cardinalidade; j++){
            if (lista.elementos[j-1]<=menor){
                menor = lista.elementos[j-1];
                posMenor= j-1;
            }
        }
        lista.elementos[posMenor]=lista.elementos[i-1];
        lista.elementos[i-1]= menor;
    }
}
template <typename T, int MAX>
void MaiorMenor(ListaEstaticaGenerica<T, MAX> lista, T &menor, T &maior){
    menor = lista.elementos[0];
    maior = lista.elementos[0];
    for(int i=1; i<lista.cardinalidade; i++){
        if (lista.elementos[i]<menor)
            menor = lista.elementos[i];
        else if (lista.elementos[i]>maior)
            maior = lista.elementos[i];
    }
}
template <typename T, int MAX>
void RemoveDuplicados(ListaEstaticaGenerica<T, MAX> &lista){
    int i, j;
    for(i=0; i<lista.cardinalidade; i++){
        for(j=i+1; j<lista.cardinalidade; j++){
            if(lista.elementos[i]==lista.elementos[j])
                RetiraLista(lista, j+1);
        }
    }
}

#endif // LISTAESTATICAGENEREICA_H_INCLUDED
