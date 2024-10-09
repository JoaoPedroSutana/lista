#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <string.h>


typedef char TipoDado[100]; //Define o tipo de dado que será armazenado na Lista


struct TipoCelula{

   TipoDado Item;
   TipoCelula *Prox;
};


void Lista_Construtor();

void Lista_Destrutor();

bool Lista_Vazia();

int Lista_Tamanho();

bool Lista_Inserir_Ordenado(TipoDado Elemento);

bool Lista_Inserir_Inicio(TipoDado Elemento);

/*bool Lista_Inserir_Fim(int Elemento);

bool Lista_Inserir(int Elemento, int Posicao);*/

bool Lista_Remover_Inicio(TipoDado &Elemento);

bool Lista_Remover_Fim(TipoDado &Elemento);

bool Lista_Remover(TipoDado &Elemento, int Posicao);

bool Lista_Inicio(TipoDado &Elemento);

bool Lista_Fim(TipoDado &Elemento);

bool Lista_BuscarPeloElemento(TipoDado Elemento, int &Posicao);

bool Lista_BuscarPelaPosicao(TipoDado &Elemento, int Posicao);



#endif // LISTA_H_INCLUDED
