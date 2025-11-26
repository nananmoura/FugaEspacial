#include "tiro.h"
#include "screen.h"
#include "meteoro.h"
#include "nivel.h"
#include <stdio.h>
#include <stdlib.h>

void disparar_tiro(Tiro **lista, Nave *n, int nivel) {
    int num = get_num_tiros(nivel);

    for (int i = 0; i < num; i++) {
        int offset = get_tiro_offset(nivel, i);
        Tiro *novo = malloc(sizeof(Tiro));
        if (!novo) return; 

        novo->x = n->x + offset;
        novo->y = n->y - 1;
        novo->prox = *lista;
        *lista = novo;
    }
}

void atualizar_tiros(Tiro **lista) {
    Tiro *atual = *lista;
    Tiro *ant   = NULL;

    while (atual != NULL) {

        atual->y--; 

        if (atual->y <= 1) {

            if (ant == NULL)
                *lista = atual->prox;
            else
                ant->prox = atual->prox;

            free(atual);

            atual = (ant == NULL ? *lista : ant->prox);
            continue;
        }

        ant = atual;
        atual = atual->prox;
    }
}

void desenhar_tiros(Tiro *lista) {
    while (lista != NULL) {
        if (lista->y > 1 && lista->y < MAXY) {
            screenGotoxy(lista->x, lista->y);
            printf("*");
        }
        lista = lista->prox;
    }
}

int tiro_acertou_meteoro(Tiro *t, Meteoro *m) {

    int largura = (m->tamanho == 3 ? 5 :
                   m->tamanho == 2 ? 5 : 4);

    int altura = m->tamanho;

    int inicioX = m->x - largura / 2;

    if (inicioX < 1) inicioX = 1;
    if (inicioX > MAXX - largura) inicioX = MAXX - largura;

    for (int y = 0; y < altura; y++) {
        for (int x = 0; x < largura; x++) {

            if (t->x == inicioX + x &&
                t->y == m->y + y)
                return 1;
        }
    }

    return 0;
}
