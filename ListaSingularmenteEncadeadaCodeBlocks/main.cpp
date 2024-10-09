#include <cstdio>
#include <cstdlib>
#include "Lista.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
    TipoDado x;
    int opcao;
    int posicao;

    Lista_Construtor();

    do {
        system("cls");

        printf("Programa para uso da Lista Singularmente Encadeada\n\n");
        printf("Escolha uma das opcoes abaixo.");
        printf("\n\n\nMenu: \n");
        printf("\n1 - Inserir string");
        printf("\n2 - Remover no inicio");
        printf("\n3 - Remover no fim");
        printf("\n4 - Remover dado em uma posicao");
        printf("\n5 - Elemento no inicio");
        printf("\n6 - Elemento no fim");
        printf("\n7 - Procurar elemento");
        printf("\n8 - Numero de elementos na lista");
        printf("\n9 - Exibir elemento em uma posicao");
        printf("\n10 - Exibir elementos da Lista");
        printf("\n11 - Remover e exibir todos os elementos");
        printf("\n12 - Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &opcao);

        system("cls");

        switch (opcao) {
            case 1:
                printf("\n\nDigite a string: ");
                cin >> x;

                if (Lista_Inserir_Ordenado(x))
                    printf("String inserida\n\n");
                else
                    printf("Erro ao inserir string. Ou já existe ou falta de memória.\n\n");

                system("pause");
                break;

            case 2:
                if (Lista_Remover_Inicio(x)) {
                    printf("\n\nString '%s' removida\n\n", x);
                } else {
                    printf("Erro. Lista vazia.\n\n");
                }
                system("pause");
                break;

            case 3:
                if (Lista_Remover_Fim(x)) {
                    printf("\n\nString '%s' removida\n\n", x);
                } else {
                    printf("Erro. Lista vazia.\n\n");
                }
                system("pause");
                break;

            case 4:
                printf("Digite a posicao para remover o dado: ");
                scanf("%d", &posicao);

                if (Lista_Remover(x, posicao))
                    printf("\n\nString '%s' removida\n\n", x);
                else
                    printf("Erro. Posição não encontrada.\n\n");

                system("pause");
                break;

            case 5:
                printf("\nElemento no inicio da lista: ");
                if (Lista_Inicio(x))
                    printf("%s\n\n", x);
                else
                    printf("\n\nLista vazia\n\n");

                system("pause");
                break;

            case 6:
                printf("\nElemento no fim da lista: ");
                if (Lista_Fim(x))
                    printf("%s\n\n", x);
                else
                    printf("\n\nLista vazia\n\n");

                system("pause");
                break;

            case 7:
                printf("\nDigite a string para pesquisa: ");
                cin >> x;

                if (Lista_BuscarPeloElemento(x, posicao))
                    printf("String encontrada na posicao %d.\n\n", posicao);
                else
                    printf("Erro. String não encontrada.\n\n");

                system("pause");
                break;

            case 8:
                printf("\n\nNumero de elementos na lista: %d\n\n", Lista_Tamanho());
                system("pause");
                break;

            case 9:
                printf("\n\nEntre com a posicao desejada:\n\n");
                scanf("%d", &posicao);
                if (Lista_BuscarPelaPosicao(x, posicao)) {
                    printf("\nValor na posicao %d: %s", posicao, x);
                } else {
                    printf("Lista vazia ou posicao invalida");
                }

                printf("\n\n");
                system("pause");
                break;

            case 10:
                printf("\n\nElementos na Lista:\n\n");
                posicao = 0;
                while (Lista_BuscarPelaPosicao(x, posicao)) {
                    printf("\nValor na posicao %d: %s", posicao, x);
                    posicao++;
                }

                printf("\n\n");
                system("pause");
                break;

            case 11:
                printf("\nTodos os elementos: \n\n");

                while (Lista_Remover_Inicio(x)) {
                    printf("\nString: %s", x);
                }

                printf("\n\n");
                system("pause");
                break;

            case 12:
                Lista_Destrutor();
                break;

            default:
                printf("\n\nOpcao invalida\n\n");
                system("pause");
        }
    } while (opcao != 12);

    return 0;
}
