#include "meteoro.h"
#include "tiro.h"
#include "nave.h"
#include "screen.h"
#include <stdio.h>
#include <stdlib.h>

void desenhar_meteoros(Meteoro *m) {
    for (Meteoro *aux = m; aux != NULL; aux = aux->prox) {

        const char *forma[3];
        int linhas = aux->tamanho;

        if (aux->tamanho == 3) {
            forma[0] = " +++ ";
            forma[1] = "+++++";
            forma[2] = " +++ ";
        }
        else if (aux->tamanho == 2) {
            forma[0] = " +++ ";
            forma[1] = " +++ ";
        }
        else {
            forma[0] = " ++ ";
        }

        int largura = (aux->tamanho == 3 ? 5 :
                       aux->tamanho == 2 ? 5 : 4);

        int inicioX = aux->x - largura / 2;

        if (inicioX < 1) inicioX = 1;
        if (inicioX > MAXX - largura) inicioX = MAXX - largura;

        for (int i = 0; i < linhas; i++) {
            if (aux->y + i > 1 && aux->y + i < MAXY) {
                screenGotoxy(inicioX, aux->y + i);
                printf("%s", forma[i]);
            }
        }
    }
}


void atualizar_meteoros(Meteoro **lista, Placar *p, Nave *n) {
    Meteoro *atual = *lista;
    Meteoro *ant = NULL;

    while (atual != NULL) {

        int removido = 0;


        Tiro *t = n->tiros;
        Tiro *antT = NULL;

        while (t != NULL) {
            Tiro *nextT = t->prox;

            if (tiro_acertou_meteoro(t, atual)) {

                if (antT == NULL) n->tiros = nextT;
                else antT->prox = nextT;
                free(t);

                atual->vida--;

                if (atual->vida <= 0) {
                    p->pontos += 5;

                    if (ant == NULL)
                        *lista = atual->prox;
                    else
                        ant->prox = atual->prox;

                    free(atual);
                    atual = (ant == NULL ? *lista : ant->prox);
                    removido = 1;
                }
                else {
                    if (atual->tamanho > 1)
                        atual->tamanho--;
                }

                break;
            }

            antT = t;
            t = nextT;
        }

        if (removido) continue;

        if (atual->direcao == 0)
            atual->y++;          

        else if (atual->direcao == 1) {
            atual->x++;        
            atual->y++;          
        }

        else if (atual->direcao == 2) {
            atual->x--;          
            atual->y++;          
        }

        else {
            atual->y++;
            atual->x += (rand() % 3) - 1; 
        }

        if (atual->y >= MAXY - 1 ||
            atual->x <= 1 ||
            atual->x >= MAXX - 1) {

            p->pontos++;

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


void gerar_meteoro(Meteoro **lista, Placar *p, int nivel) {
    Meteoro *novo = malloc(sizeof(Meteoro));
    if (!novo) return;

    novo->tamanho = (rand() % 3) + 1;
    novo->vida = novo->tamanho;

    int origem = rand() % 100;

    if (nivel >= 6)
        origem = rand() % 4;

    if (origem < 60) {
        novo->direcao = 0;
        novo->x = 4 + rand() % (MAXX - 8);
        novo->y = 3;
    }
    else if (origem < 80) {
        novo->direcao = 1;
        novo->x = 2;
        novo->y = 3 + rand() % (MAXY - 6);
    }
    else {
        novo->direcao = 2;
        novo->x = MAXX - 3;
        novo->y = 3 + rand() % (MAXY - 6);
    }

    novo->prox = *lista;
    *lista = novo;
}


int verificar_colisao_nave_meteoro(Nave *n, Meteoro *lista) {

    for (Meteoro *m = lista; m != NULL; m = m->prox) {

        int largura_m = (m->tamanho == 3 ? 5 : (m->tamanho == 2 ? 5 : 4));
        int altura_m  = m->tamanho;
        int inicioX_m = m->x - largura_m / 2;
        if (inicioX_m < 1) inicioX_m = 1;
        if (inicioX_m > MAXX - largura_m) inicioX_m = MAXX - largura_m;

        for (int a = 0; a < NAVE_ALTURA; a++) {
            for (int b = 0; b < NAVE_LARGURA; b++) {
                char c = NAVE_FORMA[a][b];
                if (c == ' ') continue;  

                int xn = n->x - (NAVE_LARGURA / 2) + b;
                int yn = n->y + a;

                if (xn < 1 || xn >= MAXX || yn < 1 || yn >= MAXY)
                    continue;

                for (int i = 0; i < altura_m; i++) {
                    for (int j = 0; j < largura_m; j++) {
                        if (xn == inicioX_m + j && yn == m->y + i)
                            return 1;  
                    }
                }
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
