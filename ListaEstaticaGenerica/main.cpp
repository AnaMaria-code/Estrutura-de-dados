#include <iostream>
#include "ListaEstaticaGenereica.h"
using namespace std;
#define TMAX 100

int main()
{
    /*Teste das rotinas */

    /*ListaEstaticaGenerica<int,10> listaTeste;
    int menor, maior;

    cria(listaTeste);
    InsereLista(listaTeste, 1, 3);
    InsereLista(listaTeste, 2, 5);
    InsereLista(listaTeste, 3, 2);
    InsereLista(listaTeste, 4, 9);
    InsereLista(listaTeste, 5, 6);
    InsereLista(listaTeste, 6, 3);

    Relatorio(listaTeste);
    cout<<endl;
    RetiraLista(listaTeste, 4);
    Relatorio(listaTeste);
    cout<<endl;
    MaiorMenor(listaTeste, menor, maior);
    cout<<"Maior: "<<maior<<endl;
    cout<<"Menor: "<<menor<<endl;
    ordenaLista(listaTeste);
    Relatorio(listaTeste);
    cout<<endl;
    RemoveDuplicados(listaTeste);
    Relatorio(listaTeste);
    cout<<endl;*/

    /*Desenvolva um programa que utilize a estrutura ListaEstaticaGenerica para gerenciar uma lista
    de produtos de um estoque. O programa deve permitir i) inserir produtos, lendo o nome, o preço e a
    posição no estoque; ii) remover um produto a partir de sua posição no estoque; e iii) exibir todos os
    produtos cadastrados no estoque. O programa deve lançar exceções apropriadas para tentativas de
    inserção em uma lista cheia, remoção de um produto de uma lista vazia ou acesso a posições inválidas.*/
    typedef struct {
        string nome;
        double preco;
    } Produto;

    ListaEstaticaGenerica<Produto, TMAX> produtos;
    int posicao, op;
    cria(produtos);
    Produto p;

    do{
        cout<<"======== MENU ========"<<endl;
        cout<<"Informe a opcao desejada:"<<endl;
        cout<<"1- Inserir produtos."<<endl;
        cout<<"2- Remover produto."<<endl;
        cout<<"3- Relatorio."<<endl;
        cout<<"4- Sair do menu."<<endl;
        cin>>op;
        cin.ignore();
        switch (op){
            case 1:{
                cout<<"Produto:";
                getline(cin, p.nome);
                cout<<"Preco:";
                cin>>p.preco;
                cout<<"Posicao:";
                cin>>posicao;
                if (!temEspaco(produtos))
                    cout<<"Lista cheia"<<endl;
                else{
                    if(posicao <1 or posicao>produtos.cardinalidade+1)
                        cout<<"Posicao invalida"<<endl;
                    else
                        InsereLista(produtos, posicao, p);
                }
                break;
            }
            case 2:{
                cout<<"Posicao do produto que deseja remover:"<<endl;
                cin>>posicao;
                if(ehVazia(produtos))
                    cout<<"Lista vazia."<<endl;
                else if(!posicaoValida(produtos, posicao))
                    cout<<"Posicao invalida."<<endl;
                else
                    RetiraLista(produtos, posicao);
                break;
            }
            case 3:{
                if (ehVazia(produtos))
                    cout<<"Lista vazia.";
                else{
                    cout<<"Relatorio: "<<endl;
                    for(int i=0; i<produtos.cardinalidade; i++){
                        cout<<"Produto: "<<produtos.elementos[i].nome<<endl;
                        cout<<"Preco: "<<produtos.elementos[i].preco<<endl;
                        cout<<"======================="<<endl;
                    }
                }
                break;
            }
            case 4:{
                cout<<"Programa encerrado!"<<endl;
                break;
            }
        }
    }while(op!=4);

    return 0;
}
