#include "placar.h"
#include "screen.h"
#include <stdio.h>
#include <stdlib.h>

void inicializar_placar(Placar *p) {
    p->pontos = 0;
    carregar_recorde(p);
}

void desenhar_placar(Placar p) {
    screenGotoxy(20, 2);
    printf("                ");

    screenGotoxy(20, 2);
    printf("PONTOS: %d", p.pontos);

    screenGotoxy(50, 2);
    printf("                ");

    screenGotoxy(50, 2);
    printf("RECORDE: %d", p.recorde);
}

void adicionar_pontos(Placar *p, int qtd) {
    p->pontos += qtd;
}

void salvar_recorde(Placar p) {
    FILE *f = fopen("recorde.txt","w");
    if (!f) return;
    fprintf(f, "%d", p.pontos);
    fclose(f);
}

void carregar_recorde(Placar *p) {
    FILE *f = fopen("recorde.txt","r");
    if (!f) {
        p->recorde = 0;
        return;
    }
    int v = 0;
    if (fscanf(f, "%d",&v) != 1) v = 0;
    p->recorde = v;
    fclose(f);
}

