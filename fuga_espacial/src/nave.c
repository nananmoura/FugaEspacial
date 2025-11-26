#include "nave.h"
#include "screen.h"
#include <stdio.h>

const char *NAVE_FORMA[NAVE_ALTURA] = {
    "    /\\    ",
    "  <====>   ",
    "    \\/    "
};

void inicializar_nave(Nave *n) {
    n->x = MAXX / 2;
    n->y = MAXY - NAVE_ALTURA - 1;
    n->tiros = NULL;
    n->vidas = 3;    
}

void desenhar_nave(Nave n) {
    for (int i = 0; i < NAVE_ALTURA; i++) {
        screenGotoxy(n.x - (NAVE_LARGURA / 2), n.y + i);
        printf("%s", NAVE_FORMA[i]);
    }
}

void mover_nave(Nave *n, char tecla) {
    if ((tecla == 'a' || tecla == 'A') && n->x > (NAVE_LARGURA / 2) + 1)
        n->x--;

    else if ((tecla == 'd' || tecla == 'D') && n->x < MAXX - (NAVE_LARGURA / 2) - 1)
        n->x++;

    else if ((tecla == 'w' || tecla == 'W') && n->y > 2)
        n->y--;

    else if ((tecla == 's' || tecla == 'S') && n->y < MAXY - NAVE_ALTURA - 1)
        n->y++;
}
