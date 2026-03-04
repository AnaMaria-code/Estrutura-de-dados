#include <iostream>
#include "Circunferencia.h"
#define TMAX 5
using namespace std;

int main()
{
    Circunferencia c[TMAX];
    int i, j, x, y;
    float raio;

    for(i=0; i<3; i++){
        cout<<"Circunferencia "<< i+1<<":"<<endl;
        cout<<"Raio:";
        cin>>raio;
        cout<<"X: ";
        cin>>x;
        cout<<"Y: ";
        cin>>y;
        c[i] = criaCircunferencia(raio, x, y);
    }
    c[3] = c[0];
    alteraRaio(c[3], (c[3].raio)+5);
    cout << "circunferencia 5" << endl;
    cout << "raio = ";
    cin >> raio;
    cout << "coordenada Y = ";
    cin >> y;

    c[4] = criaCircunferencia (raio, recuperaY(c[2]) - 10, y);
    alteraRaio (c[0], recuperaRaio(c[0]) + 3);

    for (i = 0; i < 5; i++)
    cout << "perimetro da circunferencia = " << i + 1 << " = "
    << calculaPerimetro(c[i]) << endl;

    for (i = 0; i < 5; i++)
        for (j = i + 1; j < 5; j++)
            if (mesmaPosicao (c[i], c[j]))
                cout << "as circunferencias " << i + 1 << " e " << j + 1
                    << " tem a mesma posicao" << endl;

     return 0;
}
