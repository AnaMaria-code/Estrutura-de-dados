#ifndef JOGODAMEMORIA_H_INCLUDED
#define JOGODAMEMORIA_H_INCLUDED
#include <string>
#include "ListaDuplamenteEncadeada.h"
using namespace std;
enum {
    //tipo da carta
    NORMAL,
    BONUS,
    PENALIDADE
};

typedef struct{
    int id;
    string simbolo;
    bool oculta;
    int tipo;
} Carta;

typedef struct{
    char simbolo;
    int duracao;
    string efeito;
} Bonus;

template<typename T>
void inicializa_cartas(ListaDinamica<T> &cartas){
    string simbolos[17]{
        "🍎", "🍐", "🍊", "🍋", "🍌",
        "🍉", "🍇", "🍓", "🫐", "🍈",
        "🍒", "🍑", "🥭", "🍍", "🥥",
        "🥝", "🍅"
    };
    for(int i = 0; i < 34; i++){
        Carta c{i, simbolos[i%18], true, NORMAL};
        insere(cartas, c);
    }
}

template<typename T>
void cria_tabuleiro(ListaDinamica<T> &tabuleiro){ //tabuleiro: {int id, nodo prox, nodo ant}
    cria(tabuleiro);

}


#endif // JOGODAMEMORIA_H_INCLUDED
