#ifndef LISTASIMPLESMENTEENCADEADA_H_INCLUDED
#define LISTASIMPLESMENTEENCADEADA_H_INCLUDED

using namespace std;

/*Elabore uma unidade sintática para representar uma estrutura de lista dinâmica e construa operações e
relações para criar uma lista, destruir uma lista, verificar se uma lista está vazia, recuperar o número de
elementos da lista, verificar se um determinado elemento existe na lista, verificar se uma posição qualquer
é válida, recuperar um elemento da lista, recuperar a posição de um elemento da lista, inserir um elemento
na lista, retirar um elemento da lista e exibir os elementos da lista.*/

template <typename T>
struct Nodo{
    T elemento;
    Nodo<T>* proximo;
};

template <typename T>
struct ListaEncadeada{
    int cardinalidade;
    Nodo<T>* inicio;
};

template <typename T>
void criaLista(ListaEncadeada<T> &lista){
    lista.cardinalidade = 0;
    lista.inicio = NULL;
}

template <typename T>
void destroiLista(ListaEncadeada<T> &lista){
    Nodo<T>* paux;
    while (lista.inicio!= NULL){
        paux = lista.inicio;
        lista.inicio = lista.inicio->proximo;
        delete paux;
    }
    lista.cardinalidade = 0;
}

template <typename T>
bool ehVazia(ListaEncadeada<T> lista){
    return (lista.cardinalidade == 0);
}

template <typename T>
int recuperaCardinalidade(ListaEncadeada<T> lista){
    return lista.cardinalidade;
}

template <typename T>
bool existeElemento(ListaEncadeada<T> lista, T elemento){
    Nodo<T>* paux;
    while(paux!= NULL){
        paux = lista.inicio;
        if (paux->elemento == elemento)
            return true;
        paux = paux->proximo;
    }
    return false;
}

template <typename T>
bool posicaoValida(ListaEncadeada<T> lista, int posicao){
    return ((posicao>=1) and (posicao<=lista.cardinalidade));
}

template <typename T>
T recuperaElemento(ListaEncadeada<T> lista, int posicao){
    if(posicao<1 or posicao>lista.cardinalidade)
        throw "POSICAO INVALIDA";
    Nodo<T>* p;
    p = lista.inicio;
    int i = 1;
    while(i < posicao){
        p = p->proximo;
        i++;
    }
    return p->elemento;
}

template <typename T>
int recuperaPosicao(ListaEncadeada<T> lista, T elemento){
    if (!existeElemento(lista, elemento))
        throw "ELEMENTO NAO ESTA NA LISTA";
    int i = 1;
    Nodo<T>* paux = lista.inicio;
    while(paux->elemento != elemento){
        paux = paux->proximo;
        i++;
    }
    return i;
}

template <typename T>
void insere(ListaEncadeada<T> &lista, int posicao, T elemento){
    //verifica se a posicao eh valida
    if (posicao <1 or posicao>lista.cardinalidade+1)
        throw "POSICAO INVALIDA";
    //cria o nodo, aloca memoria e preenche
    Nodo<T>* q = new Nodo<T>;
    q->elemento = elemento;
    q->proximo = NULL;
    //caso a lista esteja vazia
    if(lista.inicio ==NULL)
        lista.inicio = q;
    else{
        //inserir na primeira posicao de uma lista que nao esta vazia
        if(posicao == 1){
                q->proximo = lista.inicio;
                lista.inicio = q;
        }
        else{
            int i=1;
            Nodo<T>* paux = lista.inicio;
            while(i != posicao-1){
                paux = paux->proximo;
                i++;
            }
            q->proximo = paux->proximo;
            paux->proximo = q;
        }
    }
    lista.cardinalidade++;
}

template <typename T>
void retira(ListaEncadeada<T> &lista, int posicao){
    if(ehVazia(lista))
        throw "LISTA VAZIA";
    if(posicao<1 or posicao>lista.cardinalidade)
        throw "POSICAO INVALIDA";
    Nodo<T>* q = lista.inicio;
    if(posicao == 1){
        lista.inicio = lista.inicio->proximo;
    }
    else{
        Nodo<T>* p = lista.inicio;
        int i =1;
        while(i<posicao-1){
            p=p->proximo;
            i++;
        }
        q = p->proximo;
        p->proximo = q->proximo;
    }
    delete q;
    lista.cardinalidade --;
}

template<typename T>
void mostraLista(ListaEncadeada<T> lista){
    Nodo<T>* paux=lista.inicio;
    while(paux!=NULL){
        cout<<paux->elemento <<" ";
        paux =paux->proximo;
    }
}
//Elabore uma rotina para inverter a ordem dos elementos de uma lista simplesmente encadeada
/*template<typename T>
void inverteLista(ListaEncadeada<T> &lista){
    Nodo<T>* p;
    Nodo<T>* q;
    p = lista.inicio;
    while(p!=NULL){
        if(p->proximo==NULL) break;
        p = p->proximo;
    }
    q = p;
    p = lista.inicio;
    int i = 1;
    while(i != lista.cardinalidade/2){
        T elem = p->elemento;
        p->elemento = q->elemento;
        q->elemento = elem;
        i++;
    }
}*/
template<typename T>
void inverte(ListaEncadeada<T> &lista){
    int n = lista.cardinalidade;
    for(int i = 1; i <= n/2; i++){
        Nodo<T>* p = lista.inicio;
        Nodo<T>* q = lista.inicio;
        for(int j = 1; j < i; j++){
            p = p->proximo;
        }
        for(int j = 1; j < n - i + 1; j++){
            q = q->proximo;
        }
        T elem = p->elemento;
        p->elemento = q->elemento;
        q->elemento = elem;
    }
}

#endif // LISTASIMPLESMENTEENCADEADA_H_INCLUDED
