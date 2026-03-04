#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
using namespace std;
#define TMAX 100
template <typename T, int MAX>
struct Fila{
    int cardinalidade, i, f;
    T elementos[MAX];
};
template <typename T, int MAX>
void cria(Fila<T, MAX> &fila){
    fila.cardinalidade = 0;
    fila.i =0;
    fila.f =0;
}

template <typename T, int MAX>
bool ehVazia(Fila<T, MAX> fila){
    return (fila.cardinalidade == 0);
}
template <typename T, int MAX>
bool temEspaco(Fila<T, MAX> fila){
    return (fila.cardinalidade < MAX);
}
template <typename T, int MAX>
int recuperaCardinalidade(Fila<T, MAX> fila){
    return (fila.cardinalidade);
}
template<typename T, int MAX>
void insereFila(Fila<T, MAX> &fila, T elemento){
    if(fila.cardinalidade != MAX){
        if(fila.f == MAX){
            fila.f = 1;
        }
        else fila.f = fila.f+1;
        fila.elementos[fila.f] = elemento;
        fila.cardinalidade ++;
    }else  throw "OVERFLOW";
}
template<typename T, int MAX>
void removeFila(Fila<T, MAX> &fila){
    if(fila.cardinalidade > 0){
            if(fila.i == MAX){
                fila.i = 1;
            }
            else fila.i ++;
            fila.cardinalidade--;
    }else throw "LISTA VAZIA";
}

/*template<typename T, int MAX>
bool estaNaFista(Fila<T, MAX> fila, T elemento){

}*/
#endif // FILA_H_INCLUDED
