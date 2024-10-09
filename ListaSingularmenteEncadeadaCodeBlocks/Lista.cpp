//Bibliotecas necessárias
#include <cstdio>
#include <cstdlib>
#include "Lista.h"
#include <iostream>
#include <string>
#include <cstring>  // Para comparação e manipulação de strings

using namespace std;

TipoCelula *Frente, *Tras;

int Contador;

void Lista_Construtor() {
    Frente = Tras = NULL;
    Contador = 0;
}

void Lista_Destrutor() {
    TipoCelula *Temp;

    while (Frente != NULL) {
        Temp = Frente;
        Frente = Frente->Prox;

        Temp->Prox = NULL;
        free(Temp);
    }

    Tras = NULL;
    Contador = 0;
}

bool Lista_Vazia() {
    return Frente == NULL;
}

int Lista_Tamanho() {
    return Contador;
}

bool Lista_Inserir_Ordenado(TipoDado Elemento) {

    int posicao;

    if (Lista_BuscarPeloElemento(Elemento, posicao)) { //if para verificar se uma string já esta na lista
        return false;
    }

    TipoCelula *Novo; // Criar nova célula
    Novo = (TipoCelula *) malloc(sizeof(TipoCelula));
    if (Novo == NULL) {
        return false;
    }

    strcpy(Novo->Item, Elemento); // Copiar o conteúdo da string para um novo elemento

    if (Lista_Vazia()) {  // Se a lista está vazia, a string é inserida no início
        Novo->Prox = NULL;
        Frente = Tras = Novo;
    } else {
        TipoCelula *Atual = Frente;
        TipoCelula *Anterior = NULL;

        while (Atual != NULL && strcmp(Atual->Item, Elemento) < 0) { // Procurar a posição correta para inserir em ordem alfabética
            Anterior = Atual;
            Atual = Atual->Prox;
        }

        if (Anterior == NULL) {
            Novo->Prox = Frente; // Inserir no início
            Frente = Novo;
        } else {
            Anterior->Prox = Novo; // Inserir no meio ou fim
            Novo->Prox = Atual;

            if (Atual == NULL) { // Se a string foi inserida no final da ista, o ponteiro Tras é atualizado
                Tras = Novo;
            }
        }
    }

    Contador++;
    return true;
}

bool Lista_Inserir_Inicio(TipoDado Elemento) {
    TipoCelula *Novo;
    Novo = (TipoCelula *) malloc(sizeof(TipoCelula));
    if (Novo == NULL) {
        return false;
    }

    strcpy(Novo->Item, Elemento);

    Novo->Prox = Frente;

    if (Lista_Vazia()) {
        Tras = Novo;
    }

    Frente = Novo;
    Contador++;
    return true;
}

bool Lista_Remover_Inicio(TipoDado &Elemento) {
    if (!Lista_Vazia()) {
        TipoCelula *Temp = Frente;

        strcpy(Elemento, Frente->Item);
        Frente = Frente->Prox;
        Temp->Prox = NULL;

        free(Temp);

        if (Frente == NULL) {
            Tras = NULL;
        }

        Contador--;
        return true;
    } else {
        return false;
    }
}

bool Lista_Remover_Fim(TipoDado &Elemento) {
    if (!Lista_Vazia()) {
        TipoCelula *Temp = Frente;

        if (Frente == Tras) {
            strcpy(Elemento, Tras->Item);
            free(Tras);
            Frente = Tras = NULL;
            Contador--;
            return true;
        }

        while (Temp->Prox != Tras) {
            Temp = Temp->Prox;
        }

        strcpy(Elemento, Tras->Item);
        free(Tras);
        Tras = Temp;
        Tras->Prox = NULL;

        Contador--;
        return true;
    } else {
        return false;
    }
}

bool Lista_Remover(TipoDado &Elemento, int Posicao) {
    if (Posicao < 0 || Posicao >= Contador) return false;

    TipoCelula *Temp = Frente;
    TipoCelula *Anterior = NULL;

    for (int i = 0; i < Posicao; i++) {
        Anterior = Temp;
        Temp = Temp->Prox;
    }

    if (Anterior == NULL) {
        Frente = Frente->Prox;
        if (Frente == NULL) {
            Tras = NULL;
        }
    } else {
        Anterior->Prox = Temp->Prox;
        if (Temp == Tras) {
            Tras = Anterior;
        }
    }

    strcpy(Elemento, Temp->Item);
    free(Temp);
    Contador--;

    return true;
}

bool Lista_Inicio(TipoDado &Elemento) {
    if (!Lista_Vazia()) {
        strcpy(Elemento, Frente->Item);
        return true;
    } else {
        return false;
    }
}

bool Lista_Fim(TipoDado &Elemento) {
    if (!Lista_Vazia()) {
        strcpy(Elemento, Tras->Item);
        return true;
    } else {
        return false;
    }
}

bool Lista_BuscarPeloElemento(TipoDado Elemento, int &Posicao) {
    TipoCelula *Temp = Frente;
    int i = 0;

    while (Temp != NULL) {
        if (strcmp(Temp->Item, Elemento) == 0) {
            Posicao = i;
            return true;
        }
        Temp = Temp->Prox;
        i++;
    }

    return false;
}

bool Lista_BuscarPelaPosicao(TipoDado &Elemento, int Posicao) {
    if (Posicao < 0 || Posicao >= Contador) return false;

    TipoCelula *Temp = Frente;
    for (int i = 0; i < Posicao; i++) {
        Temp = Temp->Prox;
    }

    strcpy(Elemento, Temp->Item);
    return true;
}
