#ifndef CICUNFERENCIA_H_INCLUDED
#define CIRCUNFERENCIA_H_INCLUDED

typedef struct {
    float raio;
    int x, y;
} Circunferencia;

enum comparacao{
    MENOR,
    MAIOR,
    IGUAL
};
Circunferencia criaCircunferencia (float raio, int x, int y){
    Circunferencia c;
    c.raio = raio;
    c.x = x;
    c.y = y;
    return c;
}
int recuperaRaio(Circunferencia c){
    return c.raio;
}
int recuperaX(Circunferencia c){
    return c.x;
}
int recuperaY(Circunferencia c){
    return c.y;
}
float calculaDiametro(Circunferencia c){
    return c.raio*2;
}
float calculaPerimetro(Circunferencia c){
    return (c.raio)*2*3.14;
}
void alteraRaio(Circunferencia &c, float novoRaio){
    c.raio = novoRaio;
}
void alteraX(Circunferencia &c, int novoX){
    c.x = novoX;
}
void alteraY(Circunferencia &c, int novoY){
    c.x = novoY;
}
comparacao compara2Circunferencias(Circunferencia c1, Circunferencia c2){
    if(c1.raio > c2.raio){
        return MAIOR;}
    else if (c2.raio > c1.raio)
        return MENOR;
    else return IGUAL;
}
bool mesmaPosicao(Circunferencia c1, Circunferencia c2){
    if(c1.x == c2.x and c1.y == c2.y) return true;
    else return false;
}

#endif // CIRCUNFERENCIA_H_INCLUDED
