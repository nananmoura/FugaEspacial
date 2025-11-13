#include "meteoro.h"
#include <stdio.h>
#include <stdlib.h>

void desenhar_meteoros(Meteoro *m) {
    for (Meteoro *aux = m; aux != NULL; aux = aux->prox) {
        const char **forma;
        int linhas = 0;

        switch (aux->tamanho) {
            case 3:
                forma = (const char*[]){" *** ", "*****", " *** "};
                linhas = 3;
                break;
            case 2:
                forma = (const char*[]){" *** ", " *** "};
                linhas = 2;
                break;
            default:
                forma = (const char*[]){" ** "};
                linhas = 1;
        }

        for (int i = 0; i < linhas; i++) {
            screenGotoxy(aux->x, aux->y + i);
            printf("%s", forma[i]);
        }
    }
}

void atualizar_meteoros(Meteoro **lista, Placar *p, Nave n) {
    Meteoro *atual = *lista;
    Meteoro *anterior = NULL;
    static int nivel_atual = 1;
    static int velocidade_atual = 100;

    while (atual != NULL) {
        if (atual->direcao == 0) atual->y++;
        else if (atual->direcao == 1) atual->x++;
        else if (atual->direcao == 2) atual->x--;
        else if (atual->direcao == 3) { 
            atual->x += (rand() % 3) - 1;
            atual->y++;
        }

        if (atual->y > MAXY - 1 || atual->x < 1 || atual->x > MAXX - 1) {
            p->pontos++;

            if (anterior == NULL) {
                *lista = atual->prox;
                free(atual);
                atual = *lista;
            } else {
                anterior->prox = atual->prox;
                free(atual);
                atual = anterior->prox;
            }
            continue;
        }

        anterior = atual;
        atual = atual->prox;
    }

    int pontos = p->pontos;
    int novo_nivel;

    if (pontos < 30)
        novo_nivel = pontos / 10 + 1;
    else if (pontos < 75)
        novo_nivel = 3 + ((pontos - 30) / 15) + 1; 
    else
        novo_nivel = 6 + ((pontos - 75) / 20) + 1;

    if (novo_nivel > nivel_atual) {
        nivel_atual = novo_nivel;

        int nova_velocidade = 100 - (nivel_atual - 1) * 10;
        if (nova_velocidade < 40) nova_velocidade = 40;

        velocidade_atual = nova_velocidade;
        timerInit(velocidade_atual);

        screenGotoxy(40, 1);
        printf("LEVEL UP - Nivel %d\a", nivel_atual);
    }

    screenGotoxy(60, 1);
    printf("Nivel: %d", nivel_atual);
}

void gerar_meteoro(Meteoro **lista, Placar *p, int nivel) {
    Meteoro *novo = malloc(sizeof(Meteoro));
    if (!novo) return;

    novo->tamanho = (rand() % 3) + 1;
    novo->vida = novo->tamanho;
    novo->direcao = (nivel < 6) ? (rand() % 3) : (rand() % 4);

    switch (novo->direcao) {
        case 0: novo->x = rand() % MAXX; novo->y = 1; break;
        case 1: novo->x = 1; novo->y = rand() % MAXY; break; 
        case 2: novo->x = MAXX - 5; novo->y = rand() % MAXY; break; 
        case 3: novo->x = rand() % MAXX; novo->y = rand() % 5; break; 
    }

    novo->prox = *lista;
    *lista = novo;
}

int verificar_colisao(Nave n, Meteoro *lista) {
    for (Meteoro *aux = lista; aux != NULL; aux = aux->prox) {
        int largura = (aux->tamanho == 3) ? 5 : (aux->tamanho == 2 ? 3 : 2);
        int altura = aux->tamanho;

        for (int i = 0; i < largura; i++) {
            for (int j = 0; j < altura; j++) {
                if ((n.x == aux->x + i) && (n.y == aux->y + j))
                    return 1;
            }
        }
    }
    return 0;
}

void liberar_meteoros(Meteoro *lista) {
    while (lista != NULL) {
        Meteoro *tmp = lista;
        lista = lista->prox;
        free(tmp);
    }
}
